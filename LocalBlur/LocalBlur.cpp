#include "LocalBlur.h"
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include <stdexcept>

LocalBlurParams::LocalBlurParams(int x, int y, int width, int height):
							x_(x), y_(y), width_(width), height_(height) {}

int LocalBlurParams::get_x() const
{
	return x_;
}

int LocalBlurParams::get_y() const
{
	return y_;
}
int LocalBlurParams::get_width() const
{
	return width_;
}
int LocalBlurParams::get_height() const
{
	return height_;
}

LocalBlur::LocalBlur(const std::shared_ptr<BlurMethod>& blur_method) :blur_method_(blur_method)
{
	if (!blur_method)
	{
		throw std::runtime_error("null pointer for blur function");
	}
}

std::pair<int, int> LocalBlur::set_width_and_height(int image_width, int image_height,
                                                    LocalBlurParams const& blur_params)
{
	int width = cut_long_side(blur_params.get_width(), blur_params.get_x(), image_width);
	int height = cut_long_side(blur_params.get_height(), blur_params.get_height(), image_height);
	return { width, height };
}

int LocalBlur::cut_long_side(int side_longitude, int coordinate, int image_side)
{
	if (side_longitude + coordinate > image_side)
	{
		return  image_side - coordinate;
	}
	return  side_longitude;
}

void LocalBlur::draw(const cv::Mat& image, LocalBlurParams const& params) const
{
	const std::pair<int, int>region_sides = set_width_and_height(image.cols, image.rows, params);
	const int width = region_sides.first;
	const int height = region_sides.second;
	const cv::Rect region{ params.get_x(), params.get_y(), width, height };
	if (width && height)
	{
		blur_method_->operator()(image(region), image(region));
	}
}
