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

	// �����Ӱ��� �ð� ��
	double	_dt;
	double	_acc;
	UINT _callCount;
	UINT _fps;
};

