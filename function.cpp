#include <algorithm>
#include <cstdio>
#include <cstdlib>

#include "functions.hpp"

const char* _GenerateInfo(int lineNumber, const char* content, const char* fileName)
{
	const int size = 128;
	static char cache[size];

	// ÿ��ʹ��ǰ��ջ�����
	std::fill(cache, cache + size, 0);

	// д�������Ϣ������
	std::snprintf(cache, sizeof(cache), "%s, on line %d of %s\n", content, lineNumber, fileName);
	return cache;
}

int Random(int max, int min)
{
	return min + std::rand() / (RAND_MAX / (max - min + 1) + 1);
}