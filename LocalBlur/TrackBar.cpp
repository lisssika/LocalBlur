#include <opencv2/highgui.hpp>
#include "TrackBar.h"
#include <string>
#include <memory>
#include <opencv2/core.hpp>

TrackBar::TrackBar(std::string const& window_name, std::string const& name, int start_pos, int max_pos)
{
	position = std::make_unique<int>(start_pos);
	cv::createTrackbar(name, window_name, position.get(), max_pos);
}

int TrackBar::get() const
{
	return *position;
}