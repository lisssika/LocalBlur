#include <opencv2/imgcodecs.hpp>

#include "ImageWindow.h"

int main()
{
	cv::Mat image = cv::imread("image.jpg");
	ImageWindow blur_img(image, "window");
	blur_img.draw();
	return 0;
}