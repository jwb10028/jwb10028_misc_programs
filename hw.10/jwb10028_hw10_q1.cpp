#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);

int main(){
    int outWordsArrSize; string sentence;
    cout << "Please enter a string of text: "<< endl;
    getline(cin, sentence);

    string* stringArray = createWordsArray(sentence, outWordsArrSize);

    cout << "New Size: "<<outWordsArrSize<<endl;
    cout << "[ ";
    for (int i = 0; i < outWordsArrSize; i++){
        cout << "'" << stringArray[i] << "'";
        if (i != outWordsArrSize - 1){
            cout << " , ";
        }
    }
    cout << " ]";
    delete [] stringArray;
   
    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize){
    string* stringArray = new string[1]; string word;
    int wordCount = 0; int capacity = 1; int j = 0;

    for (int i = sentence.length(); i >= 0; i--){
        if (sentence[j] == ' ' || sentence[j] == '\0'){
            if(wordCount > 0){
                string* wordArr = new string[capacity*2];
                for (int i = 0; i < wordCount; i++){
                    wordArr[i] = stringArray[i];
                }
                delete [] stringArray;
                stringArray = wordArr;
                capacity *= 2;
            }
            stringArray[wordCount] = word;
            wordCount++;

            word = "";
        }
        else {
            word += sentence[j];
        }
        j++;
    }

    outWordsArrSize = wordCount;
    
    return stringArray;
}
