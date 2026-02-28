#include <iostream>
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
