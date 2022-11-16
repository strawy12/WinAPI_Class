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
	//cpu ƽ ���°�
	QueryPerformanceCounter(&_curCount);
	//�ʴ� ī��Ʈ Ƚ�� ��ȯ
	QueryPerformanceFrequency(&_frequency);
}

void TimeManager::Update()
{
	QueryPerformanceCounter(&_curCount);
	// ���� �����Ӱ� ���� ������ ī���� ���� ���̸� ���Ѵ�
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
