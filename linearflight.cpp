#include<cstdio>

#include"linearflight.h"

void LinearFlight::reverse()
{
	arr_point.swap(dep_point);
}


int LinearFlight::get_dep_time()
{
	return dep_time;
}

vector <string> LinearFlight::get_last_point()
{
	vector <string> list;
	list.push_back(arr_point);
	return list;
}

std::string LinearFlight::get_fst_point()
{
	return dep_point;
}

void LinearFlight::print()
{
	std::cout << get_plane_ID() << " | " << dep_time << " - " << arr_time << " | " << dep_point << " --> " << arr_point <<  " | day " << dep_day << "\n";
}

int LinearFlight::get_full_time()
{
	int x;
	if (dep_day == arr_day)
		x = arr_time - dep_time;
	else x = 24 - dep_time + arr_time;
	return x;
}

bool LinearFlight::operator==(LinearFlight& left)
{
	return left.dep_time == dep_time;
};

bool LinearFlight::operator<(LinearFlight& left)
{
	return  dep_time < left.dep_time;
};