#pragma once
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>

class ImageWindow final
{
public:
	ImageWindow(const cv::Mat& image, std::string const& window_name);
	void draw();
private:
	std::string window_name_;
	int exit_key_ = 27;
	cv::Mat original_image_;

	int initial_side_ = 250;
	int max_side_ = 500;

	
};

