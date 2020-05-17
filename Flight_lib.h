#pragma once

#include "timetable.h"

#ifdef FLIGHTLIB_EXPORTS
#define FLIGHTLIB_API __declspec(dllexport)
#else
#define FLIGHTLIB_API __declspec(dllimport)
#endif

extern "C"
{
	//adapt  LinearFlight functions
	FLIGHTLIB_API LinearFlight* create_LF(char* dep_point, int dep_day, int dep_time, char* arr_point, int arr_day, int arr_time, char* id);
	FLIGHTLIB_API int LF_dep_time(LinearFlight* lf);
	FLIGHTLIB_API int LF_full_time(LinearFlight* lf);
	FLIGHTLIB_API void LF_fst_point(LinearFlight* lf, char* fst_p, int max_fst_p_len);
	FLIGHTLIB_API void LF_ID(LinearFlight* lf, char* id, int max_id_len);
	FLIGHTLIB_API void LF_last_point(LinearFlight* lf, char* last_p, int max_last_p_len);
	FLIGHTLIB_API void LF_print(LinearFlight* lf);

	//adapt vector<int>
	FLIGHTLIB_API vector<int>* create_int_vector();
	FLIGHTLIB_API void del_int_vector(vector<int>* v);
	FLIGHTLIB_API int int_vector_get(vector<int>* v, int i);
	FLIGHTLIB_API void int_vector_push(vector<int>* v, int i);

	//adapt vector<string>
	FLIGHTLIB_API vector<string>* create_str_vector();
	FLIGHTLIB_API void del_str_vector(vector<string>* v);
	FLIGHTLIB_API void str_vector_get(vector<string>* v, int i, char* str, int max_id_len);
	FLIGHTLIB_API void str_vector_push(vector<string>* v, char* i);

	//adapt  CyclicFlight functions
	FLIGHTLIB_API CyclicFlight* create_CF(vector<string>* dep_points, vector<int>* dep_days, vector<int>* dep_times, vector<int>* arr_days, vector<int>* arr_times, char* id);
	FLIGHTLIB_API int CF_full_time(CyclicFlight* cf);
	FLIGHTLIB_API void CF_fst_point(CyclicFlight* cf, char* fst_p, int max_fst_p_len);
	FLIGHTLIB_API void CF_ID(CyclicFlight* cf, char* id, int max_id_len);
	FLIGHTLIB_API vector<string>* CF_last_point(CyclicFlight* lf);

}