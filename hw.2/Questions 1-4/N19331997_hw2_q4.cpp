#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int num1, num2;

    cout << "Please enter two positive integers, separated by a space:\n";
    cin  >> num1;
    cin  >> num2;

    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;
    double quotient = (double)num1 / num2;
    int div = num1 / num2;
    int mod = num1 % num2;

    cout << num1 << " + " << num2 << " = " << sum << endl;
    cout << num1 << " - " << num2 << " = " << difference << endl;
    cout << num1 << " * " << num2 << " = " << product << endl;
    cout << num1 << " / " << num2 << " = " << quotient << endl;
    cout << num1 << " div " << num2 << " = " << div << endl;
    cout << num1 << " mod " << num2 << " = " << mod << endl;




    return 0;
}