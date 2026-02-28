#include "Item.h"

class Clothe : public Item
{
protected:
  double age_degree;
  double gender_degree;
  string material;
  unsigned int age;
  unsigned char gender;
  float fashion;

public:
  Clothe(string name,
         string manufacturer,
         float purchase_price,
         float sale_price,
         float fashion,
         float age_degree = 1,
         float gendere_degree = 1,
         unsigned int count_in_stock = 0,
         float discont = 0);

  double getAgeDegree();
  double getGenderDegree();
  string getMaterial();
  unsigned int getAge();
  unsigned char getGender();
  float getFashionDegree();

  // TODO: реализовать нормальные коэфициенты пола/возраста и учет в модность
  virtual void changeFashion(float advertisement);
  virtual void changePrice();
};