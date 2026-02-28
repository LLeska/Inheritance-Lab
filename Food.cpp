#include "Food.h"


Food::Food(string name,
           string manufacturer,
           float purchase_price,
           float sale_price,
           float fashion,
           float mass,
           float caloric_content,
           float pfc[3],
           string production_date,      // DD.MM.YYYY
           string expitarion_date = "", // DD.MM.YYYY
           unsigned int count_in_stock = 0,
           float discont = 0) : Item(name, manufacturer, purchase_price, sale_price, count_in_stock, discont)
{
  this->caloric_content = caloric_content;
  for (int i = 0; i < 3; i++)
  {
    this->pfc[i] = pfc[i];
  }
  this->production_date = production_date;
  this->expitarion_date = expitarion_date;
}
float Food::getMass() { return mass; }
float Food::getCaloricContent() { return caloric_content; }
void Food::getPfc(float dest_pfc[3])
{
  for (int i = 0; i < 3; i++)
  {
    dest_pfc[i] = pfc[i];
  }
}
string Food::getExpitarionDate() { return expitarion_date; }
string Food::getProductionDate() { return production_date; }
float Food::getCaloricContentOnOne() { return caloric_content * mass / 100; }
float Food::getCalroicContentOnMoney() { return caloric_content * (mass / 100) / sale_price; }