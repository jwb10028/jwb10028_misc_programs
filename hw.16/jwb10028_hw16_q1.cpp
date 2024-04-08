#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <stack>
#include <sstream>
using namespace std;

bool isExpected(string inStr);
bool isSameType(string open, string close);
bool isClose(string inStr);
bool isOpen(string inStr);
bool isBalanced(vector<string>& inChecks);
void checkCharacters(string inWord, vector<string>& inChecks);
bool checkBalance(ifstream& input_data);
void printResults(ifstream& input_data);
void openInputFile(ifstream& input_data);

int main(){
    ifstream inputFileStream;
    openInputFile(inputFileStream);
    printResults(inputFileStream);
    return 0;
}

bool isExpected(string inStr){
    //these are the characters that we need to make sure are balanced, otherwise ignore
    if (inStr == "(" || inStr == ")"){ return true;}
    if (inStr == "{" || inStr == "}"){ return true;}
    if (inStr == "[" || inStr == "]"){ return true;}
    if (inStr == "begin" || inStr == "end"){ return true;}
    return false;
}

bool isSameType(string open, string close){
    if (open == "("){
        if (close == "]" || close == "}" || close == "end")
            return false;
    } 
    else if (open == "{"){
        if (close == "]" || close == ")" || close == "end")
            return false;
    }  
    else if (open == "["){
        if (close == "}" || close == ")" || close == "end");
            return false;
    } 
    else if (open == "begin"){
        if (close == "]" || close == ")" || close == "}");
            return false;
    }  
    return true;
}

bool isClose(string inStr){
    //if the input string is an close symbol return true, else return false
    if (inStr == ")" || inStr == "}" || inStr == "]" || inStr == "end")
        return true;
    return false;
}

bool isOpen(string inStr){
    //if the input string is an open symbol return true, else return false
    if (inStr == "(" || inStr == "{" || inStr == "[" || inStr == "begin")
        return true;
    return false;
}

bool isBalanced(vector<string>& inChecks){
    //declaring stack to store symbols
    stack<string> inSymbols;
    
    //iterating over every item that needs to be checked for balance
    for (int i = 0; i < inChecks.size(); ++i){
        //checking for open symbols to be pushed onto the stack
        if (isOpen(inChecks[i])){
            inSymbols.push(inChecks[i]);
            continue;
        } 
        else if (isClose(inChecks[i])){
            
            //if the symbols stack is empty we know that no open has been pushed, return false
            if(inSymbols.empty()){
                return false;
            }
                
            //if there is an open we continue, and check to see if it is the same symbol at the head of the stack
            string opening = inSymbols.top();
            inSymbols.pop();

            //if not the same, return false
            if(isSameType(inChecks[i], opening) == false){
                return false;
            }
                
        }
    } 

    return inSymbols.empty();    
}

void checkCharacters(string inWord, vector<string>& inChecks){
    int i = 0;
    while (i < inWord.size()){
        string temp =  "";
        temp += inWord[i];

        if (isExpected(temp)){
            inChecks.push_back(temp);
        } 
        
        i++;
    }
}

bool checkBalance(ifstream& input_data){
    //declaring vector for string storage
    vector<string> inChecks;
    //temp string to store for input
    string input_line;

    //reading from file line by line
    while (getline(input_data, input_line)) {
        
        //storing 'word' string up to space character ' '
        stringstream wordStream(input_line);
        //temp string for word input
        string input_word;
        
        while (wordStream >> input_word){
            
            if (isExpected(input_word)){
                inChecks.push_back(input_word);
            } else {

                checkCharacters(input_word, inChecks);
            }   
        }
    }

    return isBalanced(inChecks);
}

void printResults(ifstream& input_data){
    if (checkBalance(input_data)){
        cout << "The pascal program is balanced.";
    } else {
        cout << "The pascal program is not balanced";
    }
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