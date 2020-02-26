#include <iostream>
using namespace std;
int evenSum(long x)
{
    long sum;
    sum = 0;    //Starting value of sum is 0
    
    while (x != 0)  //Will terminate when x = 0
        {
            int digit;
            digit = x % 10; //Get the last integer

            if (digit % 2 == 0) //Check to see if the digit is even 
            {
                sum += digit;   //Add digit to sum 
                x = x / 10;     //Remove the last digit, return to beginning of while statement
            }
            else    //For odd values 
            {
                x = x / 10;
            }
        }

    return sum; //Return value of sum 
}

int main()
{
    long x;
    cout << "Enter an integer greater than 10000: "; 
    cin >> x; 

    while (x < 10000)
        {
            cout << x << " is not greater than 10000" << endl; //Explain the error
            cout << "Enter an integer greater than 10000: "; //Get the input again 
            cin >> x;
        }
    
    cout << "The sum of the even digits of " << x << " is: " << evenSum(x) << endl;

    return 0;
}