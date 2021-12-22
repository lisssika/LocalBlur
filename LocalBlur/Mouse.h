#pragma once
#include <string>

class Mouse final
{
private:
	int x_ = 0;
	int y_ = 0;
	bool was_moved = false;
public:
	Mouse(const std::string& window_name_);
	void operator()(int x, int y, bool flg);
	int get_x() const;
	int get_y() const;
	bool moved() const;
	void reset_moved();
};

