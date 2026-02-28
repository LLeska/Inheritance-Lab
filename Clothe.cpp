#include "Clothe.h"


Clothe::Clothe(string name,
               string manufacturer,
               float purchase_price,
               float sale_price,
               float fashion,
               float age_degree = 1,
               float gendere_degree = 1,
               unsigned int count_in_stock = 0,
               float discont = 0) : Item(name, manufacturer, purchase_price, sale_price, count_in_stock, discont)
{
  this->age_degree = age_degree;
  this->gender_degree = gendere_degree;
  this->fashion = fashion;
}
double Clothe::getAgeDegree() { return age_degree; }
double Clothe::getGenderDegree() { return gender_degree; }
string Clothe::getMaterial() { return material; }
unsigned int Clothe::getAge() { return age; }
unsigned char Clothe::getGender() { return gender; }
float Clothe::getFashionDegree() { return fashion; }