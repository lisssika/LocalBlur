#pragma once
#include <string>
#include <memory>
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include "ImageWindow.h"
#include "Mouse.h"
#include <opencv2/core/mat.hpp>

#include "LocalBlur.h"
 class TrackBar
 {
	 std::unique_ptr<int> position;
 public:
	 TrackBar(std::string const& window_name, std::string const& name, int start_pos, int max_pos);
	 int get() const;
 };

class ImageWindow
{
public:
	ImageWindow(cv::Mat original_image, std::string const& window_name);
	void draw();
private:
	cv::Mat image;
	cv::Mat original_image_;
	LocalBlur blur;
	std::string window_name_;

	int initial_side = 250;
	std::unique_ptr<int> side_of_blur_rect;

	bool was_moved = false;
	int mouseX_, mouseY_;
	std::unique_ptr<Mouse>mouse_;
	void get_mouse_inf();
};

