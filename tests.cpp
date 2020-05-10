#include<cassert>

#include "linearflight.h"
#include "cyclicflight.h"
#include "point.h"
#include "timetable.h"


void test_LinearFlight()
{   // создаем рейс	
	LinearFlight fl1("Moscow", 2, 13, "Perm", 2, 15, "SU7394");
	LinearFlight fl2("Moscow", 2, 15, "Perm", 2, 17, "SU7395");
	LinearFlight fl3("Moscow", 2, 13, "Perm", 2, 16, "SU7396");

	// проверяем, верно ли создается обратный рейс
	LinearFlight fl4 = fl1;
	fl4.reverse();
	assert(fl4.get_plane_ID() == "SU7394");
	assert(fl4.get_fst_point() == "Perm");
	assert(fl4.get_last_point().back() == "Moscow");
	//assert((fl4.get_dep_time() == fl1.get_dep_time()) && (fl4.get_arr_time() == fl1.get_arr_time()));

	// сравниваем рейсы с одним временем, когда они действительно равны
	assert(fl1 == fl3);
	// сравниваем рейсы с одним временем, когда они не равны
	assert(!(fl1 == fl2));
	// сравниваем рейсы с разным временем (f1 < f2)
	assert(fl1 < fl2);
	// сравниваем рейсы с разным временем (f1 > f2)
	assert(!(fl2 < fl1));
	// сравниваем рейсы с разным временем (f1 == f2)
	assert(!(fl1 < fl3));
}

void test_CyclicFlight()
{   // создаем рейс	
	vector <string> points = { "Moscow", "London", "Oslo" };
	vector <int> dep_days = { 2, 2, 2 };
	vector <int> dep_times = { 9, 13, 14 };
	vector <int> arr_days = { 2, 2, 2 };
	vector <int> arr_times = { 15, 12, 14 };

	CyclicFlight flight(points, dep_days, dep_times, arr_days, arr_times, "SU7395");

	// проверяем, верно ли создается рейс

	assert(flight.get_fst_point() == "Moscow");
	assert(flight.get_last_point() == points);
	assert(flight.get_full_time() > 0);
	assert(flight.get_plane_ID() == "SU7395");
}

void test_Point()
{
	//создаем точку маршрута
	vector <string> connected_points = { "Tokyo", "London", "Paris", "Oslo" };
	vector <int> max_time = { 12, 6, 3, 4 };
	vector <int> min_time = { 9, 3, 2, 2 };

	//проверяем работу методов и корректность создания
	Point point("Moscow", connected_points, max_time, min_time);
	assert(point.get_connected_points()[2] == "Paris");
	assert(point.get_connected_points().size() == 4);
	assert(point.get_max_time(3) == 4);
	assert(point.get_min_time(3) == 2);
}

vector <Point> create_point_set()
{
	// создаем список точек маршрута для тестирования Рассписания
	vector <string> connected_points = { "Tokyo", "London", "Paris", "Oslo" };
	vector <int> max_time = { 12, 6, 3, 4 };
	vector <int> min_time = { 9, 3, 2, 2 };
	Point p1("Moscow", connected_points, max_time, min_time);

	connected_points = { "Moscow", "Washington" };
	max_time = { 13, 5 };
	min_time = { 10, 3 };
	Point p2("Tokyo", connected_points, max_time, min_time);

	connected_points = { "Moscow", "Washington", "Oslo" };
	max_time = { 6, 4, 2 };
	min_time = { 3, 2, 1 };
	Point p3("London", connected_points, max_time, min_time);

	connected_points = { "Moscow", "Oslo" };
	max_time = { 4, 4 };
	min_time = { 3, 2 };
	Point p4("Paris", connected_points, max_time, min_time);

	connected_points = { "Moscow", "London", "Washington" };
	max_time = { 4, 2, 2 };
	min_time = { 3, 1, 2 };
	Point p5("Oslo", connected_points, max_time, min_time);

	connected_points = { "Tokyo", "Oslo" };
	max_time = { 6, 3 };
	min_time = { 4, 2 };
	Point p6("Washington", connected_points, max_time, min_time);

	vector <Point> point_list{ p1, p2, p3, p4, p5 };

	return point_list;
}

vector<shared_ptr<Flight>> create_flight_set()
{
	LinearFlight *fl1 = new LinearFlight("Moscow", 2, 13, "London", 2, 19, "SU7394");
	LinearFlight *fl2 = new LinearFlight("Moscow", 1, 9, "Paris", 1, 11, "SU7395");
	LinearFlight *fl3 = new LinearFlight("Paris", 2, 11, "London", 2, 15, "SU7391");
	LinearFlight *fl6 = new LinearFlight("Moscow", 2, 23, "Paris", 3, 2, "SU7393");
	LinearFlight *fl5 = new LinearFlight("Moscow", 1, 14, "Paris", 1, 16, "SU7393");


	vector <string> points = { "Moscow", "Oslo", "London" };
	vector <int> dep_days = { 3, 3, 3 };
	vector <int> dep_times = { 14, 16, 18 };
	vector <int> arr_days = { 3, 3, 3 };
	vector <int> arr_times = { 19, 16, 17 };

	CyclicFlight* fl4 = new CyclicFlight (points, dep_days, dep_times, arr_days, arr_times, "SU7395");
	auto ptr4 = shared_ptr<Flight>(fl4);
	
	auto ptr1 = shared_ptr<Flight>(fl1);
	auto ptr2 = shared_ptr<Flight>(fl2);
	auto ptr3 = shared_ptr<Flight>(fl3);
	auto ptr5 = shared_ptr<Flight>(fl5);
	auto ptr6 = shared_ptr<Flight>(fl6);

	vector <shared_ptr<Flight>> flight_list{ ptr1, ptr2, ptr3, ptr6, ptr5, ptr4};
	return flight_list;

}

void test_Timetable()
{
	vector <Point> p_list = create_point_set();
	vector <shared_ptr<Flight>> f_list = create_flight_set();

	Timetable ttable;

	for (int i = 0; i < p_list.size(); i++)
		ttable.add_point(p_list[i]);
	ttable.print_points();

	for (int i = 0; i < f_list.size(); i++)
		ttable.add_flight(f_list[i]);
	ttable.print_timetable();

	std::cout << "Flight time for SU7393 is " << ttable.count_flight_time("SU7393") << " hours \n\n";

	std::cout << "Lets find flight Moscow -> London after 20 \n";
	shared_ptr <Flight> rez = ttable.find_flight(20, "Moscow", "London");
	if (rez == nullptr)
		std::cout << "No suitable rezult \n\n";
	else
		rez->print();

	std::cout << "Lets find flight Moscow -> London after 10 \n";
	rez = ttable.find_flight(10, "Moscow", "London");
	if (rez == nullptr)
		std::cout << "No suitable rezult \n";
	else
		rez->print();



}

int main()
{
	test_LinearFlight();
	test_CyclicFlight();
	test_Point();
	test_Timetable();
	return 0;
}
