#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cctype>
using namespace std;

//Class Implementations/Interface:
class Money {
public:
    //Operator Overloading:
    friend Money operator +(const Money& amount1, const Money& amount2);
    //Returns the sum of the values of amount1 and amount2.

    friend Money operator -(const Money& amount1, const Money& amount2);
    //Returns amount1 minus amount2.

    friend bool operator ==(const Money& amount1, const Money& amount2);
    //returns true if amount1 and amount2 have same value. False otherwsie.

    friend bool operator <(const Money& amount1, const Money& amount2);
    //returns true if amount1 is less than amount2. False otherwise.

    //Constructors:
    Money(long dollars, int cents);
    //Inits the object so its value represents an amount with
    //the dollars and cents given by the arguments. If the amount
    //is negative, then both dollars and cents should be negative

    Money(long dollars);
    //Inits the object so its value represents $dollars.00

    Money();
    //Inits the object so its value represents $0.00

    //Accessors:
    double get_value() const;
    //Returns the amount of money recorded in the data portion
    // of the calling object

    //IO:
    friend istream& operator >>(istream& ins, Money& amount);
    //Overloads the >> operator so it can be used with type Money.
    //Notation for inputting negative amounts is as in - $100.00
    //Precondition: If ins is a file input stream, then ins
    //has already been connected to a file

    friend ostream& operator <<(ostream& outs, const Money& amount);
    //Overloads the << operator so it can be used with type Money.
    //Precedes each output value of type Money with a dollar sign.
    //Precondition: If outs is a file output stream, then outs has 
    //already been connected to a file

    private:
        long all_cents;
};
class Check {
public:
    //Constructors:
    Check(int ID, double Amount, bool isCashed);
    //Inits the object so its values represent a valid check.

    Check(int ID, double amount);
    //Inits the object so that its values represent ID Amount 0

    Check();
    //Inits the object so that all ID, Amount, and IsCashed are all 0.

    //Accessors:
    Money get_amount() const;
    //return the amount on the check using data type money

    int   get_ID() const;
    //returns the ID number of the check

    bool  get_IsCashed() const;
    //returns whether or not the check has been cashed
    //1 for true, 0 for false

    //IO:
    friend istream& operator >>(istream& ins, Check& currCheck);
    //overloads the >> operator to accept statements that input data for an object of type Check

    friend ostream& operator <<(ostream& outs, Check& currCheck);
    //overloads the << operator to properly outpput the check ID, amount, and whether it has been cashed

    //Mutators:
    void set_ID(int newID);
    //sets a new id number for a check type
    
    void set_Amount(Money newAmount);
    //sets a new amount for a check type
    
    void set_IsCashed(bool newIsCashed);
    //sets a new check cashed status for a check type
private:
    int checkID;
    Money checkAmount;
    bool checkIsCashed;
};

//extra helper function declarations:
int digit_to_int(char c);
void resizeArr(double*& arr, int& currentSize, int newSize);
void resizeArr(Check*& arr, int& currentSize, int newSize);
Money return_deposits(double total_deposits);
Money return_balance(double prior_balance, double sum_of_deposits, Money total_cashed_checks);

