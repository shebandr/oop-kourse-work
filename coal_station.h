#pragma once
#include "based_factory.h"
class coal_station :
    public based_factory
{
protected:
    int capacity_eu;
    int amount_eu;
    int income_eu;

public:
    coal_station();
    int get_capacity_eu();
    int get_amount_eu();
    int get_income_eu();

    void set_capacity_eu(int ceu);
    void set_amount_eu(int aeu);
    void set_income_eu(int ieu);

   
};

