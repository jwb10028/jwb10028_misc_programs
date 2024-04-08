#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    string dow;
    char temp;
    int duration;
    int time_h, time_m;
    double cost;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "Please enter a day of the week:"<<endl;
    cout << "Mo | Tu | We | Th | Fr | Sa | Su"<<endl;
    cin >> dow;
    cout << "Please enter the time of call start (in 24 hour format:)"<<endl;
    cin >> time_h >> temp >> time_m;
    cout << "Please enter the duration of the call in minutes: "<< endl ;
    cin >> duration;

    if (time_h >= 8 || time_h <= 18 && dow != "Sa" || dow != "Su") {
        cost = (double)duration * .4;
        cout << "The total price of the call is: $" << cost << endl;
    }
    else if (time_h < 8 || time_h > 18 && dow != "Sa" || dow != "Su") {
        cost = (double)duration * .25;
        cout << "The total price of the call is: $" << cost << endl;
    }
    else {
        cost = (double)duration * .15;
        cout << "The total price of the call is: $" << cost << endl;
    }
    
    return 0;
}