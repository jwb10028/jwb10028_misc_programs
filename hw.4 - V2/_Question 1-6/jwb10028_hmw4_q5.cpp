#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int i, n, s, j;

    cout << "Enter number of rows:";
    cin  >> n;

    for (i = n; i >= 1;i--){
        for (s = n - i; s > 0; s--)
            cout << " ";
        
        for (j = 2 * i - 1; j > 0; j--)
            cout << "*";

        cout << "\n";

    }

    for (i = 1; i <= n; i++) {
        for (s = n - i;s > 0; s--)
            cout<<" ";
        for (j = 1; j <= 2 * i - 1; j++)
            cout << "*";

        cout << "\n";
    }

    return 0;
}