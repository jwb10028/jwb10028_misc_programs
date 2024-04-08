#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main() {
    cout << "Please enter a word, we will see if it is a palindrome:"<< endl;
    string str;
    cin >> str;

    bool pal = isPalindrome(str);
    if (pal == 1){
        cout << str << " is a palindrome.";
    }
    else {
        cout << str << " is not a palindrome.";
    }
    
    return 0;
}

bool isPalindrome(string str){
    string rev_string = "";

    for(int i = str.length() - 1; i >= 0; i--){
        rev_string += str[i];
    }
  
    if(rev_string == str)
        return true;
    else
        return false;
}
