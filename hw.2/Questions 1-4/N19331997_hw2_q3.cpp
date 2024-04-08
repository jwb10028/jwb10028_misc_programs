#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int john_days, john_hours, john_minutes;
    int bill_days, bill_hours, bill_minutes;

    cout << "Please enter the number of days John has worked:";
    cin  >> john_days;
    cout << "Please enter the number of hours John has worked:";
    cin  >> john_hours;
    cout << "Please enter the number of minutes John has worked:";
    cin  >> john_minutes;

    cout << "\n";

    cout << "Please enter the number of days Bill has worked:";
    cin  >> bill_days;
    cout << "Please enter the number of hours Bill has worked:";
    cin  >> bill_hours;
    cout << "Please enter the number of minutes Bill has worked:";
    cin  >> bill_minutes;
    
    int total_days = john_days + bill_days;
    int total_hours = john_hours + bill_hours;
    int total_minutes = john_minutes + bill_minutes;

    if (total_hours >= 24) {
        ++total_days;
        total_hours -= 24;
    }

    if (total_minutes >= 60) {
        ++total_hours;
        total_minutes -= 60;
    }
    
    cout << "\n";
    
    cout << "The total time both of them worked together is: " << total_days << " days, " << total_hours << " hours and " << total_minutes << " minutes.\n";

    return 0;
}