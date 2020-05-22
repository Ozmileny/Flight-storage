#ifndef FL
#define FL
#include <string>
using std::string;
#include <vector>
using std::vector;

class Flight
{

	string plane_ID;

public:
	Flight(const string& id) : plane_ID(id) {}

	string get_plane_ID() const
	{
		return plane_ID;
	}

	virtual int get_dep_time() = 0;
	virtual int get_full_time() = 0;
	virtual string get_fst_point() = 0;
	virtual vector <string> get_last_point() = 0;
	virtual void print() = 0;
	virtual string c_print() = 0;
	virtual ~Flight() {}
};

#endif