#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main(){
    int arrSize = 4;
    int arr[arrSize] = {2,-1,3,10};
    
    int sum_of_squares = sumOfSquares(arr, arrSize);

    cout << "Sum of Squares: "<< endl;
    cout << sum_of_squares << endl;

    bool sorted = isSorted(arr, arrSize);

    cout << "Is Array Sorted in ascending order?"<< endl;
    if (sorted == true){
        cout << "YES."<< endl;
    }
    else{
        cout << "NO."<< endl;
    }

    return 0;
}

int sumOfSquares(int arr[], int arrSize){
    if (arrSize <= 0){
        return 0;
    }
    else {
        int temp = sumOfSquares(arr, arrSize - 1);
        return temp + (arr[arrSize - 1] * arr[arrSize - 1]);
    }
}

bool isSorted(int arr[], int arrSize){
    if (arrSize == 1){
        return true;
    }

    if (arr[arrSize-1] < arr[arrSize-2]){
        return false;
    }

    return isSorted(arr, arrSize - 1);
}