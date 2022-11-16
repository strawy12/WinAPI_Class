#pragma once
#include "Object.h"

class Bullet : public Object
{
public:
	Bullet();
	~Bullet();

	virtual void Update() override;
	virtual void Render(HDC dc) override;

public:
	void SetDir(float theta)
	{
		_fTheta = theta;
	}

private:
	float _fTheta;
};

