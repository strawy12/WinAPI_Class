#include "pch.h"
#include "Player.h"
#include "KeyManager.h"
#include "TimeManager.h"
#include "Bullet.h"
#include "SceneManager.h"
#include "Scene.h"


void Player::Update()
{
	Vec2 vPos = GetPos();
	if (KEY_HOLD(KEY::LEFT))
	{
		vPos.x -= 300.f * FDT;
	}

	if (KEY_HOLD(KEY::RIGHT))
	{
		vPos.x += 300.f * FDT;
	}

	if (KEY_HOLD(KEY::UP))
	{
		vPos.y -= 300.f * FDT;
	}

	if (KEY_HOLD(KEY::DOWN))
	{
		vPos.y += 300.f * FDT;
	}

	if (KEY_TAP(KEY::SPACE))
	{
		CreateBullet();
	}

	SetPos(vPos);
}

void Player::CreateBullet()
{
	Vec2 bulletPos = GetPos();
	bulletPos.y -= GetScale().y / 2.f;

	Bullet* pBullet = new Bullet;
	pBullet->SetPos(bulletPos);
	pBullet->SetScale(Vec2(25.f,25.f));
	pBullet->SetDir(true);

	Scene* curScene = SceneManager::GetInst()->GetCurScene();
	curScene->AddObject(pBullet, GROUP_TYPE::BULLET);
}