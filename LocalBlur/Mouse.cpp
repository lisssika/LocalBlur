#include "Mouse.h"

void Mouse::operator()(int x, int y, bool flg)
{
	x_ = x;
	y_ = y;
	was_moved = flg;
}

int Mouse::get_x() const
{
	return x_;
}

int Mouse::get_y() const
{
	return y_;
}

bool Mouse::moved() const
{
	return was_moved;
}

void Mouse::reset_moved()
{
	was_moved = false;
}
