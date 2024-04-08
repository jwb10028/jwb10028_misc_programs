#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    
    double a,b,c;
    double discriptant;

    cout << "Please enter value of a: ";cin >> a;
    cout << "Please enter value of b: ";cin >> b;
    cout << "Please enter value of c: ";cin >> c;

    discriptant = pow(b,2) - 4 * a * c;

    if (a != 0 && b == 0 && c != 0)
        cout << "This equation has no real solutions." << endl;
    else if (a == 0 && b == 0 && c == 0)
        cout << "This equation has infinite solutions." << endl;
    else if (a == 0 && b == 0 && c != 0)
        cout << "This equation has no solution." << endl;
    else if (discriptant == 0) {
        double x = -b/(2*a);
        cout << "This equation has a single real solution. x = " << x << endl; 
    }
    else if (discriptant < 0) {
        discriptant = discriptant * -1;
        discriptant = sqrt(discriptant);
        double real_sol = -b/(2*a);
        double complex_sol = discriptant/(2*a);
        cout << "This equation has two real and complex solutions. x1 = " << real_sol << " x2 = " << complex_sol;
    }
    else {
        discriptant = sqrt(discriptant);
        double real1, real2;
        real1=(-b + discriptant)/(2*a);
        real2=(-b - discriptant)/(2*a);
        cout << "This equation has two real solutions. x1 = " << real1 << " x2 = " << real2;
    }
    


    return 0;
}