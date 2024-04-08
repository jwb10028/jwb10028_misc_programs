#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int user_guess;
    int range_low = 1, range_high = 100;
    int attempts = 5;
    srand(time(0)); int rand_num = (rand() % 100) + 1;

    cout << "I thought of a number between 1 and 100! Try to guess it.\n " <<  endl;
    
    int attempt_counter = attempts;
    
    for (int i = 0; i < attempts; i++) {
        
        //game banner
        cout << "Range: [" << range_low << " , " << range_high << "], "; //range output
        cout << "Number of guesses left: " << attempt_counter << endl; //attempt output
        cout << "Your guess: "; cin >> user_guess; //guess input

        /*Rule branches listed below*/
        //winner
        if (user_guess == rand_num) {
            cout << "\n";
            cout << "Congrats! ";
            cout << "You guessed my number in " << attempts - attempt_counter + 1 << " guesses!";

            i = attempts;
        }
        attempt_counter--; 
        //guess too small
        if (user_guess < rand_num && attempt_counter > 0) {
            cout << "WRONG. My number is bigger.\n";
            
            if (user_guess > range_low)
                range_low = user_guess + 1;
        }
        
        //guess too large
        if (user_guess > rand_num && attempt_counter > 0) {
            cout << "WRONG. My number is smaller.\n";
            
            if (user_guess < range_high)
                range_high = user_guess - 1;
        }
        
        //out of attempts
        if (attempt_counter == 0 && user_guess != rand_num) {
            cout << "\n" << "Out of guesses! My number is " << rand_num;
        }

        cout << "\n";
    }
    
    return 0;
}
