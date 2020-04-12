#include<cstdio>

#include"linearflight.h"

void LinearFlight::reverse()
{
	std::string s = dep_point;
	dep_point = arr_point;
	arr_point = s;
}
int LinearFlight::get_dep_day() const
{
	return dep_day;
}

int LinearFlight::get_dep_time() const
{
	return dep_time;
}

int LinearFlight::get_arr_day() const
{
	return arr_day;
}

int LinearFlight::get_arr_time() const
{
	return arr_time;
}

std::string LinearFlight::get_dep_point() const
{
	return dep_point;
}

std::string LinearFlight::get_arr_point() const
{
	return arr_point;
}

std::string LinearFlight::get_plane_ID() const
{
	return plane_ID;
}


bool LinearFlight::operator==(LinearFlight& left)
{
	return left.dep_time == dep_time;
};

bool LinearFlight::operator<(LinearFlight& left)
{
	return  dep_time < left.dep_time;
};