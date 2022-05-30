#ifndef HEAD_BINARY_SEARCH_VISUAL
#define HEAD_BINARY_SEARCH_VISUAL

#include <vector>

#include <SDL2/SDL.h>

#include "unit.hpp"
#include "sprite.hpp"
#include "vector2.hpp"

// 二分查找算法的可视化
class BinarySearchVisual
{
private:
	// 单元列表
	std::vector<Unit*> m_units;

	// 查找前后两端的索引
	int m_first, m_last;

	// 查找目标
	int m_expected;
	// 指示是否查找完毕
	bool m_finish;

	// 非帧同步的时间间隔
	const float Interval = 0.5f;
	float m_count;

	// 可视化参数
	int m_viewportWidth;
	vector2i m_unitSpacing;

	// 绘制单元所要用的精灵
	Sprite& m_unitSprite;

public:
	BinarySearchVisual(int viewportWidth, vector2i unitSpacing, Sprite& unitSprite);
	~BinarySearchVisual();

	BinarySearchVisual(const BinarySearchVisual&) = delete;
	BinarySearchVisual& operator=(const BinarySearchVisual&) = delete;

	// 设定搜索参数并开始搜索
	void startSearch(int expected);

	// 初始化单位组
	void initUnits(int unitNumber, int max, int min);
	void freeUnits();

	// 二分查找单步
	int binarySearchStep(bool& ref_succeed);

	virtual void update(float dt);

	Sprite& getUnitSprite() { return m_unitSprite; }
};

#endif  // !HEAD_BINARY_SEARCH_VISUAL
