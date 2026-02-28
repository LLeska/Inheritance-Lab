#include "HouseholdGood.h"


HouseholdGood::HouseholdGood(string name,
                             string manufacturer,
                             float purchase_price,
                             float sale_price,
                             unsigned char flammability_class,
                             bool dangerous_for_childrens,
                             bool necessary_for_apocalypse,
                             unsigned int count_in_stock,
                             float discont) : Item(name, manufacturer, purchase_price, sale_price, count_in_stock, discont)
{
  this->flammability_class = flammability_class;
  this->dangerous_for_childrens = dangerous_for_childrens;
  this->necessary_for_apocalypse = necessary_for_apocalypse;
}
bool HouseholdGood::getDangerousForChildrens() { return dangerous_for_childrens; }
bool HouseholdGood::getNecessaryForApocalypse() { return necessary_for_apocalypse; }
unsigned char HouseholdGood::getFlammabilityClass() { return flammability_class; }
void HouseholdGood::printDetails() {
    Item::printDetails();
    printf("  ---\n");
    char* fl = flammability_class == 1 ? "1 (трудновоспламен.)"
                   : flammability_class == 2 ? "2 (умеренно горючий)"
                                             : "3 (горючий)";
    printf("  Горючесть:        %s\n", fl);
    printf("  Опасно для детей: %s\n", dangerous_for_childrens ? "Да" : "Нет");
    printf("  Нужно при апок.:  %s\n", necessary_for_apocalypse ? "Да" : "Нет");
}
