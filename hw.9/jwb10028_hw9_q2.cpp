#include <iostream>
#include <string>
using namespace std;

bool is_Anagram(string s1, string s2);
void count_forw(string s1, int (&size)[26]);
void count_backw(string s2, int (&size)[26]);

int main(){
    string s1, s2; 
    cout << "Please enter two strings: "<< endl;
    getline(cin, s1);
    getline(cin, s2);

    if (is_Anagram(s1, s2) == true){
        cout << "VALID Anagram.";
    }
    else {
        cout << "INVALID Anagram.";
    }

    return 0;
}

bool is_Anagram(string s1, string s2){
    int sCount[26];
    
    for (int i = 0; i < 26; i++){
        sCount[i] = 0;
    }

    count_forw(s1, sCount);
    count_backw(s2, sCount);
    
    for (int i = 0; i < 26; i++){
        if (sCount[i] != 0){
            return false;
        }
    }

    return true;    
}

void count_forw(string s1, int (&size)[26]){
    for (int i = 0; i < s1.length(); i++){
        if (s1[i] >= 'A' && s1[i] <= 'Z'){
            size[s1[i] - 'A']++;
        }
    }
    for (int i = 0; i < s1.length(); i++){
        if (s1[i] >= 'a' && s1[i] <= 'z'){
            size[s1[i] - 'a']++;
        }
    }
}

void count_backw(string s2, int (&size)[26]){
    for (int i = 0; i < s2.length(); i++){
        if (s2[i] >= 'A' && s2[i] <= 'Z'){
            size[s2[i] - 'A']--;
        }
    }
    for (int i = 0; i < s2.length(); i++){
        if (s2[i] >= 'a' && s2[i] <= 'z'){
            size[s2[i] - 'a']--;
        }
    }
}