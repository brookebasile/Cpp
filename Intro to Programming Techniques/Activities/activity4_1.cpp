#include <iostream>
#include <iomanip> // Header used to manipulate output using stream mainpulators
using namespace std;

float tempC(float tempF) //Declare function return type as float, name as tempC, parameter (value that gets passed into function) as tempF (float)
{
    return (tempF-32)*5/9; //Definition of the function.  The function is evaluated before being returned.
}
int main()
{
    float tempF[5]; //Define tempF as an array with 5 float elements. 
    cout << "Enter five temperature values in Fahrenheit:" << endl; //Prompt user to enter in five temp values. 
    cin >> tempF[0] >> tempF[1] >> tempF[2] >> tempF[3] >> tempF[4]; //Receive each element in the array tempF[5]
    cout << setw(15) << "Fahrenheit" << setw(15) << "Celsius" << endl; //Print width 15 spaces

    for (int i=0; i<5; i++) //Define i as an int value equal to 0, less than five, moving thru the loop in increments of i+1 (0 > 1 > 2 > 3 > 4 > 5)
        {
            cout << setw(15) << setprecision(2) << fixed << tempF[i] << setw(15) << tempC(tempF[i]) << endl; //Set number of places after the decimal point to 2, fixed (always 2 places), print out the value for tempF[i], call the function tempC with parameter tempF[i]

            //The loop will begin at i=0, printing the value tempF[0] previously retrieved from the user, and making a function call to tempC using tempF[0] as the parameter, and will print these values.  The loop will continue to i = 1, 2, 3, 4, and will be terminated when i = 5. 
        }
    return 0;
}