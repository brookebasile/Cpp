#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float temp1, temp2, temp3, temp4, temp5;
    cout << "Enter five temperature values in Fahrenheit:" << endl;
    cin >> temp1 >> temp2 >> temp3 >> temp4 >> temp5;
    cout << setw(15) << "Fahrenheit" << setw(15) << "Celsius" << endl;
    cout << setw(15) << setprecision(2) << fixed << temp1 << setw(15) << (temp1-32)*5/9 << endl;
    cout << setw(15) << setprecision(2) << fixed << temp2 << setw(15) << (temp2-32)*5/9 << endl;
    cout << setw(15) << setprecision(2) << fixed << temp3 << setw(15) << (temp3-32)*5/9 << endl;
    cout << setw(15) << setprecision(2) << fixed << temp4 << setw(15) << (temp4-32)*5/9 << endl;
    cout << setw(15) << setprecision(2) << fixed << temp5 << setw(15) << (temp5-32)*5/9 << endl;
    return 0;
}



