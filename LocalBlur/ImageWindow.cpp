#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <stdexcept>
#include "ImageWindow.h"
#include "Mouse.h"
#include "LocalBlur.h"
#include "TrackBar.h"

ImageWindow::ImageWindow(std::shared_ptr< cv::Mat>& image, std::string const& window_name):window_name_(window_name)
{
	if (!image.get() || image->empty())
	{
		throw std::runtime_error("Image Not Found!");
	}
	original_image_ = image;
}

void ImageWindow::draw()
{
	cv::imshow(window_name_, *original_image_);
	const TrackBar track_bar(window_name_, "side of blur rect", initial_side_, max_side_);
	Mouse mouse(window_name_);
	int key = 0;
	while (key!=exit_key_)
	{
		cv::Mat image;
		original_image_->copyTo(image);
		const int side_blur_region = track_bar.get();
		blur_.reset_param(mouse.get_x(), mouse.get_y(), side_blur_region, side_blur_region);
		key = cv::waitKey(1) & 0xFF;
		
		if(!mouse.moved())
		{
			blur_.draw(image);
		}
		cv::imshow(window_name_, image);
		mouse.reset_moved();
	}
}
