#pragma once
class Object
{

public:
	Object();
	virtual ~Object();

public:
	virtual void Update() = 0;
	virtual void Render(HDC dc);

public:
	void SetPos(Vec2 pos) { _vPos = pos; }
	void SetScale(Vec2 scale) { _vScale = scale; }

	const Vec2& GetPos() { return _vPos; }
	const Vec2& GetScale() { return _vScale; }

private:
	Vec2 _vPos;
	Vec2 _vScale;

};

