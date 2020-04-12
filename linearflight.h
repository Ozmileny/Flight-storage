//! �������� ����� ����� ���� ��������, �������� ��������, ���� � ����� ������ (dep_point /_day/ _time) � �������, � ��� �� ����� �������
//! ����� reverse ������������ �������� ��������� ����� (����� ���� �� ��������, �� � ������ �������) 
//! ������������� ��������� < � == ���������� ��� ����� �� ������� �������

#ifndef LNRFL
#define LNRFL
#include <string>

class LinearFlight
{
	std::string dep_point;
	int dep_day;
	int dep_time;

	std::string arr_point;
	int arr_day;
	int arr_time;

	std::string plane_ID;

public:
	LinearFlight(std::string dp, int dd, int dt, std::string ap, int ad, int at, std::string id)
		:dep_point(dp) ,dep_day(dd), dep_time(dt), arr_point(ap), arr_day(ad), arr_time(at), plane_ID(id) {}

	void reverse();

	int get_dep_day() const;
	int get_dep_time() const;
	int get_arr_day() const;
	int get_arr_time() const;
	std::string get_dep_point() const;
	std::string get_arr_point() const;
	std::string get_plane_ID() const;

	bool operator==(LinearFlight& left);
	bool operator<(LinearFlight& left);
};

#endif