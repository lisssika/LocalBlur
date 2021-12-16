#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include "LocalBlur.h"
#include "MouseMoved.h"

using namespace cv;
using namespace std;

void new_mouse_coordinates(int event, int mouseX, int mouseY, int, void*a)
{
	if (event == EVENT_MOUSEMOVE)
	{
		static_cast<MouseMoved*>(a)->operator()(mouseX, mouseY, true);
	}
}

void LocalBlur::get_mouse_inf()
{
	mouseX_ = mouse_->get_x();
	mouseY_ = mouse_->get_y();
	was_moved = mouse_->moved();
}

LocalBlur::LocalBlur(const std::string& filename)
{
	mouse_ = new MouseMoved;
	original_image = imread(filename);
	if (original_image.empty())
	{
		throw std::runtime_error("Image Not Found!");
	}
	original_image.copyTo(image);
	side_of_blur_rect = new int{ initial_side };
}

void LocalBlur::draw()
{
	while (true)
	{
		setMouseCallback("image", new_mouse_coordinates, mouse_);
		get_mouse_inf();
		imshow("image", image);
		createTrackbar("area", "image", side_of_blur_rect, 500);
		auto k = waitKey(6) & 0xFF;
		original_image.copyTo(image);
		*side_of_blur_rect + mouseX_ > image.cols ? a = image.cols - mouseX_ : a = *side_of_blur_rect;
		*side_of_blur_rect + mouseY_ > image.rows ? b = image.rows - mouseY_ : b = *side_of_blur_rect;
		region = { mouseX_, mouseY_, a, b };
		if (!mouse_->moved()&&a&&b)
		{
			GaussianBlur(image(region), image(region), Size(0, 0), 10);
		}
		if (k == 27)
		{
			break;
		}
		mouse_->reset_moved();
	}
}


