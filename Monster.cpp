#include "pch.h"
#include "Monster.h"
#include "TimeManager.h"                                      

Monster::Monster()
	: _fSpeed(100.f)
	, _vCenterPos(Vec2(0.1f, 0.1f))
	, _fMaxDis(50.f)
	, _iDir(1)
{
}

Monster::~Monster()
{
}

void Monster::Update()
{
	Vec2 vCurPos = GetPos();
	vCurPos.x += _fSpeed * _iDir * FDT;

	// 
	float fDist = abs(_vCenterPos.x - vCurPos.x) - _fMaxDis;
	if (fDist > 0.f)
	{
		_iDir *= -1;
		vCurPos.x += fDist * _iDir;
	}

	SetPos(vCurPos);
}

