#pragma once

#include <opencv2/core/mat.hpp>

void my_gauss_blur(cv::InputArray src, cv::OutputArray dst);

class LocalBlur final
{
public:
	LocalBlur(void (* const blur_func)(cv::InputArray&, cv::OutputArray&) = my_gauss_blur);
	void draw(const cv::Mat& image);
	void reset_param(int x, int y, int width, int height);
private:
	void (*blur_func_)(cv::InputArray&, cv::OutputArray&);
	int x_coordinate_ = 0;
	int y_coordinate_ = 0;
	int width_ = 0;
	int height_ = 0;
	void set_width_and_height(int image_width, int image_height);
	static void cut_long_side(int& side_longitude, const int& coordinate, const int& image_side);
};
