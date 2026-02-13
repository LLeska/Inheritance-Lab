#include <iostream>

using std::cin;
using std::cout;
using std::string;

class Item
{
protected:
  string name;
  string manufacturer;
  float purchase_price;
  float sale_price;
  unsigned int count_in_stock;
  float discont;
  float profit;

public:
  Item(string name,
       string manufacturer,
       float purchase_price,
       float sale_price,
       unsigned int count_in_stock = 0,
       float discont = 0);
  string getName();
  string getManufacturer();
  float getPurchasePrice();
  float getSalePrice();
  unsigned int getCountInStock();
  float getDiscont();
  float getProfit();
  void setPurchasePrice(float new_price);
  void setSalePrice(float new_price);
  void setDiscont(float new_discont);
};

Item::Item(string name,
           string manufacturer,
           float purchase_price,
           float sale_price,
           unsigned int count_in_stock = 0,
           float discont = 0)
{
  this->name = name;
  this->manufacturer = manufacturer;
  this->purchase_price = purchase_price;
  this->sale_price = sale_price;
  this->count_in_stock = count_in_stock;
  this->discont = discont;
}
string Item::getName() { return name; }
string Item::getManufacturer() { return manufacturer; }
float Item::getPurchasePrice() { return purchase_price; }
float Item::getSalePrice() { return sale_price; }
unsigned int Item::getCountInStock() { return count_in_stock; }
float Item::getDiscont() { return discont; }
float Item::getProfit() { return profit; }
void Item::setPurchasePrice(float new_price) { purchase_price = new_price; }
void Item::setSalePrice(float new_price) { sale_price = new_price; }
void Item::setDiscont(float new_discont) { discont = new_discont; }

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

class Food : public Item
{
protected:
  float mass;             // in grams
  float caloric_content;  // on 100gram
  float pfc[3];           // on 100gram
  string production_date; // DD.MM.YYYY
  string expitarion_date; // DD.MM.YYYY
public:
  Food(string name,
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
       float discont = 0);
  float getMass();
  float getCaloricContent();
  void getPfc(float dest_pfc[3]);
  string getProductionDate();
  string getExpitarionDate(); // empty if no expiration date

  float getCaloricContentOnOne();
  float getCalroicContentOnMoney();
};
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

class HouseholdGood : public Item
{
protected:
  bool dangerous_for_childrens;
  bool necessary_for_apocalypse;
  unsigned char flammability_class; // 1 - difficult to ignite, 2 - moderately flammable, 3 - flammable
public:
  HouseholdGood(string name,
                string manufacturer,
                float purchase_price,
                float sale_price,
                unsigned char flammability_class,
                bool dangerous_for_childrens = false,
                bool necessary_for_apocalypse = false,
                unsigned int count_in_stock = 0,
                float discont = 0);
  bool getDangerousForChildrens();
  bool getNecessaryForApocalypse();
  unsigned char getFlammabilityClass(); // 1 - difficult to ignite, 2 - moderately flammable, 3 - flammable
};
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

int main()
{
  std::cout << "Hello World";
  return 0;
}
