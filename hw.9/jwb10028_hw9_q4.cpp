#include <iostream>
using namespace std;

int* oddsKeepEvensFlip(int* arr, int arrSize);

int main() {
    int arrSize;
    cout << "Please enter Array Size: "<<endl;
    cin  >> arrSize;
    
    int arr[arrSize];
    cout << "Please enter Array elements separated by a space, press enter when done: "<<endl;
    for (int i = 0; i < arrSize; i++){
        cin >> arr[i];
    }
    int* flippedArray;

    cout << "Odds Keep, Even Flip: "<<endl;
    flippedArray = oddsKeepEvensFlip(arr, arrSize);
    for (int i = 0; i < arrSize; i++){
        cout << flippedArray[i] << " ";
    }
    
    return 0;
}

int* oddsKeepEvensFlip(int* arr, int arrSize){
    int* tempArr = new int[arrSize]; int c = 0;

    for (int i = 0; i < arrSize; i++){
        if (arr[i]%2 == 1){
            tempArr[c++] = arr[i];
        }    
    }
    
    
    for (int i = arrSize - 1; i >= 0; i--){
        if(arr[i]%2 == 0){
            tempArr[c++] = arr[i];
        }
    }
    
    for (int i = 0; i < arrSize; i++){
        arr[i] = tempArr[i];
    }
    
    delete [] tempArr;
    return arr;
}