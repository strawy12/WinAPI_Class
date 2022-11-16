#pragma once
class Vec2
{
public:
	float x;
	float y;

public:
	Vec2();
	Vec2(int x, int y);
	Vec2(long x, long y);
	Vec2(float x, float y);
	Vec2(const POINT pt);
	~Vec2();

};

