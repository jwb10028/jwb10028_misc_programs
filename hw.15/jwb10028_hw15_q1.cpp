#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

//extra helper functions:
void openInputFile(ifstream& input_data);


struct customer{
    string name;
    double amntPaid;
};
class Node {
    double amountPaid;
    double amountOwed;
    string name;
    Node* next;
public: 
    Node(){
        this->amountPaid = 0.00;
        this->amountOwed = 0.00;
        this->name = "0";
        this->next = nullptr;
    }
    Node(double amntPaid, string newName, Node* next = nullptr){
        this->amountPaid = amntPaid;
        this->amountOwed = 0.00;
        this->name = newName;
        this->next = next;
    }
    Node(double amntPaid, string newName, double amntOwed){
        this->amountPaid = amntPaid;
        this->amountOwed = amntOwed;
        this->name = newName;
        this->next = nullptr;
    }

    //returns amount paid
    double getPaid(){return this->amountPaid;}
    //returns amount owed
    double getOwed(){return this->amountOwed;}
    //set amount owed
    void setOwed(double inOwed){this->amountOwed = inOwed;}
    //set amount paid
    void setPaid(double inPaid){this->amountPaid = inPaid;}
    //set name
    void setName(string inName){this->name = inName;}
    //returns node name
    string getName(){return this->name;}
    //returns pointer to next item in list
    Node* getNext(){return this->next;}
    //sets list pointer
    void setNext(Node* newNext){this->next = newNext;}
};
class LList {
    Node* head;
public:
    //constructor
    LList(){ this->head = nullptr;}
    //destructor
    ~LList(){ while(this->head != nullptr) pop_back();}
    //Insertion Operator <<
    friend ostream& operator<<(ostream& outs, const LList& rhs);
    //Add Links (push_back)
    void push_back(double inputPaid, string inputName);
    //Remove Links (pop_back)
    Node pop_back();
    //Find Length
    int getLength();
    //returns true if empty
    bool isEmpty() const {return (this->head == NULL);}

    //extra class functions
    double getPayouts();
    void printResults(double target);
};

int main() {
    
    //opening file
    ifstream input_data;
    openInputFile(input_data);
    //storing file data in linked list
    LList list; customer temp;
    while (input_data >> temp.amntPaid){
        input_data.ignore(9999, ' ');
        getline(input_data, temp.name);
        list.push_back(temp.amntPaid, temp.name);
    }
    input_data.close();
    
    //printing results
    double target = list.getPayouts();
    list.printResults(target);
    
    return 0;
}

void LList::push_back(double inputPaid, string inputName){
    Node* addNode = new Node(inputPaid, inputName);
    addNode->setNext(head);
    head = addNode;   
    //this->head = new Node(inputPaid, inputName, this->head);
}
Node LList::pop_back(){
    double aPaid, aOwed; string name;
    aPaid = this->head->getPaid();
    aOwed = this->head->getOwed();
    name = this->head->getName();
    Node resNode(aPaid, name, aOwed);
    Node* trashNode = this->head;
    this->head = this->head->getNext();
    delete trashNode;
    return resNode;
}
ostream& operator<<(ostream& outs, const LList& rhs){
            outs.setf(ios::fixed);
            outs.setf(ios::showpoint);
            outs.precision(2);
            
            Node* currNode = rhs.head;
            while(currNode != nullptr){
                outs << "Name: ";
                outs << currNode->getName() << endl;
                outs << "Amount Paid: ";
                outs << currNode->getPaid() << endl;
                outs << "Amount Owe(d)(s): ";
                outs << currNode->getOwed() << endl;
                //outs << "List ID Number: ";
                //outs << currNode->getID();
                outs << endl << endl;

                currNode = currNode->getNext();
            }
    }
int LList::getLength(){
    int count = 0;
    Node *currNode = this->head;
    while (currNode != nullptr)
    {
        count++;
        currNode = currNode->getNext();
    }
    return count;
}
double LList::getPayouts(){
    Node* currNode = head;

    double cAmount = 0.0;
    int gCount = 0;

    while (currNode != nullptr){
        cAmount += currNode->getPaid();
        gCount++;
        currNode = currNode->getNext();
    }

    double targetValue = cAmount / (double)gCount;
    currNode = head;

    while(currNode != nullptr){
        if (currNode->getPaid() < targetValue){
            double temp = targetValue - currNode->getPaid();
            currNode->setOwed(temp);
        }

        else if (currNode->getPaid() > targetValue){
            double temp = currNode->getPaid() - targetValue;
            currNode->setOwed(temp);
        }

        currNode = currNode->getNext();
    }
    double returnTarg = targetValue;
    return returnTarg;
}
void LList::printResults(double target){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    Node* onNode = head;

    //loop to find those on target
    while (onNode != nullptr){
        double currOwed = onNode->getOwed();
        if (currOwed == 0){
            cout << onNode->getName() << ", you don't need to do anything" << endl;;
        }
        onNode = onNode->getNext();
    }

    //loop to find those owed
    Node* currNode = head;
    while (currNode != nullptr){
        if (currNode->getOwed() > 0 && currNode->getPaid() < target){
            cout << currNode->getName() << ", you give ";

            Node* personOwed = head;
            while (personOwed != nullptr){
                if (personOwed->getOwed() > 0 && personOwed != currNode && personOwed->getPaid() > target){
                    double diff = personOwed->getOwed() - target;

                    if (personOwed->getOwed() > target){
                        
                        personOwed->setOwed(personOwed->getOwed() - diff );
                    }
                    
                    cout << personOwed->getName() << " $" << personOwed->getOwed()<<endl;
                            
                    personOwed->setOwed(0.0);
                    currNode->setOwed(0.0);

                    break;        
                }
               
                personOwed = personOwed->getNext();
            }
        }
        
        currNode = currNode->getNext();
    }
    
    cout << endl;
    cout << "In the end, you all should have spent around $"<<target;
}
void openInputFile(ifstream& input_data){
    string fileName;
    cout << "Enter file name: \n";
    cin >> fileName;
    cout << "Editing file: " << fileName;
    
    input_data.open(fileName);

    while(!input_data){
        cout << "FAILED TO OPEN INPUT" << endl;
        cout << "Enter file name: ";
        cin >> fileName;
        input_data.clear();
        input_data.open(fileName);
    }

    cout << endl << endl;
}