int main(){ 
    cout << "Please enter the check number, amount on check[exclude the dollar sign] and whether or not\n";
    cout << "the check has been cashed by typing 1(yes) or 0(no) : \n";
    cout << "Example Input: 9 40.89 1\n";
    cout << "End output by entering 0 0.00 0\n" << endl;

    //check array input
    cout << "Enter Check(s): \n";
    int input_checks_arr_size = 2; int j = 0;
    Check* input_checks_arr = new Check[input_checks_arr_size];
    while (true) {
        int ID; double amount; bool isCashed;
        cin >> ID;
        cin >> amount;
        cin >> isCashed;
        if(ID == 0 && amount == 0.00 && isCashed == false){
            break;
        } else {
            Check temp(ID, amount, isCashed);
            input_checks_arr[j] = temp;
            if (j == input_checks_arr_size - 1){
                resizeArr(input_checks_arr, input_checks_arr_size, input_checks_arr_size*2);
            }
        }
        j++;
    }

    //sum of checks cashed/uncashed
    cout << endl;
    cout << "The sum of the cashed checks is: "<<endl;
    Money sum_of_cashed;
    for (int i = 0; i < input_checks_arr_size - 1; i++){
        
        bool cashed = input_checks_arr[i].get_IsCashed();
        if (cashed == true){
            sum_of_cashed = sum_of_cashed + input_checks_arr[i].get_amount();
        }
        
    }
    cout << sum_of_cashed;

    cout << endl;
    cout << "The sum of the un-cashed checks is: "<<endl;
    Money sum_of_uncashed;
    for (int i = 0; i < input_checks_arr_size-1; i++){
        bool cashed = input_checks_arr[i].get_IsCashed();
        if (cashed == false){
            sum_of_uncashed = sum_of_uncashed + input_checks_arr[i].get_amount();
        }
    }
    cout << sum_of_uncashed << endl;
    cout << endl;

    cout << "Please enter the deposits in the format ##.## (end by typing 0.00): "<<endl;
    
    //dynamic array for deposits
    int deposit_arrSize = 2; int i = 0;
    double* deposits = new double[deposit_arrSize];
    while (true){
        cin >> deposits[i];
        if(deposits[i] == 0.00){
            break;
        } else {
            if (i == deposit_arrSize - 1){
                resizeArr(deposits, deposit_arrSize, deposit_arrSize*2);
            }
        }
        i++;
    }

    //sum of depostis
    cout << endl;
    cout << "The sum of deposits is: "<<endl;
    double sum = 0.0;
    for (int i = 0; i < deposit_arrSize - 1; i++){
        double temp = deposits[i];
        sum += temp;
    }
    Money sum_of_deposits = return_deposits(sum);
    cout << sum_of_deposits <<endl;

    //balance input
    cout << endl;
    cout << "Please enter the prior balance amount (format ##.##)"<<endl;
    double prior_balance; cin >> prior_balance;
    cout << "Please enter the new balance according to account holder (format ##.##)"<<endl;
    double new_balance; cin >> new_balance; cout << endl;

    Money final_balance = return_balance(prior_balance, new_balance, sum_of_cashed);
    cout << "The balance according to the bank which includes only cleared checks is: "<< final_balance << endl;
    Money account_difference = final_balance - sum_of_deposits;
    cout << "The difference between the account holder's balance and the bank's balance is: "<< account_difference << endl;
    cout << endl;

    //list checks cashed/unchashed
    Money empty_checkAmt;
    cout << "The cashed checks are:"<<endl;
    for (int i = 0; i < input_checks_arr_size; i++){
        if (input_checks_arr[i].get_IsCashed() == 1 && empty_checkAmt < input_checks_arr[i].get_amount()){
            cout << "Check: " << input_checks_arr[i].get_ID() << " with amount: ";
            cout << input_checks_arr[i].get_amount() << endl;
        }
    }
    cout << endl;
    
    cout << "The uncashed checks are: "<<endl;
    for (int i = 0; i < input_checks_arr_size; i++){
        if (input_checks_arr[i].get_IsCashed() == 0 && empty_checkAmt < input_checks_arr[i].get_amount()){
            cout << "Check: " << input_checks_arr[i].get_ID() << " with amount: ";
            cout << input_checks_arr[i].get_amount() << endl;
        }
    }
    
    delete [] input_checks_arr;
    delete [] deposits;

    return 0;
}

//extra helper function definitions:
Money return_deposits(double total_deposits){
    double total = total_deposits * 100;
    int total_cents =  (int)total % 100;
    long total_dollars = (int)total / 100;
    Money sum_of_deposits(total_dollars, total_cents);
    return sum_of_deposits;
}
Money return_balance(double prior_balance, double sum_of_deposits, Money total_cashed_checks){
    double cashed_checks = total_cashed_checks.get_value();
    
    double post_deposits = prior_balance + sum_of_deposits;
    double final_balance = post_deposits - cashed_checks;
    final_balance *= 100;
    long final_dollars = (int)final_balance / 100;
    int final_cents = (int)final_balance % 100;
    Money final_dollar_amount(final_dollars, final_cents);
    return final_dollar_amount;

}
void resizeArr(double*& arr, int& currentSize, int newSize){
    double* temp = new double[newSize];
    for (int i = 0; i < currentSize; i++){
        temp[i] = arr[i];
    }
    delete [] arr;
    arr = temp;
    currentSize = newSize;
}
void resizeArr(Check*& arr, int& currentSize, int newSize){
    Check* temp = new Check[newSize];
    for (int i = 0; i < currentSize; i++){
        temp[i] = arr[i];
    }
    delete [] arr;
    arr = temp;
    currentSize = newSize;
}
int digit_to_int(char c){
    int digit = c - '0';
    return digit;
}

