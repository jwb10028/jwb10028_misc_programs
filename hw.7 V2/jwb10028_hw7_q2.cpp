#include <iostream>
#include <cmath>
using namespace std;

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main(){
    int sum = 0; int count = 0; int m;
    cout << "Please enter a positive integer that is >= 2: "<<endl;
    cin  >> m;

    cout << "Perfect Numbers from 2 to "<< m << ": "<<endl;
    for (int i = 2; i <= m; i++){
        bool perf = isPerfect(i);

        if (perf == true && i != 1){
            cout << i << endl;
        }
    }

    cout << endl;
    cout << "Amicable Pairs from 2 to "<< m << ": "<<endl;
    for (int i = 2; i <= m; i++){
        int s = 0; int c = 0; int s2 = 0;
        analyzeDivisors(i, c, s);
        if ((i<s) && (s <= m))
            analyzeDivisors(s, c, s2);

        if (s2 == i) {
            cout << i << "\t|\t" << s << endl;
        }
    }
    
    return 0;
}

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs){
        int n = num; int s = 0; int c = 0;

        for (int i = 1; i <= sqrt(n); i++){
            if (n < 2){
                c = 1;
                s = 1;
            }
            if (n%i == 0 && n >= 2){
                
                s = i + s;
                c++;
            }
        }
        for (int i = sqrt(n); i >= 1; i--){
            if (n%i == 0 && n >= 2){
                if(n/i == n)
                    break;
                
                s = (n/i) + s;
                c++;
            }
        }
        outSumDivs = s;
        outCountDivs = c;
}

bool isPerfect(int num){
    int n = num; int s = 0; int c = 0;
    analyzeDivisors(n , c , s);

    if (s == n)
        return true;
    else
        return false;
}