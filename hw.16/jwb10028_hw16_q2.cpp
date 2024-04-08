#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <class T>
class Queue {
    vector<T> data;
    int start;
public:
    Queue(){data.clear(); start = 0;}
    
    void enqueue(T newItem){data.push_back(newItem);}
    
    T dequeue(){start++; if(start >= data.size()){data.resize(0); start = 0;}}
    
    T top(){return data[start];}

    T bottom(){return data[data.size() - 1];}
  
    bool isEmpty()const{return start == data.size();}
    
    int size()const{return data.size()-start;}
    
    void clear(){data.clear(); start = 0;}
    
};

int main(){
    
    
    return 0;
}


