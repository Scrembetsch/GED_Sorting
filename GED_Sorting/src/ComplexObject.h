#pragma once
#include <string>

#include "Random.h"

struct ComplexObject
{
	ComplexObject()
		: key(Random(0, INT32_MAX))
		, a(Random(0, INT32_MAX))
		, b(Random(0, INT32_MAX))
		, c(Random(0, INT32_MAX))
		, d(Random(0, INT32_MAX))
		, e(Random(0, INT32_MAX))
	{
	}

	~ComplexObject()
	{
	}

	std::string ToString() const
	{
		return std::to_string(key) + ": " + std::to_string(a) + "," + std::to_string(b) + "," + std::to_string(c) + "," + std::to_string(d) + "," + std::to_string(e);
	}

	size_t key;

	int a;
	int b;
	int c;
	int d;
	int e;

	operator size_t() const
	{
		return key;
	}
};

bool operator<(const ComplexObject& lhs, const ComplexObject& rhs)
{
	return lhs.key < rhs.key;
}

bool operator>(const ComplexObject& lhs, const ComplexObject& rhs)
{
	return rhs < lhs;
}

bool operator<=(const ComplexObject& lhs, const ComplexObject& rhs)
{
	return !(lhs > rhs);
}

bool operator>=(const ComplexObject& lhs, const ComplexObject& rhs)
{
	return !(lhs < rhs);
}

bool operator==(const ComplexObject& lhs, const ComplexObject& rhs)
{
	return lhs.key == rhs.key
		&& lhs.a == rhs.a
		&& lhs.b == rhs.b
		&& lhs.c == rhs.c
		&& lhs.d == rhs.d
		&& lhs.e == rhs.e;
}

bool operator!=(const ComplexObject& lhs, const ComplexObject& rhs)
{
	return !(lhs == rhs);
}