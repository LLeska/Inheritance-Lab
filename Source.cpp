#include <vector>
#include <string>
#include <cstdio>
#include "Item.h"
#include "Clothe.h"
#include "Food.h"
#include "HouseholdGood.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;


void clearInput() {
    cin.clear();
    cin.ignore(256, '\n');
}

void printSep(char c = '=', int n = 50) {
    cout << "\n" << string(n, c) << "\n";
}


void printItemInfo(Item* item) {
    printSep('-', 45);
    item->printDetails();
    printSep('-', 45);
}

void listItems(const vector<Item*>& items) {
    if (items.empty()) { cout << "  Склад пуст.\n"; return; }
    printf("  %-4s %-30s %10s %7s %10s\n", "№", "Название", "Цена", "Склад", "Прибыль");
    printf("  %s\n", string(65, '-').c_str());
    for (size_t i = 0; i < items.size(); ++i) {
        printf("  %-4zu %-30s %10.2f %7u %10.2f\n",
               i + 1,
               items[i]->getName().c_str(),
               items[i]->getSalePrice(),
               items[i]->getCountInStock(),
               items[i]->getProfit());
    }
}

int selectItem(const vector<Item*>& items) {
    if (items.empty()) { cout << "  Склад пуст.\n"; return -1; }
    listItems(items);
    int id;
    cout << "  Номер товара: "; cin >> id; clearInput();
    if (id < 1 || id > (int)items.size()) { cout << "  Неверный номер.\n"; return -1; }
    return id - 1;
}


Item* inputClothe() {
    string name, manufacturer;
    float pp, sp, fashion, age_d, gen_d, disc;
    unsigned int cnt;

    clearInput();
    cout << "  Название: ";         getline(cin, name);
    cout << "  Производитель: ";    getline(cin, manufacturer);
    cout << "  Закупочная цена: ";  cin >> pp;      clearInput();
    cout << "  Цена продажи: ";     cin >> sp;      clearInput();
    cout << "  Модность (0-10): ";  cin >> fashion; clearInput();
    cout << "  Коэф. возраста: ";   cin >> age_d;   clearInput();
    cout << "  Коэф. пола: ";       cin >> gen_d;   clearInput();
    cout << "  Кол-во на складе: "; cin >> cnt;     clearInput();
    cout << "  Скидка (0.0-1.0): "; cin >> disc;    clearInput();

    return new Clothe(name, manufacturer, pp, sp, fashion, age_d, gen_d, cnt, disc);
}

Item* inputFood() {
    string name, manufacturer, prod, exp;
    float pp, sp, mass, kcal, pfc[3], disc;
    unsigned int cnt;

    clearInput();
    cout << "  Название: ";                   getline(cin, name);
    cout << "  Производитель: ";              getline(cin, manufacturer);
    cout << "  Закупочная цена: ";            cin >> pp;   clearInput();
    cout << "  Цена продажи: ";               cin >> sp;   clearInput();
    cout << "  Масса (г): ";                  cin >> mass; clearInput();
    cout << "  Калорийность ккал/100г: ";     cin >> kcal; clearInput();
    cout << "  Белки г/100г: ";               cin >> pfc[0]; clearInput();
    cout << "  Жиры г/100г: ";                cin >> pfc[1]; clearInput();
    cout << "  Углеводы г/100г: ";            cin >> pfc[2]; clearInput();
    cout << "  Дата произв. (ДД.ММ.ГГГГ): "; cin >> prod; clearInput();
    cout << "  Срок годности (Enter = нет): "; getline(cin, exp);
    cout << "  Кол-во на складе: ";           cin >> cnt;  clearInput();
    cout << "  Скидка (0.0-1.0): ";           cin >> disc; clearInput();

    return new Food(name, manufacturer, pp, sp, 0, mass, kcal, pfc, prod, exp, cnt, disc);
}

