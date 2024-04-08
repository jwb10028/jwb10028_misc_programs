
#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);


int main(){
    
    int arrSize;
    cout << "Please enter Array size: "<< endl;
    cin  >> arrSize;
    cout << "Please enter elements of the array separated by a space, press enter when done: "<<endl;
    
    int* arr; 
    arr = new int[arrSize];

    for (int i = 0; i < arrSize; i++){
        cin >> arr[i];
    }
    int outPosArrSize;
    int* outPosArr;

    cout << "Function 1:"<< endl;
    outPosArr = getPosNums1(arr, arrSize, outPosArrSize);
    for (int i = 0; i < outPosArrSize; i++){
        cout << outPosArr[i]<< " " << endl;
    }
    delete [] outPosArr;
    cout << "Function 2:"<< endl;
    outPosArr = getPosNums2(arr, arrSize, &outPosArrSize);
    for (int i = 0; i < outPosArrSize; i++){
        cout << outPosArr[i]<< " " << endl;
    }
    delete [] outPosArr;
    cout << "Function 3:"<< endl;
    getPosNums3(arr, arrSize, outPosArr, outPosArrSize);
    for (int i = 0; i < outPosArrSize; i++){
        cout << outPosArr[i]<< " " << endl;
    }
    delete [] outPosArr;
    cout << "Function 4:"<< endl;
    getPosNums4(arr, arrSize, &outPosArr, &outPosArrSize);
    for (int i = 0; i < outPosArrSize; i++){
        cout << outPosArr[i]<< " " << endl;
    }
    delete [] outPosArr;
    delete [] arr;
    
    
    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    outPosArrSize = 0;

    for (int i = 0; i < arrSize; i++){
        if ( arr[i] > 0)
            outPosArrSize++;
    }

    int* posArr = new int[outPosArrSize];
    int c = 0;
    
    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            posArr[c++] = arr[i];   
        }
    }
    return posArr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
    (*outPosArrSizePtr) = 0;

    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0)
            (*outPosArrSizePtr)++;
    }

    int *posArr = new int[(*outPosArrSizePtr)];
    int c = 0;

    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            posArr[c++] = arr[i];
        }
    }
    return posArr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
    outPosArrSize = 0;
    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0)
            outPosArrSize++;
    }

    outPosArr = new int[outPosArrSize];
    int c = 0;

    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            outPosArr[c++] = arr[i];
        }
    }
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    (*outPosArrSizePtr) = 0;

    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0)
            (*outPosArrSizePtr)++;
    }

    (*outPosArrPtr) = new int [(*outPosArrSizePtr)];
    int c = 0;

    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            (*outPosArrPtr)[c++] = arr[i];
        }
    }
}