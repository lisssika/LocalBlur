#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int mouseX_, mouseY_;
bool was_moved;
Rect region;
int a, b;

void draw_blur(int event, int mouseX, int mouseY, int, void*)
{
	if (event == EVENT_MOUSEMOVE)
	{
		mouseX_ = mouseX;
		mouseY_ = mouseY;
		was_moved = true;
	}
}

int main()
{
	int* side_of_blur_rect = new(int);
	*side_of_blur_rect = 100;
	was_moved = false;
	Mat image = imread("image.jpg");
	const Mat original_img = imread("image.jpg");
	if(image.empty())
	{
		cout << "Image Not Found!" << endl;
		cin.get();
		return  -1;
	}
	
	while (true)
	{
		setMouseCallback("image", draw_blur);

		imshow("image", image);
		createTrackbar("area", "image", side_of_blur_rect, 500);
		auto k = waitKey(6) & 0xFF;
		original_img.copyTo(image);

		*side_of_blur_rect + mouseX_ > image.cols ? a = image.cols - mouseX_ : a = *side_of_blur_rect;
		*side_of_blur_rect + mouseY_ > image.rows ? b = image.rows - mouseY_ : b = *side_of_blur_rect;

		region = { mouseX_, mouseY_, a, b };
		if (!was_moved)
		{
			GaussianBlur(image(region), image(region), Size(0, 0), 10);
		}
		if (k == 27)
		{
			break;
		}
		was_moved = false;
	}
	
	return 0;
}