#include "pch.h"
#include "Object.h"
#include "KeyManager.h"
#include "TimeManager.h"

Object::Object()
	: _vPos{}
	, _vScale{}
{
}

Object::~Object()
{
}

void Object::Render(HDC dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	Rectangle(dc
		, (int)(vPos.x - (vScale.x / 2))
		, (int)(vPos.y - (vScale.y / 2))
		, (int)(vPos.x + (vScale.x / 2))
		, (int)(vPos.y + (vScale.y / 2))
	);
}


