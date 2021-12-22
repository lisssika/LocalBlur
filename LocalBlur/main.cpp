#include <opencv2/imgcodecs.hpp>
#include <memory>
#include "ImageWindow.h"

int main()
{
	const cv::Mat image = cv::imread("image.jpg");
	const std::shared_ptr<const cv::Mat> img(&image);
	ImageWindow blur_img(img, "window");
	blur_img.draw();
	return 0;
}