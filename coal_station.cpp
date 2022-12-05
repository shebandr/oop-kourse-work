#include "coal_station.h"

int capacity_eu;
int amount_eu;
int income_eu;

coal_station::coal_station(int ce, int ae, int ie) {
    capacity_eu = ce;
    amount_eu = ae;
    income_eu = ie;
}
coal_station::coal_station() {
};
int coal_station::get_capacity_eu() {
    return capacity_eu;
}
int coal_station::get_amount_eu() {
    return amount_eu;
};
int coal_station::get_income_eu() {
    return income_eu;
}

void coal_station::set_capacity_eu(int ceu) {
    capacity_eu = ceu;
}
void coal_station::set_amount_eu(int aeu) {
    amount_eu = aeu;
}
void coal_station::set_income_eu(int ieu) {
    income_eu = ieu;
}