//Money Operator Overloading Functions:
Money operator +(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}
Money operator -(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}
bool operator ==(const Money& amount1, const Money& amount2){
    return (amount1.all_cents == amount2.all_cents);
}
bool operator <(const Money& amount1, const Money& amount2){
    return (amount1.all_cents < amount2.all_cents);
}

//Money Constructors:
Money::Money(long dollars, int cents){
    if (dollars * cents < 0){
        cout << "Illegal Entry for dollars and cents. Aborting Program";
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}
Money::Money(long dollars) : all_cents(dollars * 100){}
Money::Money() : all_cents(0){}

//Money Accesors:
double Money::get_value() const{
    return (all_cents * .01);
}

//Money IO:
istream& operator >>(istream& ins, Money& amount){
    char one_char, decimal_point, digit1, digit2;
    long dollars; int cents;
    bool negative;//sets to true if input is negative

    ins >> one_char;
    if (one_char == '-'){
        negative = true;
        ins >> one_char; //read '$'
    }
    else {
        negative = false;
    }
    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)){
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
    amount.all_cents = dollars * 100 + cents;
    if (negative)
        amount.all_cents = -amount.all_cents;
    return ins;

}
ostream& operator <<(ostream& outs, const Money& amount){
    long positive_cents, dollars, cents;
    positive_cents = amount.all_cents;
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if (amount.all_cents < 0){
        outs << "- $" << dollars << ".";
    } else {
        outs << "$" << dollars << ".";
    }
    if (cents < 10){
        outs << '0';
    }
    outs << cents;

    return outs;
}


//Check Constructors:
Check::Check(int ID, double Amount, bool isCashed){
    checkID = ID;
    checkIsCashed = isCashed;

    double change = (double)Amount - (int)Amount;
    change *= 100;
    int cents = change;
    long dollars = (int)Amount;
    Money temp(dollars, cents);
    checkAmount = temp;
    
}
Check::Check(int ID, double Amount){
    checkID = ID;
    checkIsCashed = 0;

    double change = (double)Amount - (int)Amount;
    change *= 100;
    int cents = change;
    long dollars = (int)Amount;
    Money temp(dollars, cents);
    checkAmount = temp;
}
Check::Check(){
    checkID = 0;
    long dollars = 0;
    int cents = 0;
    Money temp(dollars, cents);
    checkAmount = temp;
    checkIsCashed = 0;
}


//Check Accessors:
Money Check::get_amount() const{
    return checkAmount;
}
int Check::get_ID() const{
    return checkID;
}
bool Check::get_IsCashed() const{
    return checkIsCashed;
}

//Check IO:
istream& operator >>(istream& ins, Check& currCheck){
    int ID; double amount; bool isCashed;
    ins >> ID >> amount >> isCashed;
    Check temp(ID, amount, isCashed);
    currCheck = temp;
}
ostream& operator <<(ostream& outs, Check& currCheck){
    int temp_ID; Money temp_amount; bool temp_cashed;
    temp_ID = currCheck.get_ID();
    temp_amount = currCheck.get_amount();
    temp_cashed = currCheck.get_IsCashed();
    outs << temp_ID << " " << temp_amount << " " << temp_cashed;
    return outs;
}


//Check Mutators:
void Check::set_ID(int newID){
    if (newID < 0){
        cout << "Illegal ID entry. Aborting program";
        exit(1);
    }
    checkID = newID;
}
void Check::set_Amount(Money newAmount){
    Money empty_checkAmt(0,0);
    if (newAmount < empty_checkAmt){
        cout << "Illegal Check amount entry. Aborting program";
        exit(1);
    }
    checkAmount = newAmount;
}
void Check::set_IsCashed(bool newIsCashed){
    if (newIsCashed != 1 || newIsCashed != 0){
        cout << "Illegal check status entry. Aborting program";
        exit(1);
    }
    checkIsCashed = newIsCashed;
}