#include <iostream>
#include <string>
using namespace std;

string check_digits(string in_s);
bool all_digit_word(string in_s, int s, int e);

int main(){
    string user_input;
    cout << "Please enter a line of text: "<<endl;
    getline(cin, user_input);

    string check = check_digits(user_input);
    cout << check << endl;

    return 0;
}

bool all_digit_word(string in_s, int s, int e){
    for (int i = s; i < e; i++){
        if (in_s[i] >= '0' && in_s[i] <= '9')
            return true;
        else
            return false;
    }
}

string check_digits(string in_s){
    int s = 0; int e; bool check_word;
    for (int i = 0; i <= in_s.length(); i++) {
        e = i;
        if (in_s[i] == ' '){
            check_word = all_digit_word(in_s, s, e);
            if (check_word == true){
                for (int j = s; j < e; j++){
                    in_s[j] = 'x';
                }
            }
            s = i + 1;
        }    
    }
    check_word = all_digit_word(in_s, s, in_s.length());
    if (check_word == true){
        for (int j = s; j < e; j++){
            in_s[j] = 'x';
        }
    } 
    return in_s;
}
