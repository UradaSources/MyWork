#ifndef HEAD_BINARY_SEARCH_VISUAL
#define HEAD_BINARY_SEARCH_VISUAL

#include <vector>

#include <SDL2/SDL.h>

#include "sprite.hpp"
#include "vec2.hpp"
#include "activeObject.hpp"
#include "arrows.hpp"

// 二分查找算法的可视化
class BinarySearchVisual: public ActiveObject
{
public:
	// 查找结果
	enum class SecrchResult
	{
		Finish,
		Progress,
		Success
	};

private:
	// 数值列表
	std::vector<int> m_units;

	// 查找前后两端的索引
	int m_low, m_high, m_mid;

	// 查找目标
	int m_expected;

	// 指示是否查找完毕
	bool m_finish, m_succeed;

	// 非帧同步的时间间隔
	const float Interval = 1.5f;

	// 单元精灵
	Sprite m_box;

	// 所要用到的箭头
	Arrows& m_lowArrows;
	Arrows& m_highArrow;
	
	Arrows& m_midArrows;

private:
	// 更新定位指针
	// 在搜索成功或失败时, 此函数不做任何事, 否则更新定位指针
	void updatePointer();

	// 将绘制特定的单元到屏幕上
	void drawUnit(int index, SDL_Color color);

public:
	// 绘制参数硬编码
	BinarySearchVisual(int number, Sprite box, Arrows& lowArrows, Arrows& highArrows, Arrows& midArrows);
	~BinarySearchVisual() = default;

	// 重新生成值组
	void regenerate(int max, int min);

	// 设定搜索参数并开始搜索
	void startSearch(int expected);

	// 复位
	void resetSearch();

	virtual void update(float dt);
};

#endif  // !HEAD_BINARY_SEARCH_VISUAL
