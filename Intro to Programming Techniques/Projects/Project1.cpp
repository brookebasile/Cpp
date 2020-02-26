#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float windChill(short aTemp, short wSpeed) //pass aTemp and wSpeed through function windChill
{
    return (35.74+(0.6215*aTemp)-35.75*(pow(wSpeed, 0.16))+(0.4275*aTemp*(pow(wSpeed, 0.16))));
}

int main()
{
    short aTemp[] = {-5, 0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    short wSpeed[] = {5, 10, 15, 20, 25, 30, 35, 40, 45};
    short arrSizeTemp = sizeof(aTemp)/sizeof(short); //Total storage size of aTemp (byte) divided by size of short = # of short in array 
    short arrSizeSpeed = sizeof(wSpeed)/sizeof(short); //Total storage size of aTemp (byte) divided by size of short = # of short in array 
    short i, x;

    cout << "Temp | -------------------   Wind Speed ----------------------------" << endl;
    cout << setw(5) << " ";
    for (x=0; x<arrSizeSpeed; x++)
    {
        cout << right << setw(7) << wSpeed[x];
    }
    cout << "\n";

    for (i=0; i<arrSizeTemp; i++) //Beginning at point 0 in array, when i<size of array, increment thru each point in array
    {
        cout << setprecision(1) << setw(5) << fixed << aTemp[i];
        for (x=0; x<arrSizeSpeed; x++)
        {
            cout << setprecision(1) << fixed << setw(7) << windChill(aTemp[i], wSpeed[x]); //i & x value found from loop header
        }
        cout << "\n";
    }

    return 0;
}