Item* inputHouseholdGood() {
    string name, manufacturer;
    float pp, sp, disc;
    unsigned int cnt;
    int fl, danger, apoc;

    clearInput();
    cout << "  Название: ";                      getline(cin, name);
    cout << "  Производитель: ";                 getline(cin, manufacturer);
    cout << "  Закупочная цена: ";               cin >> pp;     clearInput();
    cout << "  Цена продажи: ";                  cin >> sp;     clearInput();
    cout << "  Класс горючести (1/2/3): ";       cin >> fl;     clearInput();
    cout << "  Опасно для детей (1/0): ";        cin >> danger; clearInput();
    cout << "  Нужно при апокалипсисе (1/0): ";  cin >> apoc;   clearInput();
    cout << "  Кол-во на складе: ";              cin >> cnt;    clearInput();
    cout << "  Скидка (0.0-1.0): ";              cin >> disc;   clearInput();

    return new HouseholdGood(name, manufacturer, pp, sp,
                             (unsigned char)fl, (bool)danger, (bool)apoc, cnt, disc);
}


int main() {
    vector<Item*> items;
    int choice;

    while (true) {
        printSep();
        printf("       СКЛАД МАГАЗИНА  (товаров: %zu)\n", items.size());
        printSep();
        cout << "  1. Добавить товар\n"
             << "  2. Пополнить запас\n"
             << "  3. Продать / списать\n"
             << "  4. Характеристики товара\n"
             << "  5. Все товары\n"
             << "  6. Изменить цену продажи\n"
             << "  7. Изменить скидку\n"
             << "  0. Выход\n";
        printSep('-', 50);
        cout << "  Выбор: "; cin >> choice;
        if (cin.fail()) {
            cin.clear();
            clearInput();
            cout << "  Неверный ввод.\n";
            continue;
        }
        clearInput();

        switch (choice) {

        case 1: {
            printSep();
            cout << "  Тип:\n  1. Одежда\n  2. Еда\n  3. Хозтовары\n  Выбор: ";
            int t; cin >> t; clearInput();
            Item* item = nullptr;
            if      (t == 1) item = inputClothe();
            else if (t == 2) item = inputFood();
            else if (t == 3) item = inputHouseholdGood();
            else { cout << "  Неверный тип.\n"; break; }
            items.push_back(item);
            printf("  Товар «%s» добавлен.\n", item->getName().c_str());
            break;
        }

        case 2: {
            printSep();
            int id = selectItem(items);
            if (id < 0) break;
            unsigned int count;
            cout << "  Добавить единиц: "; cin >> count; clearInput();
            items[id]->addStock(count);
            printf("  На складе теперь: %u шт.\n", items[id]->getCountInStock());
            break;
        }

        case 3: {
            printSep();
            int id = selectItem(items);
            if (id < 0) break;
            unsigned int count;
            cout << "  Продать/списать единиц: "; cin >> count; clearInput();
            if (count > items[id]->getCountInStock()) {
                cout << "  Недостаточно товара!\n";
            } else {
                items[id]->sell(count);
                printf("  Списано %u шт.  Остаток: %u шт.  Прибыль: %.2f руб.\n",
                       count,
                       items[id]->getCountInStock(),
                       items[id]->getProfit());
            }
            break;
        }

        case 4: {
            printSep();
            int id = selectItem(items);
            if (id < 0) break;
            printItemInfo(items[id]);
            break;
        }

        case 5: {
            printSep();
            listItems(items);
            if (!items.empty()) {
                float total = 0;
                for (auto* it : items) total += it->getProfit();
                printf("\n  Общая прибыль со всех позиций: %.2f руб.\n", total);
            }
            break;
        }

        case 6: {
            printSep();
            int id = selectItem(items);
            if (id < 0) break;
            float p;
            cout << "  Новая цена продажи: "; cin >> p; clearInput();
            items[id]->setSalePrice(p);
            cout << "  Цена обновлена.\n";
            break;
        }

        case 7: {
            printSep();
            int id = selectItem(items);
            if (id < 0) break;
            float d;
            cout << "  Новая скидка (0.0-1.0): "; cin >> d; clearInput();
            items[id]->setDiscont(d);
            cout << "  Скидка обновлена.\n";
            break;
        }

        case 0:
            cout << "\n  До свидания!\n";
            for (auto* it : items) delete it;
            return 0;

        default:
            cout << "  Неверный выбор.\n";
        }
    }
}
