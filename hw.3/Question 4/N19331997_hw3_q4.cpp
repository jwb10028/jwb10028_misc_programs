#include <iostream>

using namespace std;

int main() {
    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;

    double real_number, rounded_value;
    int method;
    

    cout << "Please enter a real number:"<< endl;cin >> real_number;
    cout << "Choose your rounding method: "<< endl;
    cout << "1. Floor round"<<endl;
    cout << "2. Ceiling round"<<endl;
    cout << "3. Round to the nearest whole number"<<endl; cin >> method;
    

    switch (method)
    {
    case FLOOR_ROUND:
        rounded_value = (int)real_number;
        break;
    case CEILING_ROUND:
        rounded_value = (double)((int)(real_number + 0.9));
        break;
    case ROUND:
        rounded_value = (int)(real_number + 0.5);
        break;
    }

    cout << rounded_value << endl;
    
   



    return 0;
}