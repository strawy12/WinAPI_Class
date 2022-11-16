#include "pch.h"
#include "TimeManager.h"
#include "Core.h"

TimeManager::TimeManager()
	: _curCount()
	, _frequency()
	, _prevCount()
	, _dt(0)
	, _callCount(0)
	, _fps(0)
	, _acc(0)

{
}

TimeManager::~TimeManager()
{
}

void TimeManager::Init()
{
	//cpu 틱 세는거
	QueryPerformanceCounter(&_curCount);
	//초당 카운트 횟수 반환
	QueryPerformanceFrequency(&_frequency);
}

void TimeManager::Update()
{
	QueryPerformanceCounter(&_curCount);
	// 현재 프레임과 이전 프레인 카운팅 값의 차이를 구한다
	_dt= (double)(_curCount.QuadPart - _prevCount.QuadPart) / (double)_frequency.QuadPart;
	_prevCount = _curCount;
	++_callCount;
	_acc += _dt;

	if (_acc >= 1.0)
	{
		_fps = _callCount;
		_acc = 0;
		_callCount = 0;

		static wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS: %d, DT: %lf", _fps, _dt);
		SetWindowText(Core::GetInst()->GetWndHandle(), szBuffer);
	}

}
