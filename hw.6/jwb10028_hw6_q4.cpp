#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num);

int main(){
    int n;
    cout << "Please enter a positive integer >= 2: "<<endl;
    cin  >> n;
    printDivisors(n); 
    return 0;
}

void printDivisors(int num){
    for (int i = 1;i <= sqrt(num); i++){
        if (num%i == 0 && num>=2){
            cout << i;
            cout << " ";
        }
        else if (num < 2)
            cout << "1";  
    }
    for(int i = sqrt(num);i >= 1; i--){
        if (num%i == 0 && num >= 2 && i*i != num) {
            cout << num/i;
            cout << " ";
        }   
    }
}