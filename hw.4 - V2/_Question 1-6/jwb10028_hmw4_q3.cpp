#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int user_input;
    int power_of_two, power;

    cout << "Please enter a decimal number: "<< endl;
    cin  >> user_input;

    power_of_two = 2;
    power = 0;
    while (power_of_two < user_input)
    {
        power_of_two = pow(2, power);
        power++;
    }
    
    if (power_of_two > user_input)
            power_of_two = power_of_two/2;
    
    cout << "The binary representation of " << user_input << " is ";
    
    while (power_of_two > 0) {
        if (user_input/power_of_two == 1) {
            cout << "1";
        }
        else {
            cout << "0";
        }
        
        
        if (user_input > power_of_two)
            user_input = user_input - power_of_two;
        
        power_of_two = power_of_two / 2;   
    }
    
    return 0;
}