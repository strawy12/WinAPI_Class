#include "pch.h"
#include "Scene.h"
#include "Object.h"

Scene::Scene()
{
}

Scene::~Scene()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; i++)
	{
		for (UINT j = 0; j < _vecObj[i].size(); j++)
		{
			delete _vecObj[i][j];
		}
	}
}

void Scene::Update()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; i++)
	{
		for (UINT j = 0; j < _vecObj[i].size(); j++)
		{
			_vecObj[i][j]->Update();
		}
	}
}

void Scene::Render(HDC dc)
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; i++)
	{
		for (UINT j = 0; j < _vecObj[i].size(); j++)
		{
			_vecObj[i][j]->Render(dc);
		}
	}
}
