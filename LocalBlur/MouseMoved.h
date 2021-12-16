#pragma once
class MouseMoved
{
private:
	int x_ = 0;
	int y_ = 0;
	bool was_moved = false;
public:
	void operator()(int x, int y, bool flg);
	int get_x() const;
	int get_y() const;
	bool moved() const;
	void reset_moved();
};

