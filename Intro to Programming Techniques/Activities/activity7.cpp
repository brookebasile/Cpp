#include <iostream>
using namespace std;
float due(int mins, float base, float addlMin)
{
    return (base + (mins*addlMin));
}
int main()
{
    char pkg;
    int mins;
    float base, addlMin;
    
    cout << "Which package did you purchase? Please enter A, B, or C." << endl;
    pkg = cin.get();

    if (!(pkg == 'A' || pkg == 'a' || pkg == 'B' || pkg == 'b' || pkg == 'C' || pkg == 'c'))
        {
            cout << "Error: please only enter package A, B, or C." << endl;
            return 0;
        }
    else if (pkg == 'C' || pkg == 'c')
        {
            base = 69.99;
            cout << "Total amount due: $" << base << endl;
            return 0;
        }

    cout << "How many minutes were used this month?" << endl;
    cin >> mins; 
    if (pkg == 'A' || pkg == 'a')
        {
            base = 39.99;
            addlMin = 0.45; 
            if (mins > 450)
                {
                    mins = mins - 450;
                    cout << "Total amount due: $" << due(mins, base, addlMin) << endl;
                }
            else
                {
                    cout << "Total amount due: $" << base << endl;
                }
        }
    else if (pkg == 'B' || pkg == 'b')
        {
            base = 59.99;
            addlMin = 0.40;
            if (mins > 900)
                {
                mins = mins - 900; 
                cout << "Total amount due: $" << due(mins, base, addlMin) << endl; 
                }
            else 
                {
                    cout << "Total amount due: $" << base << endl;
                }
        }
    return 0;
}