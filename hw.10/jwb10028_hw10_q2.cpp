#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main(){
    int n = 6;
    int arr[n] = {3,1,3,0,6,4};
    int resArrSize;

    int* fM = findMissing(arr, n, resArrSize);

    cout << "New Size: " << resArrSize << endl;
    
    for (int i = 0; i < resArrSize; i++){
        cout << fM[i] << " ";
    }

    delete [] fM;
    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize){
    int* temp = new int[n];
    for (int i = 0; i < n; i++){
        temp[i] = i;
    }

    int newArrSize = n;
    for (int i = 0; i < n; i++){
        if (arr[i] < n){
            if (temp[arr[i]] != -1){
                temp[arr[i]] = -1;
                newArrSize--;
            }
        }
    }
    
    
    int* missingArr = new int[newArrSize];
    int j = 0;

    for (int i = 0; i < n; i++){
        if (temp[i] != -1){
            missingArr[j] = temp[i];
            j++;
        }
    }

    delete [] temp;
    resArrSize = newArrSize;
    return missingArr;
}