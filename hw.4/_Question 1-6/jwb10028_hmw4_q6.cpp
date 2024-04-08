#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, i, remainder, print_num, odd_count, even_count;

    cout << "Please enter a positive integer: "<< endl;
    cin  >> n;

    for (i = 1; i <= n; i++) {
        print_num = i;
        odd_count = 0;
        even_count = 0;

        while (i != 0) {
            remainder = i % 10;

            if(remainder % 2 == 1) 
                odd_count++;
            else if (remainder % 2 == 0)
                even_count++;
            
            i = i / 10;
        }
        
        i = print_num;

        if (even_count > odd_count)
            cout << print_num << endl;
        
    }

    
    return 0;
}