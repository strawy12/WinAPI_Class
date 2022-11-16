#include "pch.h"
#include "Bullet.h"
#include "TimeManager.h"

Bullet::Bullet()
	:_fTheta(0.f)
{
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	Vec2 vPos = GetPos();

	//vPos.y += 500.f * _fDir * FDT;
	SetPos(vPos);
}

void Bullet::Render(HDC dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	Ellipse(dc
		, (int)(vPos.x - (vScale.x / 2))
		, (int)(vPos.y - (vScale.y / 2))
		, (int)(vPos.x + (vScale.x / 2))
		, (int)(vPos.y + (vScale.y / 2))
	);
}
