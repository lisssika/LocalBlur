#include "pch.h"
#include "../LocalBlur/LocalBlur.h"
#include "../LocalBlur/Mouse.h"
#include "../LocalBlur/TrackBar.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>


//---------------------------------LocalBlur
TEST(LocalBlur, test) {
	LocalBlur blur;
	int x_coordinate_=5;
	int y_coordinate_ = 6;
	int width_ = 40;
	int height_ = 40;
	const cv::Mat image = cv::imread("image.jpg");
	cv::Mat image2;
	image.copyTo(image2);
	blur.reset_param(x_coordinate_, y_coordinate_, width_, height_);
	blur.draw(image,);
	const cv::Rect region{ x_coordinate_, y_coordinate_, width_, height_ };
	GaussianBlur(image2(region), image2(region), cv::Size(0, 0), 10);
	EXPECT_EQ(image, image2);
}