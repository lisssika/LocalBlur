#pragma once
#include <opencv2/core/mat.hpp>

class BlurMethod
{
public:
	virtual ~BlurMethod() = default;
	virtual void operator()(cv::InputArray& src, cv::OutputArray& dst) = 0;
};

class GaussBlur final: public BlurMethod
{
public:
	void operator()(cv::InputArray& src, cv::OutputArray& dst) override;
};
