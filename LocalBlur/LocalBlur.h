#pragma once

#include <opencv2/core/mat.hpp>

void my_gauss_blur(cv::InputArray src, cv::OutputArray dst);
class LocalBlurParams final
{
	int x_, y_, width_, height_;
public:
	LocalBlurParams(int x, int y, int width, int height);
	int get_x() const;
	int get_y() const;
	int get_width() const;
	int get_height() const;
};

class LocalBlur final
{
public:
	LocalBlur(void (* const blur_func)(cv::InputArray&, cv::OutputArray&) = my_gauss_blur);
	void draw(const cv::Mat& image, LocalBlurParams const& params) const;
private:
	void (*blur_func_)(cv::InputArray&, cv::OutputArray&);
	static std::pair<int, int> set_width_and_height(int image_width, int image_height, LocalBlurParams const& blur_params);
	static int cut_long_side(int side_longitude, int coordinate, int image_side);
};
