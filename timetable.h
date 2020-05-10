
#ifndef TTB
#define TTB
#include <string> 
#include <vector>
#include <forward_list>
#include <memory>
#include "point.h"
#include "linearflight.h"
#include "cyclicflight.h"

using std::vector;
using std::string;
using namespace std;

class Timetable
{
	forward_list <shared_ptr<Flight>> flights;
	vector <Point> points;
	

public:
	Timetable() {}

	void add_flight(shared_ptr<Flight> f);
	void add_point(Point p);
	int count_flight_time(string plane_id);
	void print_timetable();
	void print_points();
	int check(shared_ptr<Flight> f);
	shared_ptr<Flight> find_flight(int dtime, string fst_point, string last_point);
};

#endif
