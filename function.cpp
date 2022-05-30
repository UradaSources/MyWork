#include <algorithm>
#include <cstdio>
#include <cstdlib>

#include "functions.hpp"

const char* _GenerateInfo(int lineNumber, const char* content, const char* fileName)
{
	const int size = 128;
	static char cache[size];

	// 每次使用前清空缓冲区
	std::fill(cache, cache + size, 0);

	// 写入错误信息并返回
	std::snprintf(cache, sizeof(cache), "%s, on line %d of %s\n", content, lineNumber, fileName);
	return cache;
}

int Random(int max, int min)
{
	return min + std::rand() / (RAND_MAX / (max - min + 1) + 1);
}