#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include "ImageWindow.h"
#include "Mouse.h"
#include <iostream>
#include <stdexcept>

#include "LocalBlur.h"

using namespace cv;
using namespace std;



void new_mouse_coordinates(int event, int mouseX, int mouseY, int, void*a)
{
	if (event == EVENT_MOUSEMOVE)
	{
		static_cast<Mouse*>(a)->operator()(mouseX, mouseY, true);
		std::cout << mouseY<<'\n';
	}
}

void ImageWindow::get_mouse_inf()
{
	mouseX_ = mouse_->get_x();
	mouseY_ = mouse_->get_y();
	was_moved = mouse_->moved();
}


TrackBar::TrackBar(std::string const& window_name, std::string const& name, int start_pos, int max_pos)
{
	position = make_unique<int>(start_pos);
	createTrackbar(name, window_name, position.get(), max_pos);
}

int TrackBar::get() const
{
	return *position;
}

ImageWindow::ImageWindow(cv::Mat original_image, std::string const& window_name):window_name_(window_name)
{
	mouse_ = std::make_unique<Mouse>();
	if (original_image.empty())
	{
		throw std::runtime_error("Image Not Found!");
	}
	original_image.copyTo(image);
	original_image.copyTo(original_image_);
	side_of_blur_rect = std::make_unique<int>(initial_side);
}



void ImageWindow::draw()
{
	imshow(window_name_, image);
	TrackBar treck_bar(window_name_, "area", 250, 500);
	
	while (true)
	{
		setMouseCallback(window_name_, new_mouse_coordinates, mouse_.get());
		get_mouse_inf();
		
		imshow(window_name_, image);
		//createTrackbar("area", window_name_, side_of_blur_rect.get(), 500);
		int side_blur_region = treck_bar.get();
		blur.reset_param(mouseX_, mouseY_, side_blur_region, side_blur_region);
		auto k = waitKey(6) & 0xFF;
		original_image_.copyTo(image);
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
