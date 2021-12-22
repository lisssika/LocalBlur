#include "LocalBlur.h"
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include <stdexcept>
void my_gauss_blur(cv::InputArray src, cv::OutputArray dst)
{
	cv::GaussianBlur(src, dst, cv::Size(0, 0), 10);
}

LocalBlur::LocalBlur(void(* const blur_func)(cv::InputArray&, cv::OutputArray&)) :blur_func_(blur_func)
{
	if (blur_func == nullptr)
	{
		throw std::runtime_error("null pointer for blur function");
	}
}

void LocalBlur::set_width_and_height(int image_width, int image_height)
{
	cut_long_side(width_, x_coordinate_, image_width);
	cut_long_side(height_, y_coordinate_, image_height);
}

void LocalBlur::cut_long_side(int& side_longitude, const int& coordinate, const int& image_side)
{
	if (side_longitude + coordinate > image_side)
	{
		side_longitude = image_side - coordinate;
	}
}

void LocalBlur::draw(const cv::Mat& image)
{
	set_width_and_height(image.cols, image.rows);
	const cv::Rect region{ x_coordinate_, y_coordinate_, width_, height_ };
	if (width_ && height_)
	{
		blur_func_(image(region), image(region));
	}
}

void LocalBlur::reset_param(int x, int y, int width, int height)
{
	x_coordinate_ = x;
	y_coordinate_ = y;
	width_ = width;
	height_ = height;
}
