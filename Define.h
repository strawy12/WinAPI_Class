#pragma once


#define SINGLE(type)		\
static type* GetInst()		\
{							\
	static type core;		\
	return &core;			\
}

#define WINDOW_NAME L"OIF Framework"

#define FDT TimeManager::GetInst()->GetfDT()
#define DT TimeManager::GetInst()->GetDT()
#define KEY_CHECK(key, state) KeyManager::GetInst()->GetKey(key) == state
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_TAP(key)  KEY_CHECK(key, KEY_STATE::TAP)
#define KEY_AWAY(key)  KEY_CHECK(key, KEY_STATE::AWAY)
#define KEY_NONE(key) KEY_CHECK(key, KEY_STATE::NONE)

enum class KEY_STATE
{
	NONE,
	TAP,
	HOLD,
	AWAY,
};

enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	Q,W,E,R,T,Y,U,I,O,P,
	A,S,D,F,G,H,J,K,L,
	Z,X,C,V,B,N,M,
	SPACE,
	LSHIFT,
	ENTER,
	CTRL,
	ESC,
	TAB,
	LAST
};

enum class GROUP_TYPE
{
	DEFAULT,
	PLATYER,
	BULLET,
	MONSTER,
	END = 30,
};

enum class SCENE_TYPE
{
	START,
	SCENE_01,
	SCENE_02,
	TOOL,
	END
};