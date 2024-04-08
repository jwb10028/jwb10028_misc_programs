#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(4);
    
    //section a
    cout << "section a" << endl; 

    double geo_mean;
    int length, i, seq_value, seq_product=1;

    cout << "Please enter the length of the sequence: \n";
    cin  >> length;
    cout << "Please enter your sequence: \n";

    
    for (i = 0; i < length; i++){
        cin >> seq_value;
        seq_product *= seq_value;
    }

    geo_mean = pow(seq_product, (double)1/length);
    cout << "The Geomteric mean is: "<< geo_mean << endl;

    
    //section b
    cout << "\n" << "section b" << endl; 

    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1: \n";
    
    length = 0;
    seq_product = 1;

    while (seq_value != -1) {     
        cin >> seq_value;
        
        if (seq_value == -1)
            continue;
        
        seq_product *= seq_value;
        length++;   
    }

    geo_mean = pow(seq_product, (double)1/(length));
    cout << "The Geomteric mean is: "<< geo_mean << endl;


    return 0;
}