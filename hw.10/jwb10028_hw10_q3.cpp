#include <iostream>
#include <vector>
using namespace std;

int main1();
int main2();
int* inputArray(int& inputArraySize);
vector<int> inputVec();
void searchInt(int* inArr, int inArraySize, int search_value);
void searchIntVector(vector<int> inputVec, int search_value);

int main(){    
    main1();
    //main2();
    return 0;
}

int main1(){
    int search_value; int inputArraySize;

    int* inArray = inputArray(inputArraySize);
    cout << "Please enter the number you want to search: "<< endl;
    cin  >> search_value;

    searchInt(inArray, inputArraySize, search_value); 
    
    delete [] inArray;
    return 0;
}

int main2(){
    int search_value;

    vector<int> inVec = inputVec();
    cout << "Please enter the number you want to search: "<< endl;
    cin  >> search_value;

    searchIntVector(inVec, search_value);

    return 0;
}

int* inputArray(int& inputArraySize){
    int* inArray = new int[1]; 
    int inArraySize = 0; int capacity = 1; int currNum;

    cout << "Please enter a sequence of positive integers, each in a separate line. End your input by typing -1:"<<endl;

    while (currNum != -1){
        cin >> currNum;
        if (inArraySize == capacity){
            int* newArr = new int[2*capacity];
            for (int i = 0; i < inArraySize; i++){
                newArr[i] = inArray[i];
            }
            delete [] inArray;
            inArray = newArr;
            capacity *= 2;
        }
        inArray[inArraySize] = currNum;
        inArraySize++;
    }
    inputArraySize = inArraySize;
    return inArray;
}

void searchInt(int* inArr, int inArraySize, int search_value){
        int* foundIndex = new int[inArraySize];

        cout << search_value << " appears in lines";
        for (int i = 0; i < inArraySize; i++){
            if (inArr[i] == search_value){
                if (i == 0){
                    cout << " " << i+1;
                }
                else {
                    cout << ", " << i+1;
                }
            }
        }
        cout << ".";
}

vector<int> inputVec(){
    vector<int> inputVec; int currNum;

    cout << "Please enter a sequence of positive integers, each in a separate line. End your input by typing -1:"<<endl;

    while (currNum != -1){
        cin >> currNum;
        inputVec.push_back(currNum);
    }

    return inputVec;
}

void searchIntVector(vector<int> inputVec, int search_value){
    cout << search_value << " appears in lines";
    for (int i = 0; i < inputVec.size(); i++){
        if (inputVec[i] == search_value){
            if (i == 0)
                cout << " " << i+1;
            else {
                cout << ", " << i+1;
            }
        }
    }
    cout << ".";
}