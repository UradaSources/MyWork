#include <algorithm>
#include <cstdio>
#include <ctime>
#include <vector>

#include "binarySearchVisual.hpp"
#include "functions.hpp"

BinarySearchVisual::BinarySearchVisual(int viewportWidth, vector2i unitSpacing, Sprite& unitSprite) :
	m_viewportWidth(viewportWidth),
	m_unitSpacing(unitSpacing),
	m_unitSprite(unitSprite),
	m_first(0),
	m_last(0),
	m_expected(-1),
	m_finish(false),
	m_count(0) {}
BinarySearchVisual::~BinarySearchVisual() {
	this->freeUnits();
}

void BinarySearchVisual::startSearch(int expected) {
	// ���ò��ҵ�Ŀ��ֵ
	m_expected = expected;
	// ֹͣ���ұ�־
	m_finish = false;

	// ��ʼ�����ҵ�λ��
	m_first = 0;
	m_last = m_units.size() - 1;
}

void BinarySearchVisual::initUnits(int unitNumber, int max, int min) {
	// �ͷŵ�Ԫ������б�
	this->freeUnits();

	// �������������
	std::srand(std::time(0));

	// ����ռ�
	m_units.reserve(unitNumber);

	// ��������Ҫ�������ֵ
	std::vector<int> randomValues;
	randomValues.reserve(unitNumber);

	for (int i = 0; i < unitNumber; i++) {
		randomValues.at(i) = Random(max, min);
	}

	// �����ɵ������ֵ����
	std::sort(randomValues.begin(), randomValues.end());

	// ���浥Ԫ��λ��
	vector2i position = { 0, 0 };

	// ��ʼ����Ԫ
	for (int i = 0; i < unitNumber; i++) {
		// ���ø�ʽ

		// ����ʽ�ļ��㵥Ԫ��λ��
		int x = position.x + m_unitSprite.getSize().x + m_unitSpacing.x;
		if (x > m_viewportWidth)
		{
			x = 0;
			position.y += m_unitSprite.getSize().y + m_unitSpacing.y;
		}

		position.x = x;

		// �͵ع��쵥Ԫ����ֵ
		m_units.emplace_back(new Unit(*this, position));
		m_units.back()->init(i, randomValues.at(i));
	}

#ifdef DEBUG

	for (int i = 0; i < m_units.size(); i++) {
		auto gm = m_units.at(i);
		std::printf("[%d](%d), ", gm->m_index, gm->m_value);
	}
	std::printf("\n");

#endif  // DEBUG
}
void BinarySearchVisual::freeUnits() {
	for (auto i : m_units)
		delete i;
	m_units.clear();
}

// ���ֲ��ҵ���
int BinarySearchVisual::binarySearchStep(bool& ref_succeed) {
	if (m_first <= m_last) {
		int mid = (m_first + m_last) / 2;

		int value = m_units.at(mid)->getValue();
		if (value == m_expected) {
			ref_succeed = true;
			return mid;
		}
		else if (value < m_expected) {
			m_first = mid + 1;
		}
		else {
			m_last = mid - 1;
		}

		ref_succeed = false;
		return mid;
	}

	ref_succeed = false;
	return -1;
}

void BinarySearchVisual::update(float dt) {
	if (m_finish)
		return;

	// �ۼӼ�ʱ��
	m_count += dt;
	if (m_count >= BinarySearchVisual::Interval) {
		// ��ռ�ʱ��
		m_count = 0;

		std::printf("����������, begin(%d), end(%d)\n", m_first, m_last);

		// �������ж��ֲ����㷨
		bool succeed = false;
		int newMid = this->binarySearchStep(succeed);

		// ���ҳɹ�
		if (succeed) {
			std::printf("���ҳɹ�, ��%d\n", newMid);
			m_finish = true;
		}
		else if (newMid < 0)  // ����ʧ��
		{
			std::printf("����ʧ��, ͣ����%d\n", newMid);
			m_finish = true;
		}
		else {
			// ���õ�Ԫ״̬
			std::printf("��������, ͣ����%d\n", newMid);
			return;
		}
	}
}
