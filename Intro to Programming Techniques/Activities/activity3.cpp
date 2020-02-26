#include <iostream>
using namespace std; 
int main()
{
    int num1, num2, num3, num4, num5;
    double sum, avg;

    cout << "Enter 5 integers." << endl;
    cin >> num1 >> num2 >> num3 >> num4 >> num5;
    sum = num1 + num2 + num3 + num4 + num5;
    avg = sum/5;
    cout << "The average is " << avg << endl;

    return 0;
}

/*
Sample:
Enter 5 integers.
1
4
5
6
7
The average is 4.6
*/ 