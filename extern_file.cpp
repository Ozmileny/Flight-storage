#include "pch.h"
#pragma warning(disable : 4996)
#include "Flight_lib.h"

extern "C" 
{
	//block of LinearFlight functions

	LinearFlight* create_LF(char* dep_point, int dep_day, int dep_time, char* arr_point, int arr_day, int arr_time, char* id)
	{
		return new LinearFlight(dep_point, dep_day, dep_time, arr_point, arr_day, arr_time, id);
	}

	int LF_dep_time(LinearFlight* lf)
	{
		return lf->get_dep_time();
	}

	int LF_full_time(LinearFlight* lf)
	{
		return lf->get_full_time();
	}

	void LF_fst_point(LinearFlight* lf, char* fst_p, int max_fst_p_len)
	{
		strncpy(fst_p, lf->get_fst_point().c_str(), max_fst_p_len);
	}

	void LF_ID(LinearFlight* lf, char* id, int max_id_len)
	{
		strncpy(id, lf->get_plane_ID().c_str(), max_id_len);
	}

	void LF_print(LinearFlight* lf, char* str, int max_str_len)
	{
		string s = lf->c_print();
		strncpy(str, s.c_str(), max_str_len);
	}

	void LF_last_point(LinearFlight* lf, char* last_p, int max_last_p_len)
	{
		string point = lf->get_last_point().back();
		strncpy(last_p, point.c_str(), max_last_p_len);
	}
	void del_LF(LinearFlight* lf)
	{
		delete lf;
	}

	
	//block of vector<int>
	vector<int>* create_int_vector()
	{
		return new vector<int>;
	}

	void del_int_vector(vector<int>* v)
	{
		delete v;
	}
	
	int int_vector_get(vector<int>* v, int i)
	{
		return v->at(i);
	}
	void int_vector_push(vector<int>* v, int i)
	{
		v->push_back(i);
	}

	//block of vector<string>
	vector<string>* create_str_vector()
	{
		return new vector<string>;
	}

	void del_str_vector(vector<string>* v)
	{
		delete v;
	}

	void str_vector_push(vector<string>* v, char* i)
	{
		v->push_back(i);
	}

	void str_vector_get(vector<string>* v, int i, char* str, int max_id_len)
	{
		strncpy(str, v->at(i).c_str(), max_id_len);
	}

	//block of CyclicFlight functions
	CyclicFlight* create_CF(vector<string>* dep_points, vector<int>* dep_days, vector<int>* dep_times, vector<int>* arr_days, vector<int>* arr_times, char* id)
	{
		return new CyclicFlight(*dep_points, *dep_days, *dep_times, *arr_days, *arr_times, id);
	}

	int CF_full_time(CyclicFlight* cf)
	{
		return cf->get_full_time();
	}

	void CF_fst_point(CyclicFlight* cf, char* fst_p, int max_fst_p_len)
	{
		strncpy(fst_p, cf->get_fst_point().c_str(), max_fst_p_len);
	}

	void CF_ID(CyclicFlight* cf, char* id, int max_id_len)
	{
		strncpy(id, cf->get_plane_ID().c_str(), max_id_len);
	}

	vector<string>* CF_last_point(CyclicFlight* lf)
	{
		vector<string>* last = &(lf->get_last_point());
		return last;
	}
	void del_CF(CyclicFlight* cf)
	{
		delete cf;
	}

	//block of Point functions
	Point* create_P(char* name, vector<string>* con_points, vector<int>* max_time, vector<int>* min_time)
	{
		return new Point(name, *con_points, *max_time, *min_time);
	}

	void P_name(Point* p, char* name, int max_name_len)
	{
		strncpy(name, p->get_name().c_str(), max_name_len);
	}

	//blocf of Timetable functions
	Timetable* create_T()
	{
		return new Timetable();
	}
	void T_add_point(Timetable* t, Point* p)
	{
		t->add_point(*p);
	}

	void T_add_lf(Timetable* t, LinearFlight* lf)
	{
		auto ptr = shared_ptr<Flight>(lf);
		t->add_flight(ptr);
	}

	void T_add_cf(Timetable* t, CyclicFlight* cf)
	{
		auto ptr = shared_ptr<Flight>(cf);
		t->add_flight(ptr);
	}

	void T_print(Timetable* t, char* str, int max_str_len)
	{
		string s = t->c_print();
		strncpy(str, s.c_str(), max_str_len);
	}

}
