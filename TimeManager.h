#pragma once
class TimeManager
{
public:
	SINGLE(TimeManager);

private:
	TimeManager();
	~TimeManager();

public:
	void Init();
	void Update();

public:
	const double GetDT() { return _dt; }
	const float GetfDT() { return (float)_dt; }

private:
	LARGE_INTEGER _curCount;
	LARGE_INTEGER _prevCount;
	LARGE_INTEGER _frequency;

	// 프레임간의 시간 값
	double	_dt;
	double	_acc;
	UINT _callCount;
	UINT _fps;
};

