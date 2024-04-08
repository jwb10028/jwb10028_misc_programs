//jwb10028
//homework 2
//question 2

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double user_input;
    int m,d,c,l,x,v,i;
    int int_number, sum_of_numerals;

    cout << "Enter decimal number: ";
    cin  >> user_input;

    int_number = (int)user_input;

    m = (int_number / 1000); //0
    d = (int_number % 1000) / 500; //0
    c = (int_number % 500) / 100; //1
    l = (int_number % 100) / 50; //0
    x = (int_number % 50) / 10;//4
    v = (int_number % 10) / 5; //1
    i = (int_number % 5) /1; //2

    sum_of_numerals = m + d + c + l + x + v + i; //8

    cout << user_input << " is ";

    while (sum_of_numerals > 0){
        for (m; m > 0;m--)
            cout << "M";
        for (d; d > 0;d--)
            cout << "D";
        for (c; c > 0;c--)
            cout << "C";
        for (l; l > 0;l--)
            cout << "L";
        for (x; x > 0;x--)
            cout << "X";
        for (v; v > 0;v--)
            cout << "V";
        for (i; i > 0;i--)
            cout << "I";

        sum_of_numerals--;
    }


    return 0;
}