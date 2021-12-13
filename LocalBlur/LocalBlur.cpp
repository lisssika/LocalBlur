#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat image;
int x, y;

void mouse_coordinates(int event, int mouseX, int mouseY, int, void*)
{
	if (event == EVENT_MOUSEMOVE)
	{
		
		cout << mouseX << ' ' << mouseY << endl;
		x = mouseX;
		y = mouseY;
		//circle(image, { 200, 200 }, 50, 0, 8);
		//circle(image, { mouseX, mouseY }, 50, 0, 8);
		
	}
}

int main()
{
	image = imread("image.jpg");
	const Mat original_img = imread("image.jpg");
	if(image.empty())
	{
		cout << "Image Not Found!" << endl;
		cin.get();
		return  -1;
	}
	//circle(image, { 200, 200 }, 50, 0, 8);
	
	while (true)
	{
		setMouseCallback("image", mouse_coordinates);
		imshow("image", image);
		auto k =waitKey(20);
		image = imread("image.jpg");
		Rect region(x, y, 100, 100);
		GaussianBlur(image(region), image(region), Size(0, 0), 10);
		if (k == 27)
		{
			break;
		}
		
	}
	
	return 0;
}