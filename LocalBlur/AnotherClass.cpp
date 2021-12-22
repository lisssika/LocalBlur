#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include "AnotherClass.h"
#include "MouseMoved.h"
#include <iostream>
#include <stdexcept>

#include "LocalBlur.h"

using namespace cv;
using namespace std;



void new_mouse_coordinates(int event, int mouseX, int mouseY, int, void*a)
{
	if (event == EVENT_MOUSEMOVE)
	{
		static_cast<MouseMoved*>(a)->operator()(mouseX, mouseY, true);
		std::cout << mouseY<<'\n';
	}
}

void AnotherClass::get_mouse_inf()
{
	mouseX_ = mouse_->get_x();
	mouseY_ = mouse_->get_y();
	was_moved = mouse_->moved();
}


AnotherClass::AnotherClass(const std::string& filename)
{
	mouse_ = std::make_unique<MouseMoved>();
	original_image = imread(filename);
	if (original_image.empty())
	{
		throw std::runtime_error("Image Not Found!");
	}
	original_image.copyTo(image);
	side_of_blur_rect = std::make_unique<int>(initial_side);
}

void AnotherClass::draw()
{
	LocalBlur blur;
	while (true)
	{
		setMouseCallback("image", new_mouse_coordinates, mouse_.get());
		get_mouse_inf();
		
		imshow("image", image);
		createTrackbar("area", "image", side_of_blur_rect.get(), 500);
		blur.reset_param(mouseX_, mouseY_, *side_of_blur_rect, *side_of_blur_rect);
		auto k = waitKey(6) & 0xFF;
		original_image.copyTo(image);
		if(!mouse_->moved())
		{
			blur.draw(image);
		}
		
		if (k == 27)
		{
			break;
		}
		mouse_->reset_moved();
	}
}
