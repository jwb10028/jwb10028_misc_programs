#include <iostream>
#include <cmath>
using namespace std;

int main() {
    //Declaring Variables
    int coin_q;
    int coin_d;
    int coin_n;
    int coin_p;
    double total;

    //Initial User Input
    cout << "Please enter number of coins: \n";
    cout << "# of quarters: ";
    cin  >> coin_q;
    cout << "# of dimes: ";
    cin  >> coin_d;
    cout << "# of nickels: ";
    cin  >> coin_n;
    cout << "# of pennies: ";
    cin  >> coin_p;

    //Total value of the users input; casting to double
    total = (coin_q * 0.25 ) + (coin_d * 0.10) + (coin_n * .05) + (coin_p * .01);

    //To separate fractional value for printing
    double init_total = total;
    double total_fractional = ((double)init_total - (int)init_total)*100;

    //Output Statement; casting doubles back to integers
    cout << "The Total is " << int(init_total) << " dollars and " << int(total_fractional) << " cents\n";

    return 0;
}
