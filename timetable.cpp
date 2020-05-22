#include "pch.h"
#include<cstdio>

#include"timetable.h"

void Timetable::add_flight(shared_ptr<Flight> f)
{
	if (check(f) == 0)
	{
		std::cout << "Invalid flight entered \n";
		return;
	}


	if (flights.empty())
	{
		flights.push_front(f);
	}
	else if (f->get_dep_time() <= flights.front()->get_dep_time())
	{
		flights.push_front(f);
	}
	else
	{
		bool its_done = false;

		forward_list<shared_ptr<Flight>>::iterator it_point_to_insert = flights.begin();
		for (forward_list<shared_ptr<Flight>>::iterator it = flights.begin(); it != flights.end(); ++it)
		{
			if (f->get_dep_time() >= (*it)->get_dep_time())
			{
				it_point_to_insert = it;
			}
			else
			{
				flights.insert_after(it_point_to_insert, f);
				its_done = true;
				break;
			}
		}

		if (!its_done)
		{
			flights.insert_after(it_point_to_insert, f);
		}
	}
}

void Timetable::add_point(Point p)
{
	points.push_back(p);
}

int Timetable::count_flight_time(string plane_id)
{
	int full_time = 0;

	for (forward_list<shared_ptr<Flight>>::iterator it = flights.begin(); it != flights.end(); ++it)
	{
		if ((*it)->get_plane_ID() == plane_id)
		{
			full_time += (*it)->get_full_time();
		}
	}
	return full_time;
}

void Timetable::print_timetable()
{
	std::cout << "Tametable sorted by departure time\n";
	for (forward_list<shared_ptr<Flight>>::iterator it = flights.begin(); it != flights.end(); ++it)
	{
		(*it)->print();
	}
	std::cout << "\n";
}

void Timetable::print_points()
{
	vector <string> conn_with_i;
	std::cout << "All points \n";

	for (int i = 0; i < points.size(); i++)
	{
		conn_with_i = points[i].get_connected_points();
		std::cout << points[i].get_name() << ": ";
		for (int j = 0; j < conn_with_i.size(); j++)
			std::cout << conn_with_i[j] << " ";
		std::cout << "\n";
	}
	std::cout << "\n";

}

int Timetable::check(shared_ptr<Flight> f)
{
	string A = f->get_fst_point();
	vector <string> B = f->get_last_point();
	for (int i = 0; i < points.size(); i++)
	{
		if (A == points[i].get_name())
		{
			vector <string> list = points[i].get_connected_points();
			for (int z = 0; z < B.size(); z++)
			{
				for (int j = 0; j < list.size(); j++)
				{
					if (B[z] == list[j])
						return 1;
				}
			}
		}
	}
	return 0;
}

shared_ptr<Flight> Timetable::find_flight(int dtime, string fst_point, string last_point)
{
	int full_time = 0;
	string list;
	shared_ptr <Flight> rezult = nullptr;
	forward_list<shared_ptr<Flight>>::iterator it = flights.begin();

	while ((it != flights.end()) && ((*it)->get_dep_time() < dtime))
		it++;

	while (it != flights.end())
	{
		if (((*it)->get_fst_point() != fst_point) || ((*it)->get_last_point().back() != last_point))
		{
			it++;
			continue;
		}

		if (((*it)->get_full_time() < full_time) || (full_time == 0))
		{
			full_time = (*it)->get_full_time();
			rezult = (*it);
		}
		it++;
	}
	return rezult;
}

string Timetable::c_print()
{
	string s;
	for (forward_list<shared_ptr<Flight>>::iterator it = flights.begin(); it != flights.end(); ++it)
	{
		s += (*it)->c_print();
	}
	return s;
}