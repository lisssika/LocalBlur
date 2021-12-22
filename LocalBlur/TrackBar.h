#pragma once
#include <string>
#include <memory>

class TrackBar final
{
	std::unique_ptr<int> position;
public:
	TrackBar(std::string const& window_name, std::string const& name, int start_pos, int max_pos);
	int get() const;
};

