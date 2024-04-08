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
    cout << "\n # of dimes:   ";
    cin  >> coin_d;
    cout << "\n # of nickels: ";
    cin  >> coin_n;
    cout << "\n # of pennies: ";
    cin  >> coin_p;

    //Total value of the users input; casting to double
    total = (coin_q * 0.25 ) + (coin_d * 0.10) + (coin_n * .05) + (coin_p * .01);

    //To separate fractional value for printing
    double init_total = total;
    double total_fractional = (init_total - floor(init_total))*100; //floor(init_total) subtracts whole numbers, multiple fractional by 100 to get our total coinage(cents)

    //Output Statement; casting doubles back to integers
    cout << "The Total is " << int(init_total) << " dollars and " << int(total_fractional) << " cents.\n";

    return 0;
}
