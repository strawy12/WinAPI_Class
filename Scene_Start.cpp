#include "pch.h"
#include "Scene_Start.h"
#include "Player.h"
#include "Monster.h"
#include "Core.h"

Scene_Start::Scene_Start()
{

}

Scene_Start::~Scene_Start() 
{

}

void Scene_Start::Enter()
{
	Object* pObj = new Player;
	pObj->SetPos(Vec2(640.f, 360.f));
	pObj->SetScale(Vec2(100,100));

	AddObject(pObj, GROUP_TYPE::DEFAULT);

	Vec2 vResolution = Core::GetInst()->GetResolution();

	Monster* pMonsterObj = nullptr;
	int iMonster = 16;
	float iMoveDist = 50.f;
	float fObjScale = 50.f;
	float selling = iMoveDist + (fObjScale / 2.f);
	float fTerm = (vResolution.x - (selling * 2)) / (float)(iMonster - 1);

	for (int i = 0; i < iMonster; i++)
	{
		pMonsterObj = new Monster;
		pMonsterObj->SetPos(Vec2(selling + (float)i*fTerm, 50.f));
		pMonsterObj->SetScale(Vec2(fObjScale, fObjScale));
		pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
		AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
	}
	
}

void Scene_Start::Exit()
{
}
