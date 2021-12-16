#pragma once
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include "LocalBlur.h"
#include "MouseMoved.h"

class LocalBlur
{
public:
	LocalBlur(const std::string& filename);
	void draw();
private:
	cv::Mat image;
	cv::Mat original_image;
	bool was_moved = false;
	cv::Rect region;
	int a, b;
	int mouseX_, mouseY_;
	int* side_of_blur_rect;
	int initial_side = 250;
	MouseMoved* mouse_;
	void get_mouse_inf();
};

