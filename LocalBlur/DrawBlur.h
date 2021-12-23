#pragma once
#include <opencv2/core/mat.hpp>

class DrawBlur
{
	virtual ~DrawBlur() = default;
	virtual cv::Mat execute(cv::Mat image) = 0;
};

