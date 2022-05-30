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
	// 设置查找的目标值
	m_expected = expected;
	// 停止查找标志
	m_finish = false;

	// 初始化查找的位置
	m_first = 0;
	m_last = m_units.size() - 1;
}

void BinarySearchVisual::initUnits(int unitNumber, int max, int min) {
	// 释放单元并清空列表
	this->freeUnits();

	// 设置随机数种子
	std::srand(std::time(0));

	// 分配空间
	m_units.reserve(unitNumber);

	// 生成所需要的随机数值
	std::vector<int> randomValues;
	randomValues.reserve(unitNumber);

	for (int i = 0; i < unitNumber; i++) {
		randomValues.at(i) = Random(max, min);
	}

	// 对生成的随机数值排序
	std::sort(randomValues.begin(), randomValues.end());

	// 储存单元的位置
	vector2i position = { 0, 0 };

	// 初始化单元
	for (int i = 0; i < unitNumber; i++) {
		// 设置格式

		// 渐进式的计算单元的位置
		int x = position.x + m_unitSprite.getSize().x + m_unitSpacing.x;
		if (x > m_viewportWidth)
		{
			x = 0;
			position.y += m_unitSprite.getSize().y + m_unitSpacing.y;
		}

		position.x = x;

		// 就地构造单元并赋值
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

// 二分查找单步
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

	// 累加计时器
	m_count += dt;
	if (m_count >= BinarySearchVisual::Interval) {
		// 清空计时器
		m_count = 0;

		std::printf("持续查找中, begin(%d), end(%d)\n", m_first, m_last);

		// 单步运行二分查找算法
		bool succeed = false;
		int newMid = this->binarySearchStep(succeed);

		// 查找成功
		if (succeed) {
			std::printf("查找成功, 在%d\n", newMid);
			m_finish = true;
		}
		else if (newMid < 0)  // 查找失败
		{
			std::printf("查找失败, 停留在%d\n", newMid);
			m_finish = true;
		}
		else {
			// 设置单元状态
			std::printf("持续查找, 停留在%d\n", newMid);
			return;
		}
	}
}
