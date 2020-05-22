#ifndef CFL
#define CFL
#include<string>
#include<vector> 
using std::vector;
using std::string;

#include <iostream>

#include "flight.h"

class CyclicFlight: public Flight
{
	vector <string> dep_points;
	vector <int> dep_days;
	vector <int> dep_times;

	vector <int> arr_days;
	vector <int> arr_times;

public:
	CyclicFlight( const vector <string>& dp, const vector <int>& dd, const vector <int>& dt, const vector <int>& ad, const vector <int>& at, const string& id)
		:dep_points(dp), dep_days(dd), dep_times(dt), arr_days(ad), arr_times(at), Flight(id) {}


	int get_dep_time() override;
	int get_full_time() override;
	string get_fst_point() override;
	vector <string> get_last_point() override;
	string c_print() override;
	void print() override;
};

#endif