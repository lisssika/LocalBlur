#include "BlurMethod.h"
#include <opencv2/imgproc.hpp>

void GaussBlur::operator()(cv::InputArray& src, cv::OutputArray& dst)
{
	cv::GaussianBlur(src, dst, cv::Size(0, 0), 10);
}
