#include <iostream>
using namespace std;

void printTriangle (int n);
void printOppositeTriangles(int n);
void printRuler(int n);

int main(){
    
    cout << "Function 1: "<< endl;
    printTriangle(4);
    cout << "Function 2: "<< endl;
    printOppositeTriangles(4);
    cout << "Function 3: "<< endl;
    printRuler(4);

    return 0;
}

void printTriangle(int n){
    if (n - 1 > 0){
        printTriangle(n - 1);
    }
    for (int i = 0; i < n; i++){
        cout << "*";
    }
    cout << endl;

}

void printOppositeTriangles(int n){

    for (int i = 0; i < n; i++){
        cout << "*";
    }
    cout << endl;

    if (n - 1 > 0){
        printOppositeTriangles(n-1);
    }

    for (int i = 0; i < n; i++){
        cout << "*";
    }
    cout << endl;
}

void printRuler(int n){
    

    if (n - 1 > 0){
        printRuler(n - 1);
    }
    for (int i = 0; i < n; i++){
        cout << "-";
    }
    cout << endl;
    if (n - 1 > 0){
        printRuler(n - 1);
    }
    
    
}