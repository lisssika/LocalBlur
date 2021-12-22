#include "Mouse.h"
#include <opencv2/highgui.hpp>

void new_mouse_coordinates(int event, int mouseX, int mouseY, int, void* a)
{
	if (event == cv::EVENT_MOUSEMOVE)
	{
		static_cast<Mouse*>(a)->operator()(mouseX, mouseY, true);
	}
}

Mouse::Mouse(const std::string& window_name_)
{
	cv::setMouseCallback(window_name_, new_mouse_coordinates, this);
}

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
