#pragma once
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include "LocalBlur.h"
#include <memory>

class ImageWindow final
{
public:
	ImageWindow(std::shared_ptr<cv::Mat>& image, std::string const& window_name);
	void draw();
private:
	std::shared_ptr<cv::Mat> original_image_;
	LocalBlur blur_;

	std::string window_name_;
	int initial_side_ = 250;
	int max_side_ = 500;
	int exit_key_ = 27;
};

