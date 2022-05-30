#ifndef HEAD_VECTOR
#define HEAD_VECTOR

#include <cmath>
#include <limits>

template <typename T> struct basic_vec2
{
public:
	static basic_vec2 Normalized(const basic_vec2& v)
	{
		T length = v.length();
		T x = v.x != 0 ? v.x / length : 0;
		T y = v.y != 0 ? v.y / length : 0;
		return basic_vec2(x, y);
	}
	static basic_vec2 Lerp(const basic_vec2& from, const basic_vec2& to, T t)
	{
		return from + (to - from) * t;
	}

	T x, y;

	T length() const
	{
		return std::sqrt(x * x + y * y);
	}
};

template <typename T> basic_vec2<T> operator+(basic_vec2<T> left, basic_vec2<T> right)
{
	return basic_vec2<T>(left.x + right.x, left.y + right.y);
}
template <typename T> basic_vec2<T> operator-(basic_vec2<T> left, basic_vec2<T> right)
{
	return basic_vec2<T>(left.x - right.x, left.y - right.y);
}
template <typename T> basic_vec2<T> operator*(basic_vec2<T> left, basic_vec2<T> right)
{
	return basic_vec2<T>(left.x * right.x, left.y * right.y);
}
template <typename T> basic_vec2<T> operator/(basic_vec2<T> left, basic_vec2<T> right)
{
	return basic_vec2<T>(left.x / right.x, left.y / right.y);
}

template <typename T> basic_vec2<T> operator+(basic_vec2<T> left, T right)
{
	return basic_vec2<T>(left.x + right, left.y + right);
}
template <typename T> basic_vec2<T> operator-(basic_vec2<T> left, T right)
{
	return basic_vec2<T>(left.x - right, left.y - right);
}
template <typename T> basic_vec2<T> operator*(basic_vec2<T> left, T right)
{
	return basic_vec2<T>(left.x * right, left.y * right);
}
template <typename T> basic_vec2<T> operator/(basic_vec2<T> left, T right)
{
	return basic_vec2<T>(left.x / right, left.y / right);
}

template <typename T> bool operator==(basic_vec2<T> left, basic_vec2<T> right)
{
	return left.x == right.x && left.y == right.y;
}
template <typename T> bool operator!=(basic_vec2<T> left, basic_vec2<T> right)
{
	return left.x != right.x || left.y != right.y;
}

using vec2 = basic_vec2<float>;
using vec2i = basic_vec2<int>;

#endif // HEAD_VECTOR
