#include "pch.h"
#include<cstdio>

#include"cyclicflight.h"


int  CyclicFlight::get_dep_time()
{
	return dep_times[0];
}

int  CyclicFlight::get_full_time()
{
	int x = 0;
	int s = dep_times.size();
	for (int i = 0; i < s - 1; i++)
	{
		if (dep_days[i] == arr_days[i+1])
			x += arr_times[i+1] - dep_times[i];
		else x += 24 - dep_times[i] + arr_times[i+1];
	}
	return x;
}

string CyclicFlight::get_fst_point() 
{
	return dep_points[0];
}

vector <string> CyclicFlight::get_last_point() 
{
	return dep_points;
}

void CyclicFlight::print()
{
	printf("%s", get_plane_ID().c_str());
	for (int i = 0; i < dep_points.size() - 1; ++i)
	{
		printf(" | %d - %d | %s --> %s", dep_times[i], arr_times[i], dep_points[i].c_str(), dep_points[i+1].c_str());
	}
	printf(" | day %d \n", dep_days[0]);
}

string CyclicFlight::c_print()
{
	string str = get_plane_ID();
	for (int i = 0; i < dep_points.size() - 1; ++i)
	{
		str += " | " + std::to_string(dep_times[i]) + " - " + std::to_string(arr_times[i]) + " | " + dep_points[i] + " --> " + dep_points[i + 1];
	}
	str += " | day " + std::to_string(dep_days[0]) + "\n";
	return str;
};