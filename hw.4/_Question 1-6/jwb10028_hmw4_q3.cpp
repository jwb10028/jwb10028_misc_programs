#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double user_input;
    int i, n, binary_num,remainder;
    

    cout << "Enter decimal number: "<<endl;
    cin >> user_input; 

    binary_num = 0;
    n = int(user_input);   
    
    for (i = 1; n != 0; i=i*10) {
        remainder = n%2;
        n = n/2;
        binary_num = binary_num + (remainder * i); 
    }
    
    cout << "The binary representation of "<< user_input << " is " << binary_num << endl;







    return 0;
}
