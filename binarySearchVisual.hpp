#ifndef HEAD_BINARY_SEARCH_VISUAL
#define HEAD_BINARY_SEARCH_VISUAL

#include <vector>

#include <SDL2/SDL.h>

// #include "unit.hpp"
#include "sprite.hpp"
#include "vec2.hpp"

// 二分查找算法的可视化
class BinarySearchVisual
{
private:
	// 数值列表
	std::vector<int> m_units;

	// 查找前后两端的索引
	int m_low, m_high;

	// 查找目标
	int m_expected;
	// 指示是否查找完毕
	bool m_finish;

	// 非帧同步的时间间隔
	const float Interval = 0.5f;
	float m_count;

	// 单元和箭头精灵
	//Sprite m_unitSprite;
	//Sprite m_upArrowSprite, downArrowSprite;

private:
	// 二分查找单步
	int binarySearchStep(bool& ref_succeed);

	// 将绘制特定的单元到屏幕上
	// void drawUnit(int index, SDL_Color color);

public:
	// 绘制参数硬编码
	BinarySearchVisual(int max, int min);
	~BinarySearchVisual() = default;

	BinarySearchVisual(const BinarySearchVisual&) = delete;
	BinarySearchVisual& operator=(const BinarySearchVisual&) = delete;

	// 重置单位组
	void reset(int max, int min);

	// 设定搜索参数并开始搜索
	void startSearch(int expected);

	virtual void update(float dt);
};

#endif  // !HEAD_BINARY_SEARCH_VISUAL
