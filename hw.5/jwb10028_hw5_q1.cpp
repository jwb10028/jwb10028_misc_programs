#include <iostream>
using namespace std;

int main() {
    int i, n, s,user_input, input, product;

    cout << "Please enter a positive integer: "<< endl;
    cin  >> user_input;

    for (n = 1; n <= user_input; n++) {
        
        for (i = 1; i <= user_input; i++) {
            product = i * n;
            cout << product;
            
            cout << "\t";    
        } 
        
        cout << "\n";
    }

    return 0;
}