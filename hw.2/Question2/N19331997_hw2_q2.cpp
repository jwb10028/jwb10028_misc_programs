#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int dollars, cents, dollars_to_cents;
    int coin_q, coin_p, coin_d, coin_n;
    
    cout << "Please enter your amount in the format of dollars and cents separated by a space: \n";
    cin  >> dollars;
    cin  >> cents;

    dollars_to_cents = dollars * 100;
    coin_q = (dollars_to_cents/25) + (cents/25);
    coin_d = ((coin_q%25)/10)      + ((cents%25)/10);
    coin_n = ((coin_d%10)/5)       + (((cents%25)%10)/5);
    coin_p = ((coin_n%5)/1)        + ((((cents%25)%10)%5)/1);

    cout << dollars << " dollars and " << cents << " cents are: \n";
    cout << coin_q << " Quarters, " << coin_d << " Dimes, " << coin_n << " Nickels, and " << coin_p << " Pennies.\n";




    return 0;
}