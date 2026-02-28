#include "Clothe.h"


Clothe::Clothe(string name,
               string manufacturer,
               float purchase_price,
               float sale_price,
               float fashion,
               float age_degree,
               float gendere_degree,
               unsigned int count_in_stock ,
               float discont) : Item(name, manufacturer, purchase_price, sale_price, count_in_stock, discont)
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
void Clothe::printDetails(){
    Item::printDetails();  
    printf("  ---\n");
    printf("  Модность:         %.2f / 10\n", fashion);
    printf("  Коэф. возраста:   %.2f\n", (float)age_degree);
    printf("  Коэф. пола:       %.2f\n", (float)gender_degree);
}