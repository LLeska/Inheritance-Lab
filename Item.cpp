#include "Item.h"

Item::Item(string name,
           string manufacturer,
           float purchase_price,
           float sale_price,
           unsigned int count_in_stock,
           float discont)
{
  this->name = name;
  this->manufacturer = manufacturer;
  this->purchase_price = purchase_price;
  this->sale_price = sale_price;
  this->count_in_stock = count_in_stock;
  this->discont = discont;
  this->profit = 0;

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
void Item::addStock(unsigned int count) { count_in_stock += count; }
void Item::sell(unsigned int count) {
  if (count > count_in_stock) return;
  count_in_stock -= count;
  profit += (sale_price * (1.0 - discont) - purchase_price) * count;
}
void Item::printDetails(){
    printf("  Название:         %s\n",   name.c_str());
    printf("  Производитель:    %s\n",   manufacturer.c_str());
    printf("  Закупочная цена:  %.2f руб.\n", purchase_price);
    printf("  Цена продажи:     %.2f руб.\n", sale_price);
    printf("  Скидка:           %.0f%%\n",    discont * 100);
    printf("  На складе:        %u шт.\n",    count_in_stock);
    printf("  Накоплено прибыли:%.2f руб.\n", profit);
}