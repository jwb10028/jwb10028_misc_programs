#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void printMenu(int arr[], int arr2[]);
void randomArr(int arr[]);
bool checkValidity(int arr[], int arr2[], int arr3[]);

int main(){
    int PIN[] = {1,2,3,4,5};
    int pinMenu[10] = {0,1,2,3,4,5,6,7,8,9};
    int pinKey[10];
    int inputArr[5];
    int user_input;
    int input_count = 0;
    randomArr(pinKey); //random array

    cout << "Please enter your 5-Digit PIN according to the following mapping:"<<endl;
    printMenu(pinMenu, pinKey);

    //user input
    cout << "Enter:" <<endl;
    cin  >> user_input;

    //storing input in 5 element array
    for (int i = 4; i >= 0; i--){
        inputArr[i] = user_input%10;
        user_input = user_input/10;
        input_count++;
    }

    
    //final validity check
    bool valid = checkValidity(inputArr, PIN, pinKey);
    if (valid == true && input_count <= 5){
        cout << "Your PIN is Correct.";
    }
    else {
        cout << "Your PIN is Incorrect.";
    }
    return 0;
}

void printMenu(int arr[], int arr2[]){
    cout << "PIN: ";
    for (int i = 0; i < 10; i++){
        cout << arr[i]<< " ";
    }
    cout <<endl<<"NUM: ";
    for (int i = 0; i < 10; i++){
        cout << arr2[i]<< " ";
    }
    cout << endl;
}
void randomArr(int arr[]){
    srand(time(0));
    for (int i = 0; i < 10; i++){
        arr[i] = (int)(rand() % 3) + 1;
    }
}
bool checkValidity(int arr[], int arr2[], int arr3[]){
    int count = 0;
    for (int i = 0; i < 5; i++){
        if (arr[i] != arr3[arr2[i]])
            count=0;
        else
            count=1;
    }
    if (count == 1)
        return true;
    else
        return false;
}