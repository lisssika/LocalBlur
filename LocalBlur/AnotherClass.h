#pragma once
#include <string>
#include <memory>
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include "AnotherClass.h"
#include "MouseMoved.h"
#include <opencv2/core/mat.hpp>


class Window final
{
public:
private:
};


class AnotherClass
{
public:
	AnotherClass(const std::string& filename);
	void draw();
private:
	cv::Mat image;
	cv::Mat original_image;
	
	cv::Rect region;
	int a, b;
	int initial_side = 250;
	std::unique_ptr<int> side_of_blur_rect;

	bool was_moved = false;
	int mouseX_, mouseY_;
	std::unique_ptr<MouseMoved>mouse_;
	void get_mouse_inf();
};

