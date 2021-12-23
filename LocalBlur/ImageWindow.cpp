#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <stdexcept>
#include "ImageWindow.h"
#include "Mouse.h"
#include "LocalBlur.h"
#include "TrackBar.h"

ImageWindow::ImageWindow(const cv::Mat& image, std::string const& window_name):window_name_(window_name)
{
	if (image.empty())
	{
		throw std::runtime_error("Image Not Found!");
	}
	image.copyTo(original_image_);
}

void ImageWindow::draw()
{
	const std::shared_ptr<BlurMethod> blur_method = std::make_shared<GaussBlur>();
	const LocalBlur blur(blur_method);
	cv::imshow(window_name_, original_image_);
	const TrackBar track_bar(window_name_, "side of blur rect", initial_side_, max_side_);
	Mouse mouse(window_name_);
	int key = 0;
	while (key!=exit_key_)
	{
		const int side_blur_region = track_bar.get();
		LocalBlurParams blur_params (mouse.get_x(), mouse.get_y(), side_blur_region, side_blur_region);
		key = cv::waitKey(1) & 0xFF;
		
		if(!mouse.moved())
		{
			cv::Mat blur_image = blur.get_blur_image(original_image_, blur_params);
			cv::imshow(window_name_, blur_image);
		}
		else
		{
			cv::imshow(window_name_, original_image_);
		}
		mouse.reset_moved();
	}
}