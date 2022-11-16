#pragma once

struct tKeyInfo
{
	//KEY eKey;
	KEY_STATE eState;
	bool bPrevCheck;
};

class KeyManager
{
public:
	SINGLE(KeyManager);

private:
	KeyManager();
	~KeyManager();

public:
	void Init();
	void Update();

public:
	KEY_STATE GetKey(KEY key)
	{
		return _vecKey[(int)key].eState;
	}

private:
	vector<tKeyInfo> _vecKey;
};

