#include <iostream>
using namespace std;

void ulam(int);

int main()
{
    int input = 0;

    while(input < 2) //Break out of loop when input is > 2 (correct)
    {
        cout << "Enter a number >=2: ";
        cin >> input;

        if (input < 2) 
        {
            cout << "Invalid input!  Please try again..." << endl;
        }
    }
    cout << "The Ulam Sequence starting from " << input << " is: ";
    ulam(input);
    cout << endl;
}

void ulam(int input)
{
    cout << input << " ";
    while (input > 1) 
    {
        if (input % 2 == 0)
        {
            input = input / 2;
        }
        else if (input % 2 > 0)
        {
            input = input * 3 + 1;
        }
        cout << input << " ";
    }
}