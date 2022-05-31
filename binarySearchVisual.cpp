#include <algorithm>
#include <cstdio>
#include <ctime>
#include <vector>

#include "binarySearchVisual.hpp"
#include "functions.hpp"
#include "context.hpp"

const int UnitNumber = 20;

BinarySearchVisual::BinarySearchVisual(int number, Sprite box, Arrows& lowArrows, Arrows& highArrows, Arrows& midArrows):
	m_units(number),
	m_expected(0), m_finish(true), m_succeed(false),
	m_low(-1), m_high(-1), m_mid(-1),
	m_box(box),
	m_lowArrows(lowArrows), m_highArrow(highArrows), m_midArrows(midArrows) {}

void BinarySearchVisual::updatePointer()
{
	if (m_low <= m_high)
	{
		m_mid = (m_low + m_high) / 2;

		int value = m_units.at(m_mid);
		if (value < m_expected)
		{
			m_low = m_mid + 1;
		}
		else
		{
			m_high = m_mid - 1;
		}
	}
}

void BinarySearchVisual::update(float dt)
{
	// 以独立于帧率的形式进行二分查找
	static float count = 0;

	if (m_finish) count += dt;
	if (count >= BinarySearchVisual::Interval)
	{
		// 清空计时器
		count = 0;

		// 更新定位指针
		this->updatePointer();
	}

	
}

// 重置或是初始化单元组
// 单元组将递增排列
void BinarySearchVisual::regenerate(int max, int min) {
	// 设置随机数种子
	std::srand(std::time(0));

	// 生成所需要的随机数值
	for (int i = 0; i < m_units.size(); i++) {
		m_units[i] = Random(max, min);
	}

	// 对生成的随机数值排序
	std::sort(m_units.begin(), m_units.end());

	// 重置
	this->resetSearch();
}

// 开始查找期望值, 调用前需要先使用reset重置或是初始化数组单元
// 注意, 在查找期间调用此函数将导致查找在设置新的期望值后重新开始
void BinarySearchVisual::startSearch(int expected)
{
	m_low = 0;
	m_high = m_units.size() - 1;

	// 设置查找的目标值
	m_expected = expected;
	m_finish = false;
}

void BinarySearchVisual::resetSearch()
{
	// 重置搜索参数
	m_low = 0;
	m_high = m_units.size() - 1;

	m_expected = 0;
	m_finish = true;
}

// 可视化器使用独立的计时器使查找过程独立于帧率
void BinarySearchVisual::update(float dt)
{
	static float count = 0;

	// 查找过程
	if (m_finish) count += dt;
	if (count >= BinarySearchVisual::Interval)
	{
		// 清空计时器
		count = 0;

		// 单步运行二分查找算法
		// 更新定位点
		this->updatePointer();
	}

	// 按既定帧率进行绘制

	vec2i position{0,0};

	// 绘制所有的方框
	for (int i =0; i < m_units.size(); i++)
	{
		int value = m_units.at(i);
		
		SDL_Color color = {1,1,1,1};

		// 首定位点方框绘制为蓝色
		if (i == m_low)
			color = { 0, 1, 1, 1 };
		else if (i == m_high)
			color = { 1,0,0,1 };
		


	}
	
}
