#include <iostream>
#include <string>
using namespace std;

const int alpha_len = 26;
void word_count(string s, int size);

int main(){
    string user_input;
    cout << "Please enter a line of text: "<< endl;
    getline(cin , user_input);

    word_count(user_input, (int)user_input.length());
    return 0;
}

void word_count(string s, int size){
    int word_count = 0; int char_count[26] = {0};
    for (int i = 0; i < s.length(); i++){
        if (s[i] == ' '){
            word_count++;
        }
        if (s[i] >= 'a' && s[i] <= 'z'){
            char_count[s[i] - 'a']++;
        }
        if (s[i] >= 'A' && s[i] <= 'Z'){
            char_count[s[i] - 'A']++;
        }
    }
    word_count++;
    cout << word_count << " " << "words" << endl;
    
    for (int i = 0; i < alpha_len; i++){
        if (char_count[i] > 0){
            cout << char_count[i] << " " << (char)('a' + i) << endl;
        }
    }
}

