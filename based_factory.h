#pragma once
#include "based_cell.h"
class based_factory:
    public based_cell
{
protected:
	int capacity;
	int amount;
	int condition;
	int not_empty;
public:
	based_factory();
<<<<<<< HEAD
	based_factory(int ca, int am, int co, int em);
	virtual int get_condition();
	virtual int get_amount();
	virtual int get_capacity();
	virtual int get_empty();
	virtual void set_condition(int cond);
	virtual void set_amount(int aamount);
	virtual void set_empty(int eempty);
	virtual int adding_resource(int aaamount, int type);
=======
	int get_condition();
	int get_amount();
	int get_capacity();
	int get_empty();
	void set_condition(int cond);
	void set_amount(int aamount);
	void set_empty(int eempty);
	int adding_resource(int aaamount, int type);
>>>>>>> 372e0346db05afee5c87996208d3c79cf37bf836
};

