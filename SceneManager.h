#pragma once

class Scene;

class SceneManager
{
public:
	SINGLE(SceneManager);

private:
	SceneManager();
	~SceneManager();

public:
	void Init();
	void Update();
	void Render(HDC dc);

public:
	Scene* GetCurScene() { return _pCurScene; }

private:
	Scene* _arrScene[(UINT)SCENE_TYPE::END];
	Scene* _pCurScene;
};

