#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, i;
    int pos_int;

    cout << "Please enter a positive integer: ";
    cin  >> n;

    
    cout << "section a"<< endl; //section a
    
    i=1;
    while (i <= n) {
        pos_int = 2 * i;
        cout << pos_int << "\n";
        i = i + 1;
    }
    
    cout << "\n";
    cout << "section b"<< endl; //section b

    for (i=1; i <= n; i++) {
        pos_int = 2 * i;
        cout << pos_int << "\n";
    }



    return 0;
}