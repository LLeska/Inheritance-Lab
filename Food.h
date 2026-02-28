#include "Item.h"

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
  void printDetails();
};
