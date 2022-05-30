#ifndef HEAD_BINARY_SEARCH_VISUAL
#define HEAD_BINARY_SEARCH_VISUAL

#include <vector>

#include <SDL2/SDL.h>

#include "unit.hpp"
#include "sprite.hpp"
#include "vector2.hpp"

// ���ֲ����㷨�Ŀ��ӻ�
class BinarySearchVisual
{
private:
	// ��Ԫ�б�
	std::vector<Unit*> m_units;

	// ����ǰ�����˵�����
	int m_first, m_last;

	// ����Ŀ��
	int m_expected;
	// ָʾ�Ƿ�������
	bool m_finish;

	// ��֡ͬ����ʱ����
	const float Interval = 0.5f;
	float m_count;

	// ���ӻ�����
	int m_viewportWidth;
	vector2i m_unitSpacing;

	// ���Ƶ�Ԫ��Ҫ�õľ���
	Sprite& m_unitSprite;

public:
	BinarySearchVisual(int viewportWidth, vector2i unitSpacing, Sprite& unitSprite);
	~BinarySearchVisual();

	BinarySearchVisual(const BinarySearchVisual&) = delete;
	BinarySearchVisual& operator=(const BinarySearchVisual&) = delete;

	// �趨������������ʼ����
	void startSearch(int expected);

	// ��ʼ����λ��
	void initUnits(int unitNumber, int max, int min);
	void freeUnits();

	// ���ֲ��ҵ���
	int binarySearchStep(bool& ref_succeed);

	virtual void update(float dt);

	Sprite& getUnitSprite() { return m_unitSprite; }
};

#endif  // !HEAD_BINARY_SEARCH_VISUAL
