#include "pch.h"
#include "SceneManager.h"
#include "Scene_Start.h"

SceneManager::SceneManager()
	: _arrScene{}
	, _pCurScene(nullptr)
{
}

SceneManager::~SceneManager()
{
	// �� ����
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; i++)
	{
		if (!_arrScene[i])
		{
			delete _arrScene[i];
		}
	}
}

void SceneManager::Init()
{
	//Scene ����
	_arrScene[(UINT)SCENE_TYPE::START] = new Scene_Start;
	_arrScene[(UINT)SCENE_TYPE::START]->SetName(L"StartScene");

	// ���� �� ����'
	_pCurScene = _arrScene[(UINT)SCENE_TYPE::START];
	_pCurScene->Enter();
}

void SceneManager::Update()
{
	_pCurScene->Update();
}

void SceneManager::Render(HDC dc)
{
	_pCurScene->Render(dc);

}
