#include "vec2.hpp"

Vec2::Vec2() :m_X(0), m_Y(0)
{

}

Vec2::Vec2(int _x, int _y)
{
	m_X = _x; m_Y = _y;
}

Vec2::~Vec2()
{
}

void Vec2::SetPosition(int _x, int _y)
{
	m_X = _x; m_Y = _y;
}
