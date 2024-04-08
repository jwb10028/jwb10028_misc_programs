#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;
    
    reverseArray(arr1, arr1Size);
    cout << endl;

    removeOdd(arr2, arr2Size);
    cout << endl;

    splitParity(arr3, arr3Size);
    
    
    return 0;
}
void printArray(int arr[], int arrSize){
    int i;

    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void reverseArray(int arr[], int arrSize){
    for (int ind = arrSize - 1; ind >= 0; ind--){
        cout << arr[ind] << " ";
    }
}
void removeOdd(int arr[], int& arrSize){
    for (int ind = 0; ind < arrSize; ind++){
        if(arr[ind]%2 != 1)
            cout << arr[ind] << " ";
    }
}
void splitParity(int arr[], int arrSize){
    for (int ind = arrSize - 1; ind >=0; ind--){
        if (arr[ind]%2 == 1)
            cout << arr[ind] << " ";
    }
    for (int ind = 0; ind < arrSize; ind++){
        if (arr[ind]%2 == 0)
            cout << arr[ind] << " ";
    }
}