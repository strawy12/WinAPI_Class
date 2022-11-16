#pragma once

class Object;

class Scene
{
public:
	Scene();
	virtual ~Scene();

public:
	virtual void Enter() = 0;
	virtual void Exit() = 0;

public:
	void Update();
	void Render(HDC dc);

public:
	void AddObject(Object* pObj, GROUP_TYPE type)
	{
		_vecObj[(UINT)type].push_back(pObj);
	}

public:
	void SetName(const wstring& strName) { _strName = strName; }
	const wstring& GetName() { return _strName; }

protected:
	vector<Object*> _vecObj[(UINT)GROUP_TYPE::END];
	wstring _strName;
};

