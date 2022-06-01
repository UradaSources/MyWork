#ifndef HEAD_BINARY_SEARCH_VISUAL
#define HEAD_BINARY_SEARCH_VISUAL

#include <vector>

#include <SDL.h>

#include "sprite.hpp"
#include "vec2.hpp"
#include "activeObject.hpp"
#include "arrows.hpp"

// 诸指示器对象
class PointerView : public ActiveObject
{
public:
	static PointerView& GetInstance()
	{
		static PointerView _instance;
		return _instance;
	}

private:
	Sprite m_arrows;

	int m_low, m_high, m_mid;

	bool _m_inited = false;

public:
	PointerView() :
		m_arrows(Context::GetInstance().loadTextureFromFile("")) {}
	~PointerView() = default;

	// 同步数据
	void syncData(int low, int high, int mid)
	{
		m_low = low;
		m_high = high;

		m_mid = mid;
	}

	// 重置指针
	void resetPointer()
	{
		m_low = 0;
		m_high = BackgroundView::GetInstance().getValueNumber() - 1;


	}

	virtual void start() {}
	virtual void update(float dt)
	{
		BackgroundView& background = BackgroundView::GetInstance();

		// 计算绘制位置
		vec2i lowPos = background.queryBoxLocalPosition(m_low);

	}
};

// 方块和背景对象
// view 从visual类中获取需要的数据然后进行绘制
class BackgroundView: public ActiveObject
{
public:
	static BackgroundView& GetInstance()
	{
		static BackgroundView _instance;
		return _instance;
	}

private:
	// 绘制方框所用的精灵
	Sprite m_box;

	// 排序后的值组
	std::vector<int> m_values;

	// 查询的目标值
	int m_target;

	bool _m_inited = false;

public:
	// 染色方案
	std::vector<SDL_Color> colorScheme;

	// 整体绘制位置
	vec2i position;

	BackgroundView() :
		m_box(Context::GetInstance().loadTextureFromFile("")),
		position({0,0}) {}
	~BackgroundView() = default;

	int getValue(int index)const { return m_values.at(index); }

	// 重新生成值组并设定查询的目标值
	void regenerate(int number, int min, int max, int target)
	{
		_m_inited = true;

		// 修改值组的尺寸
		m_values.resize(number);
		colorScheme.resize(number);

		// 重置染色
		std::fill(colorScheme.begin(), colorScheme.end(), SDL_Color{ 1,1,1,1 });

		// 重新生成值组
		for (int i = 0; i < m_values.size(); i++)
		{
			m_values[i] = Random(max, min);
		}

		// 对生成的值组进行排序
		std::sort(m_values.begin(), m_values.end());

		// 设置查找的目标值
		m_target = target;
	}

	int getValueNumber()const { return m_values.size(); }

	// 查询特定方框的定位点
	vec2i queryBoxLocalPosition(int index)
	{
		vec2i local = { 0,0 };
		local.x = index * m_box.getSize().x;
	}

	virtual void start() 
	{
		if (!_m_inited) throw std::runtime_error("必须先调用regenerate完成初始化");
	}
	virtual void update(float dt)
	{
		Context& context = Context::GetInstance();

		for (int i = 0; i < m_values.size(); i++)
		{
			int v = m_values[i];

			// 计算方框的绘制位置
			vec2i locationPoint = this->queryBoxLocalPosition(i);
			locationPoint = locationPoint + position;

			// 绘制方框
			context.setDrawColor(colorScheme[i]);
			context.draw(m_box, locationPoint);

			// 绘制文本
			vec2i indexPos = locationPoint;
			indexPos.y += (m_box.getSize() / 2).y + 12;

			context.setDrawColor(0, 0, 0, 1);
			context.drawNumberText(i, indexPos);
			context.drawNumberText(v, locationPoint);
		}
	}
};

// 二分查找算法的可视化

// 这些low high应该都有visual保存, 

class BinarySearchVisualModel: public ActiveObject
{
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

public:
	// 所要用到的箭头
	Arrows* lowArrows;
	Arrows* highArrow;
	
	Arrows* midArrows;

private:
	// 更新定位指针
	// 在搜索成功或失败时, 此函数不做任何事, 否则更新定位指针
	void updatePointerView();

public:
	// 绘制参数硬编码
	BinarySearchVisualModel(int number, Sprite box);
	~BinarySearchVisualModel() = default;

	// 重新生成值组
	void regenerate(int max, int min);

	// 设定搜索参数并开始搜索
	void startSearch(int expected);

	// 查询特定方块的位置
	void queryPosition(int index)
	{
		
	}

	// 复位
	void resetSearch();

	virtual void update(float dt);
};

#endif  // !HEAD_BINARY_SEARCH_VISUAL
