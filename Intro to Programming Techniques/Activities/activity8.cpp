#include <iostream>
using namespace std;
int main()
{
    int x, y;
    cout << "Enter an integer coordinate: x, y" << endl;
    cin >> x >> y;

    if (x == 0 && y ==0)
        {
            cout << "(" << x << ", " << y << ") is the origin" << endl;
        }
    else if (x == 0)
        {
            cout << "(" << x << ", " << y << ") is on the y axis" << endl;
        } 
    else if (y == 0)
        {
            cout << "(" << x << ", " << y << ") is on the x axis" << endl;
        }
    else if (x > 0 && y > 0 )
        {
            cout << "(" << x << ", " << y << ") is in quadrant I" << endl;
        }
    else if (x < 0 && y > 0)
        {
            cout << "(" << x << ", " << y << ") is in quadrant II" << endl;
        }
    else if (x < 0 && y < 0)
        {
            cout << "(" << x << ", " << y << ") is in quadrant III" << endl;
        }
    else if (x > 0 && y < 0)
        {
            cout << "(" << x << ", " << y << ") is in quadrant IV" << endl;
        }
    return 0;
}