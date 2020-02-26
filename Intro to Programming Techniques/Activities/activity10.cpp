#include <iostream>
using namespace std;
int main()
{
    int weekDay;
    char y;
    do
    {
        cout << "Enter a day of week value (1-7, 1 being Monday, 7 being Sunday): ";
        cin >> weekDay;
        switch(weekDay)
        {
            case 1:
                cout << "Monday" << endl;
                break;
            case 2:
                cout << "Tuesday" << endl;
                break;
            case 3:
                cout << "Wednesday" << endl;
                break;
            case 4:
                cout << "Thursday" << endl;
                break;
            case 5:
                cout << "Friday" << endl;
                break;
            case 6:
                cout << "Saturday" << endl;
                break;
            case 7:
                cout << "Sunday" << endl;
                break;
            default:
                cout << weekDay << " is invalid" << endl;
                y = 'y'; //If y is not initialized as 'y' (true) the do while will receive a false and exit the program 
                continue; //Continues to beginning of switch statement 
        }
        cout << "Do you wish to continue? "; 
        cin >> y;
    } while (y == 'y');

    cout << "Goodbye!  Thank you for using our program!" << endl;

    return 0;
}