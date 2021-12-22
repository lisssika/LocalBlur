#include <opencv2/imgcodecs.hpp>
#include <memory>
#include "ImageWindow.h"

int main()
{
	cv::Mat image = cv::imread("image.jpg");
	std::shared_ptr<cv::Mat> img(&image);
	ImageWindow blur_img(img, "window");
	blur_img.draw();
	return 0;
}