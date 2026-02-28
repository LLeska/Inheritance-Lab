#include "Item.h"

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