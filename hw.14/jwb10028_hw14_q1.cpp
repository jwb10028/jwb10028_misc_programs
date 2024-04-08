#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class item>
vector<item> findMinMax(vector<item>& input, int start, int end){   
    int size = input.size();
    if (size == 0){
        cout << "Invalid Entry. Vector Empty.";
        exit(1);
    }
    vector<item> result(2);
    if (start == end){
        result[0] = input[start];
        result[1] = input[start];
    } else if (start + 1 == end) {  
        //single comparison
        if (input[end] < input[start]){
            result[0] = input[end];
            result[1] = input[start];
        } else {
            result[0] = input[start];
            result[1] = input[end];
        }
    } else {
        int mid = (start + end) / 2;
        vector<item> firstHalf = findMinMax(input, start, mid);
        vector<item> secondHalf = findMinMax(input, mid+1, end);
        //first comparison
        if (secondHalf[0] < firstHalf[0]){
            result[0] = secondHalf[0];
        } else {
            result[0] = firstHalf[0];
        }
        //second comparison
        if (firstHalf[1] < secondHalf[1]){
            result[1] = secondHalf[1];
        } else {
            result[1] = firstHalf[1];
        }
    }
    return result;
}

template <class item>
vector<item> findMinMax(vector<item>& input){
    int end = input.size() - 1; int start = 0;
    return findMinMax(input, start, end);
}

int main(){
    //Input Vectors:
    vector<char> char_item = {'a','x','z','b'};
    vector<double> double_item = {2.10, 123.45, 13.2, 50.5};
    vector<int> int_item = {99, 52, 127, 2};
    vector<string> string_item = {"1234", "1111", "1561", "1645"};
    
    //Result Vectors:
    vector<string> s_result = findMinMax(string_item);
    vector<char> c_result = findMinMax(char_item);
    vector<int> i_result = findMinMax(int_item);
    vector<double> d_result = findMinMax(double_item);

    cout << "Minimums: \n";
    cout << s_result[0] << endl;
    cout << c_result[0] << endl;
    cout << i_result[0] << endl;
    cout << d_result[0] << endl;

    cout << "Maximums: \n";
    cout << s_result[1] << endl;
    cout << c_result[1] << endl;
    cout << i_result[1] << endl;
    cout << d_result[1] << endl;
  
    return 0;
}
