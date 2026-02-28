#include "Item.h"


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
  void printDetails();
};
