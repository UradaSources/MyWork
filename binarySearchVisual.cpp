#include <algorithm>
#include <cstdio>
#include <ctime>
#include <vector>

#include "binarySearchVisual.hpp"
#include "functions.hpp"

const int UnitNumber = 20;

BinarySearchVisual::BinarySearchVisual(int max, int min) :
	m_units(20),
	m_expected(0),
	m_finish(true),
	m_count(0)
{
	// 重置单元值组与搜索参数
	this->reset(max, min);
}

// 单步的进行二分查找
int BinarySearchVisual::binarySearchStep(bool& ref_succeed)
{
	if (m_low <= m_high)
	{
		int mid = (m_low + m_high) / 2;

		int value = m_units.at(mid);
		if (value == m_expected)
		{
			ref_succeed = true;
			return mid;
		}
		else if (value < m_expected)
		{
			m_low = mid + 1;
		}
		else
		{
			m_high = mid - 1;
		}

		ref_succeed = false;
		return mid;
	}

	ref_succeed = false;
	return -1;
}

// 重置或是初始化单元组
// 单元组将递增排列
void BinarySearchVisual::reset(int max, int min) {
	// 设置随机数种子
	std::srand(std::time(0));

	// 生成所需要的随机数值
	for (int i = 0; i < m_units.size(); i++) {
		m_units[i] = Random(max, min);
	}

	// 对生成的随机数值排序
	std::sort(m_units.begin(), m_units.end());

	// 重置搜索参数
	m_low = 0;
	m_high = m_units.size() - 1;

	m_expected = 0;
	m_finish = true;
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

// 可视化器使用独立的计时器使查找过程独立于帧率
void BinarySearchVisual::update(float dt)
{
	// 查找过程
	if (m_finish) m_count += dt;
	if (m_count >= BinarySearchVisual::Interval)
	{
		// 清空计时器
		m_count = 0;

		std::printf("持续查找中, begin(%d), end(%d)\n", m_low, m_high);

		// 单步运行二分查找算法
		bool succeed = false;
		int mid = this->binarySearchStep(succeed);

		// 查找成功
		if (succeed) {
			std::printf("查找成功, 在%d\n", mid);
			m_finish = true;
		}
		else if (mid < 0)  // 查找失败
		{
			std::printf("查找失败, 停留在%d\n", mid);
			m_finish = true;
		}
		else {
			// 设置单元状态
			std::printf("持续查找, 停留在%d\n", mid);
			return;
		}
	}

	// 绘制查找结果

}
