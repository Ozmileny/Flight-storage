//! 


#ifndef PNT
#define PNT
#include <string>
#include<vector> 
using std::vector;
using std::string;

class Point
{
	string name;
	vector <string> connected_points;
	vector <int> max_times;
	vector <int> min_times;
	
public:
	Point(const string& name, const vector <string>& cp, const vector <int>& mxt, const vector <int>& mnt)
		:name(name), connected_points(cp), max_times(mxt), min_times(mnt) {}

	int get_max_time(int n) const;
	int get_min_time(int n) const;
	vector <string> get_connected_points() const;
	string get_name() const;
};

#endif