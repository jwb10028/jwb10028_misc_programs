#include <iostream>
using namespace std;

int minInArray(int arr[], int arrSize);

int main() {
    int arrSize = 20;
    int arr[20];
    int currNum;

    cout << "Please enter 20 integers separated by a space: "<< endl;
    for (int ind = 0; ind < arrSize; ind++){
        cin >> currNum;
        arr[ind] = currNum;
    } 
    
    int min = minInArray(arr, arrSize);
    cout << "The minimum value is: " << min;
    
    cout << " and it is located in the following indices: ";
    for(int ind = 0; ind < arrSize; ind++){
        if(arr[ind] == min)
            cout << ind << " ";
    }

    
    return 0;
}

int minInArray(int arr[], int arrSize){
    int min = arr[0];
    
    for (int ind = 0; ind < arrSize; ind++){
        if (arr[ind] < min)
            min = arr[ind];
    }    
    return min;
}
