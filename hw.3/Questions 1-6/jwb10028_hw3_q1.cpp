#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int price1, price2;
    char clubcard;
    double tax_input;

    cout << "Enter price of first item: "; cin >> price1;
    cout << "Enter price of second item: "; cin >> price2;
    cout << "Does customer have a club card? [Y/N]: "; cin >> clubcard;
    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: "; cin >> tax_input;

    double tax_rate = tax_input * .01;
    double base_price = price1 + price2;
    double total_price;
    double price_after_discount;

    if (clubcard == 'y' || clubcard == 'Y') {
        if (price1 < price2)
            price_after_discount = (price1/2 + price2) - ( (price1/2 + price2) * .1 );
        else
            price_after_discount = (price2/2 + price1) - ( (price2/2 + price1) * .1 );   
    }
    else {
        if (price1 < price2)
            price_after_discount = (price1/2 + price2);
        else
            price_after_discount = (price2/2 + price1);
    }
    
    total_price = (price_after_discount*tax_rate) + price_after_discount;


    cout << "Base price: " << base_price << endl;
    cout << "Price after discounts: " << price_after_discount << endl;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);
    
    cout << "Total price: " << total_price << endl;

    
    return 0;
}