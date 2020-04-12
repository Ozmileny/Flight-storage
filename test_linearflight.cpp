#include<cassert>

#include"linearflight.h"

void test_LinearFlight()
{   // ������� ����	
	LinearFlight fl1("Moscow", 2, 13, "Perm", 2, 15, "SU7394");
	LinearFlight fl2("Moscow", 2, 15, "Perm", 2, 17, "SU7395");
	LinearFlight fl3("Moscow", 2, 13, "Perm", 2, 16, "SU7396");

	// ���������, ����� �� ��������� �������� ����
	LinearFlight fl4 = fl1;
	fl4.reverse();
	assert(fl4.get_dep_point() == "Perm");
	assert(fl4.get_arr_point() == "Moscow");
	assert((fl4.get_dep_time() == fl1.get_dep_time()) && (fl4.get_arr_time() == fl1.get_arr_time()));

	// ���������� ����� � ����� ��������, ����� ��� ������������� �����
	assert(fl1 == fl3);

	// ���������� ����� � ����� ��������, ����� ��� �� �����
	assert(!(fl1 == fl2));

	// ���������� ����� � ������ �������� (f1 < f2)
	assert(fl1 < fl2);

	// ���������� ����� � ������ �������� (f1 > f2)
	assert(!(fl2 < fl1));

	// ���������� ����� � ������ �������� (f1 == f2)
	assert(!(fl1 < fl3));
}

int main()
{
	test_LinearFlight();
	return 0;
}