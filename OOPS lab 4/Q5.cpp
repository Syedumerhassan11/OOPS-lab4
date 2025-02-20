#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MenuItem {
public:
    string name;
    string type;
    double price;

    MenuItem(string n, string t, double p) : name(n), type(t), price(p) {}
};

class CoffeeShop {
private:
    string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string n) : name(n) {}

    void addMenuItem(string itemName, string itemType, double itemPrice) {
        menu.push_back(MenuItem(itemName, itemType, itemPrice));
    }

    string addOrder(string itemName) {
        for (const auto& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string order = orders.front();
            orders.erase(orders.begin());
            return "The " + order + " is ready";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0;
        for (const auto& order : orders) {
            for (const auto& item : menu) {
                if (item.name == order) {
                    total += item.price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "No items in menu";
        MenuItem cheapest = menu[0];
        for (const auto& item : menu) {
            if (item.price < cheapest.price) {
                cheapest = item;
            }
        }
        return cheapest.name;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (const auto& item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> food;
        for (const auto& item : menu) {
            if (item.type == "food") {
                food.push_back(item.name);
            }
        }
        return food;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <shop name>" << endl;
        return 1;
    }

    CoffeeShop shop(argv[1]);
    shop.addMenuItem("Espresso", "drink", 2.5);
    shop.addMenuItem("Latte", "drink", 3.5);
    shop.addMenuItem("Muffin", "food", 2.0);
    shop.addMenuItem("Sandwich", "food", 4.5);

    cout << shop.addOrder("Espresso") << endl;
    cout << shop.addOrder("Sandwich") << endl;
    cout << shop.addOrder("Tea") << endl;
    cout << "Total Due: " << shop.dueAmount() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << "Cheapest Item: " << shop.cheapestItem() << endl;

    vector<string> drinks = shop.drinksOnly();
    cout << "Drinks: ";
    for (const auto& drink : drinks) cout << drink << " ";
    cout << endl;

    vector<string> food = shop.foodOnly();
    cout << "Food: ";
    for (const auto& item : food) cout << item << " ";
    cout << endl;

    return 0;
}

