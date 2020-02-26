#include <iostream>
using namespace std;
int main()
{
    int m, d, y;
    cout << "Please enter a numeric month, day, and two digit year, separated by spaces" << endl;
    cin >> m >> d >> y; 
    if (m*d == y)
        {
            cout << "It's a MAGIC date!" << endl;
        }
    else 
        {
            cout << "It's not a magic date :(" << endl;
        }
    return 0;

}