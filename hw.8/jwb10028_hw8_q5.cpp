#include <iostream>
#include <string>
using namespace std;

int main(){
    string first_n;
    string middle_n;
    string last_n;
    
    cout << "Please input a name in the format (first name, middle name/initial, last name):"<<endl;
    cin  >> first_n >> middle_n >> last_n;
    cout << endl;
    cout << last_n <<", "<< first_n <<" "<< middle_n.substr(0,1)<<".";
    
    return 0;
}