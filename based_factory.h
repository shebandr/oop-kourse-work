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
	based_factory(int ca, int am, int co, int em);
	virtual int get_condition();
	virtual int get_amount();
	virtual int get_capacity();
	virtual int get_empty();
	virtual void set_condition(int cond);
	virtual void set_amount(int aamount);
	virtual void set_empty(int eempty);
	virtual int adding_resource(int aaamount, int type);
};

