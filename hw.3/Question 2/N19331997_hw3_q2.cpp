#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    string name;
    int year_grad, year_pres;

    cout << "Please enter your name: "; cin >> name;
    cout << "Please enter your graduation year: "; cin >> year_grad;
    cout << "Please enter your current year: "; cin >> year_pres;

    if (year_grad - year_pres > 4)
        cout << "Jessica, you are not in college yet." <<endl;
    else if (year_grad - year_pres == 4)
        cout << "Jessica, you are a Freshmen." << endl;
    else if (year_grad - year_pres == 3)
        cout << "Jessica, you are a Sophomore." << endl;
    else if (year_grad - year_pres == 2)
        cout << "Jessica, you are a Junior." << endl;
    else if (year_grad - year_pres == 1)
        cout << "Jessica, you are a Senior." << endl;
    else if (year_grad - year_pres <= 0)
        cout << "Jessica, you are graduated." << endl;

    
    return 0;
}