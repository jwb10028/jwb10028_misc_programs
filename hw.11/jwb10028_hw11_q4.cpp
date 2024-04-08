#include <iostream>
using namespace std;

int jump_it(int arr[], int start, int end);
int minimum(int path1, int path2);

int main(){
    int arrSize = 6;
    int arr[arrSize] = {0,3,80,90,57,10};

    int jump = jump_it(arr, 0, arrSize);
    cout << "The lowest cost route is: "<< endl;
    cout << jump;
    
    return 0;
}

int minimum(int path1, int path2){
    if (path1 < path2)
        return path1;
    return path2;
}

int jump_it(int arr[], int start, int end){
    if (start == end - 1){
        return arr[start];
    }
    if (start >= end){
        return arr[end];
    }
    
    int path1 = jump_it(arr, start + 1, end);
    int path2 = jump_it(arr, start + 2, end);

    return arr[start] + minimum(path1,path2);   
}