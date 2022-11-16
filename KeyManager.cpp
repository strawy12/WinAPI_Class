#include "pch.h"
#include "KeyManager.h"
#include "Core.h"

int g_arrVK[(int)KEY::LAST] =
{
	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,
	'Q',
	'W',
	'E',
	'R',
	'T',
	'Y',
	'U',
	'I',
	'O',
	'P',
	'A',
	'S',
	'D',
	'F',
	'G',
	'H',
	'J',
	'K',
	'L',
	'Z',
	'X',
	'C',
	'V',
	'B',
	'N',
	'M',
	VK_SPACE,
	VK_LSHIFT,
	VK_RETURN,
	VK_CONTROL,
	VK_ESCAPE,
	VK_TAB
};


KeyManager::KeyManager()
{
}

KeyManager::~KeyManager()
{
}

void KeyManager::Init()
{
	for (UINT i = 0; i < (UINT)KEY::LAST; i++)
	{
		_vecKey.push_back(tKeyInfo{ KEY_STATE::NONE, false });
	}
}

void KeyManager::Update()
{
	///HWND hMainWnd = Core::GetInst()->GetWndHandle();
	HWND hWnd = GetFocus(); // 현재 내가 포커스 하고있는 윈도우 핸들을 가져옴

	if (hWnd != nullptr)
	{
		for (UINT i = 0; i < (UINT)KEY::LAST; i++)
		{
			if (GetAsyncKeyState(g_arrVK[i]) & 0x8000)
			{
				if (_vecKey[i].bPrevCheck)
				{
					_vecKey[i].eState = KEY_STATE::HOLD;
				}

				else
				{
					_vecKey[i].eState = KEY_STATE::TAP;
				}

				_vecKey[i].bPrevCheck = true;
			}

			else
			{
				if (_vecKey[i].bPrevCheck)
				{
					_vecKey[i].eState = KEY_STATE::AWAY;
				}

				else
				{
					_vecKey[i].eState = KEY_STATE::NONE;
				}

				_vecKey[i].bPrevCheck = false;

			}
		}
	}

	else
	{
		for (int i = 0; i < (int)KEY::LAST; i++)
		{
			_vecKey[i].bPrevCheck = false;

			if (_vecKey[i].eState == KEY_STATE::TAP || _vecKey[i].eState == KEY_STATE::HOLD)
			{
				_vecKey[i].eState = KEY_STATE::AWAY;
			}

			else if(_vecKey[i].eState == KEY_STATE::AWAY)
			{
				_vecKey[i].eState = KEY_STATE::NONE;
			}
		}
	}
	
}
