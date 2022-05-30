#ifndef HEAD_VECTOR
#define HEAD_VECTOR

#include <cmath>
#include <limits>

template <typename T> struct basic_vector2
{
public:
	static basic_vector2 Normalized(const basic_vector2& v)
	{
		T length = v.length();
		T x = v.x != 0 ? v.x / length : 0;
		T y = v.y != 0 ? v.y / length : 0;
		return basic_vector2(x, y);
	}
	static basic_vector2 Lerp(const basic_vector2& from, const basic_vector2& to, T t)
	{
		return from + (to - from) * t;
	}

	T x, y;

	T length() const
	{
		return std::sqrt(x * x + y * y);
	}
};

template <typename T> basic_vector2<T> operator+(basic_vector2<T> left, basic_vector2<T> right)
{
	return basic_vector2<T>(left.x + right.x, left.y + right.y);
}
template <typename T> basic_vector2<T> operator-(basic_vector2<T> left, basic_vector2<T> right)
{
	return basic_vector2<T>(left.x - right.x, left.y - right.y);
}
template <typename T> basic_vector2<T> operator*(basic_vector2<T> left, basic_vector2<T> right)
{
	return basic_vector2<T>(left.x * right.x, left.y * right.y);
}
template <typename T> basic_vector2<T> operator/(basic_vector2<T> left, basic_vector2<T> right)
{
	return basic_vector2<T>(left.x / right.x, left.y / right.y);
}

template <typename T> basic_vector2<T> operator+(basic_vector2<T> left, T right)
{
	return basic_vector2<T>(left.x + right, left.y + right);
}
template <typename T> basic_vector2<T> operator-(basic_vector2<T> left, T right)
{
	return basic_vector2<T>(left.x - right, left.y - right);
}
template <typename T> basic_vector2<T> operator*(basic_vector2<T> left, T right)
{
	return basic_vector2<T>(left.x * right, left.y * right);
}
template <typename T> basic_vector2<T> operator/(basic_vector2<T> left, T right)
{
	return basic_vector2<T>(left.x / right, left.y / right);
}

template <typename T> bool operator==(basic_vector2<T> left, basic_vector2<T> right)
{
	return left.x == right.x && left.y == right.y;
}
template <typename T> bool operator!=(basic_vector2<T> left, basic_vector2<T> right)
{
	return left.x != right.x || left.y != right.y;
}

using vector2 = basic_vector2<float>;
using vector2i = basic_vector2<int>;

#endif // HEAD_VECTOR
