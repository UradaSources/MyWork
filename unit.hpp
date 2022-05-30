#ifndef HEAD_UNIT
#define HEAD_UNIT

#include <SDL2/SDL.h>

#include "activeObject.hpp"
#include "vector2.hpp"
#include "context.hpp"

class BinarySearchVisual;

class Unit : public ActiveObject
{
private:
	BinarySearchVisual& m_visual;

	int m_index;
	int m_value;

	vector2i m_position;

public:
	Unit(BinarySearchVisual& visual, vector2i position);
	~Unit() = default;

	void init(int index, int value);
	void reset(int value);

	int getValue()const { return m_value; }

	virtual void start();
	virtual void update(float dt);
};

#endif  // !HEAD_UNIT
