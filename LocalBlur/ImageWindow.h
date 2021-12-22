#pragma once
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include "LocalBlur.h"

class ImageWindow final
{
public:
	ImageWindow(const cv::Mat& image, std::string const& window_name);
	void draw();
private:
	cv::Mat image_;
	cv::Mat original_image_;
	LocalBlur blur_;

	std::string window_name_;
	int initial_side_ = 250;
	int max_side_ = 500;
	int exit_key_ = 27;
};

