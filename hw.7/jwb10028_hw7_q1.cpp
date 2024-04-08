#include <iostream>
using namespace std;

int printMonthCalendar(int numOfDays, int startDay);
int checkLeap(int n);
void printYearCalendar(int year, int startDay);

int main(){
    int year, startDay;
    cout << "Please enter a year followed by an integer 1 - 7 denoting the first day of the year:"<<endl;
    cin  >> year;
    cin  >> startDay;
    cout << endl;

    printYearCalendar(year, startDay);
    cout << endl << endl;
    cout << "Here is a look at the calendar year.";

    return 0;
}

int printMonthCalendar(int numOfDays, int startDay){
    int d = startDay; int n = numOfDays; int s = startDay; int c = 1;
    cout<<"Mon\t"<<"Tue\t"<<"Wed\t"<<"Thr\t";
    cout<<"Fri\t"<<"Sat\t"<<"Sun\t\n";
    for (int i = s; i > 1; i--){
        cout << "\t";
    }

    for (int i = s; i <= n+(s-1); i++){
        cout<< c<< "\t";
        if (d%7 == 0){
            cout<<endl; d = 0;
        }
        if(i == n+(s-1))
            break;
        d++;
        c++;
    }
    if (d == 0)
        d = 7;
    
    return d;
}

int checkLeap(int n){
    int t = 0; int f = 1;
    if ((n%4 == 0 && n%100 != 0) || (n%4 == 0 && n%400 == 0))
        return t;
    else
        return f;
}

void printYearCalendar(int year, int startDay){
    int m = 12; int d = 1; int s = startDay;

    for (int i = 1; i <= m; i++){
        ///month headers
        if (i == 1)
            cout << "January ";
        else if (i == 2)
            cout << "February ";
        else if (i == 3)
            cout << "March ";
        else if (i == 4)
            cout << "April ";
        else if (i == 5)
            cout << "May ";
        else if (i == 6)
            cout <<  "June ";
        else if (i == 7)
            cout << "July ";
        else if (i == 8)
            cout << "August ";
        else if (i == 9)
            cout << "September ";
        else if (i == 10)
            cout << "October ";
        else if (i == 11)
            cout << "November ";
        else 
            cout << "December ";

        //calendar
        cout << year<< endl;
        if (i <= 7 && i%2 == 1){
            int cal = printMonthCalendar(31, s);
            s = cal;
        }
        else if (i > 7 && i%2 == 0){
            int cal = printMonthCalendar(31, s);
            s = cal;
        }
        else if (i == 2){
            int leap = checkLeap(year);
            if (leap == 0){
                int cal = printMonthCalendar(29, s);
                s = cal;
            }
            else{
                int cal = printMonthCalendar(28, s);
                s = cal;
            }
        }
        else {
            int cal = printMonthCalendar(30, s);
            s = cal;
        }
        if (s <= 6)
            s++;
        else if (s == 7)
            s = 1;
        cout << endl << endl;
    }
}