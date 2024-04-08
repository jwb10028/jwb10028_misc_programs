#include <iostream>
using namespace std;

double eApprox(int n);
double factorial(int n);

int main(){
    cout.precision(30);

    for (int n = 1; n <= 15; n++)
        cout<<"n = "<<n<<'\t'<<"eApprox( "<<n<<" ) = "<<eApprox(n)<<endl;
    
    return 0;
}

double eApprox(int n){
    double e=1;
    while (n>0){
        e += 1/factorial(n);
        n--;
    }
    return e;
}

double factorial(int n){
    int product = 1;
    while (n > 0){
        product = n * product;
        n--;
    }
    return product;
}