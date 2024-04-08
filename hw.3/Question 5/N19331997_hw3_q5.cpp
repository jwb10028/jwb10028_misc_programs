#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double weight_lbs, height_inch;
    double weight_klg, height_mtrs;

    cout << "Please enter weight (in pounds): ";cin >> weight_lbs;
    cout << "Please enter height (in inches): ";cin >> height_inch;

    weight_klg = weight_lbs / 2.20462442;
    height_mtrs = height_inch / 39.37007874;

    double BMI = weight_klg / (height_mtrs * height_mtrs);

    if (BMI < 18.5)
        cout << "The weight status is: Underweight";
    else if ( BMI >= 18.5 && BMI < 25)
        cout << "The weight status is: Normal";
    else if (BMI >= 25 && BMI < 30)
        cout << "The weight status is: Overweight";
    else if (BMI >= 30)
        cout << "The weight status is: Obese";

    return 0;
}