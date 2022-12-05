#include "based_factory.h"

int capacity;
int amount;
int condition;
int empty = 1;
based_factory::based_factory() {
	type_ground = "resources/Empty.png";
}
based_factory::based_factory(int ca, int am, int co, int em) {
	capacity = ca;
	amount = am;
	condition = co;
	empty = em;
}

 int based_factory::get_condition() {
	return condition;
}

int based_factory::get_amount() {
	return amount;
}
int based_factory::get_capacity() {
	return capacity;
}
int based_factory::get_empty() {
	return empty;
}
int based_factory::adding_resource(int aaamount, int type) {
	if ((amount + aaamount) < capacity) {
		amount += aaamount;
		return 1;
	}
	else {
		return 0;
	}
}
void based_factory::set_amount(int aamount) {
	amount = aamount;
}
void based_factory::set_condition(int cond) {
	condition = cond;
}
void based_factory::set_empty(int eempty) {
	empty=eempty;
}