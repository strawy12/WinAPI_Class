#pragma once
#include "Object.h"
class Monster : public Object
{
public:
	Monster();
	~Monster();

public:
	void Update() override;

public:
	float GetSpeed() { return _fSpeed; }
	void GetSpeed(float speed) {  _fSpeed = speed; }
	void SetCenterPos(Vec2 vPos) { _vCenterPos = vPos; }
	void SetMaxDis(float maxDis) { _fMaxDis = maxDis; }

private:
	float _fSpeed;
	Vec2 _vCenterPos;
	float _fMaxDis;
	int _iDir;

};

