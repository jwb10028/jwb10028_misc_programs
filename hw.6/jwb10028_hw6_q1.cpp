#include <iostream>
using namespace std;

int fib(int n);

int main() {
    int user_input, n;
    cout << "Please enter a positive integer: ";
    cin >> user_input;
    n = fib(user_input);
    cout <<"The "<<user_input<<"th Element of the Fibonacci Sequence is: "<< n;
    return 0;
}

int fib(int n){
    int fib_n, i;
    int f0=0, f1=1, f2;  
    if (n == 0)
        return f0;
    for (i = 2; i<=n; i++){
        f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
    }
    fib_n = f1;
    return fib_n;
}