#include "pch.h"
#include "Vec2.h"

Vec2::Vec2()
{
	x = 0;
	y = 0;
}

Vec2::Vec2(int x, int y)
	: x((float)x)
	, y((float)y)
{
}

Vec2::Vec2(long x, long y)
	: x((float)x)
	, y((float)y)
{
}

Vec2::Vec2(float x, float y)
	: x(x)
	, y(y)
{
}

Vec2::Vec2(const POINT pt)  
	: x(float(pt.x))
	, y(float(pt.y))
{
	
}


Vec2::~Vec2()
{
}
