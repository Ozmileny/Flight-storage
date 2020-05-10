#include<cstdio>

#include"point.h"




int  Point::get_max_time(int n) const
{
	return max_times[n];
}

int  Point::get_min_time(int n) const
{
	return min_times[n];
}

vector <string>  Point::get_connected_points() const
{
	return connected_points;
}

string Point::get_name() const
{
	return name;
}