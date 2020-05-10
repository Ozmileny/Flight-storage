#ifndef LNRFL
#define LNRFL
#include <string>
#include <vector>
using std::string;
using std::vector;
#include <iostream>

#include "flight.h"

class LinearFlight: public Flight
{
	string dep_point;
	int dep_day;
	int dep_time;

	string arr_point;
	int arr_day;
	int arr_time;

public:
	LinearFlight(const string& dp, int dd, int dt, const string& ap, int ad, int at, const string& id)
		:dep_point(dp) ,dep_day(dd), dep_time(dt), arr_point(ap), arr_day(ad), arr_time(at), Flight(id) {}

	void reverse();

	int get_dep_time() override;
	int get_full_time() override;
	string get_fst_point() override;
	vector<string> get_last_point() override;
	void print() override;

	bool operator==(LinearFlight& left);
	bool operator<(LinearFlight& left);
};

#endif