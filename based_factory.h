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
	int get_condition();
	int get_amount();
	int get_capacity();
	int get_empty();
	void set_condition(int cond);
	void set_amount(int aamount);
	void set_empty(int eempty);
	int adding_resource(int aaamount, int type);
};

