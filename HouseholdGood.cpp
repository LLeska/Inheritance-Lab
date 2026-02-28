#include "HouseholdGood.h"


HouseholdGood::HouseholdGood(string name,
                             string manufacturer,
                             float purchase_price,
                             float sale_price,
                             unsigned char flammability_class,
                             bool dangerous_for_childrens = false,
                             bool necessary_for_apocalypse = false,
                             unsigned int count_in_stock = 0,
                             float discont = 0) : Item(name, manufacturer, purchase_price, sale_price, count_in_stock, discont)
{
  this->flammability_class = flammability_class;
  this->dangerous_for_childrens = dangerous_for_childrens;
  this->necessary_for_apocalypse = necessary_for_apocalypse;
}
bool HouseholdGood::getDangerousForChildrens() { return dangerous_for_childrens; }
bool HouseholdGood::getNecessaryForApocalypse() { return necessary_for_apocalypse; }
unsigned char HouseholdGood::getFlammabilityClass() { return flammability_class; }
