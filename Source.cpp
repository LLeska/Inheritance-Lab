#include <iostream>


using std::cout;
using std::cin;
using std::string;


class Item{
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
       float discont = 0){
    this->name = name; 
    this->manufacturer = manufacturer;
    this->purchase_price = purchase_price; 
    this->sale_price = sale_price;
    this->count_in_stock = count_in_stock;
    this->discont = discont;
  }
string Item::getName(){ return name;}
string Item::getManufacturer(){ return manufacturer;}
float Item::getPurchasePrice(){ return purchase_price;}
float Item::getSalePrice(){return sale_price;}
unsigned int Item::getCountInStock(){ return count_in_stock;}
float Item::getDiscont(){return discont;}
float Item::getProfit(){return profit;}
void Item::setPurchasePrice(float new_price){purchase_price = new_price;}
void Item::setSalePrice(float new_price){sale_price = new_price;}
void Item::setDiscont(float new_discont){discont = new_discont;}


class Clothe: public Item{
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

  //TODO: реализовать нормальные коэфициенты пола/возраста и учет в модность
  void changeFashion(float advertisement);
};

Clothe::Clothe(string name, 
       string manufacturer,
       float purchase_price, 
       float sale_price, 
       float fashion,
       float age_degree = 1,
       float gendere_degree = 1,
       unsigned int count_in_stock = 0,
       float discont = 0): Item (name, manufacturer, purchase_price, sale_price, count_in_stock, discont){
          this->age_degree = age_degree;
          this->gender_degree = gendere_degree;
          this->fashion = fashion;
       }
double Clothe::getAgeDegree(){return age_degree;}
double Clothe::getGenderDegree(){return gender_degree;}
string Clothe::getMaterial(){return material;}
unsigned int Clothe::getAge(){return age;}
unsigned char Clothe::getGender(){return gender;}
float Clothe::getFashionDegree(){return fashion;}
void Clothe::changeFashion(float advertisement){fashion += advertisement*age_degree*gender_degree;}


int main(){
  std::cout << "Hello World";
  return 0;
}
