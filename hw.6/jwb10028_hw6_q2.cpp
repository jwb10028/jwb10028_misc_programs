#include <iostream>
using namespace std;
void printShiftedTri(int scale, int shift, char symbol);
void printTree(int n, char symbol);

int main(){
    int scale, shift;
    char symbol1;
    char symbol2;
    cout << "Please enter two integer values (scale, and x shift): "<<endl;
    cin  >> scale;
    cin  >> shift;
    cout << "Please enter a two character symbols: "<<endl;
    cin  >> symbol1;
    cin  >> symbol2; 
    
    printShiftedTri(scale, shift, symbol1);
    cout << "\n";
    printTree(scale, symbol2);
    return 0;
}

void printShiftedTri(int scale, int shift, char symbol){
    int n = scale,s = shift, i, n2; n2 = n-1;
    char x = symbol;
    //shape
    for (i=1; i<=n;i++){
        for (int m=1;m<=s;m++)
            cout << " ";
        for (int z = n2; z>=1; z--)
            cout << " ";
        for(int j=1;j<=2*i-1;j++)
            cout << x;
        n2--;
        cout<<"\n";
    }
    return;
}

void printTree(int scale, char symbol){
    int n = scale+1; char x = symbol;
    int s = scale-1;

    for (int i=2;i<=n;i++){
        
        printShiftedTri(i,s,symbol);
        s--;
    }
}