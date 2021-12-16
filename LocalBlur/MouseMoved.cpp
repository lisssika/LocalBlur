#include "MouseMoved.h"

void MouseMoved::operator()(int x, int y, bool flg)
{
	x_ = x;
	y_ = y;
	was_moved = flg;
}

int MouseMoved::get_x() const
{
	return x_;
}

int MouseMoved::get_y() const
{
	return y_;
}

bool MouseMoved::moved() const
{
	return was_moved;
}

void MouseMoved::reset_moved()
{
	was_moved = false;
}
