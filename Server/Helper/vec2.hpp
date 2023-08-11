#pragma once

class Vec2
{
public:

	Vec2();
	Vec2(int _x, int _y);
	~Vec2();
	
	void SetPosition(int _x, int _y);
	int m_X;
	int m_Y;
};
