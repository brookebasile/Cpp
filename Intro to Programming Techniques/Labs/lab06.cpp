//Author: Brooke Basile 
//Class: CMPSC121 
//Experiment: 06
//File: E:\Documents\CMPSCI121\Labs\lab04.cpp
//Purpose: Loops. 
/********************************************************************\
* Academic Integrity Affidavit:                                      *
* I certify that, this program code is my work.  Others may have     *
* assisted me with planning and concepts, but the code was written,  *
* solely, by me.                                                     *
* I understand that submitting code which is totally or partially    *
* the product of other individuals is a violation of the Academic    *
* Integrity Policy and accepted ethical precepts. Falsified          *
* execution results are also results of improper activities. Such    *
* violations may result in zero credit for the assignment, reduced   *
* credit for the assignment, or course failure.                      *
\********************************************************************/
// Sources of logic assistance:  121 Study Group:  Peter Parker, 
// Bruce Wayne, and Clark Kent 
#include <iostream>
#include <iomanip>
using namespace std;

float avgU(float uSold, float tNum)
{
    return ((uSold+99)/(tNum-2));
}
int main()
{
    float minPrice, maxPrice;
    float cost;
    short numItems;
    float uPrice = -1;
    short tNum = 1;
    short uSold = 0;
    float total = 0;


    cout << "Enter transactions -99 0 to stop" << endl;

    while(true) {
        cout << "Transaction # " << tNum << ":" << "\t";
        cin >> numItems >> uPrice;

        // break out of loop before doing maths
        if (numItems == -99 && uPrice == 0) {
            break;
        }

        uSold += numItems;
        cost = numItems * uPrice;
        total += cost;

        if (maxPrice < cost)
        {
            maxPrice = cost;
        }

        if (minPrice > cost || minPrice == 0)
        {
            minPrice = cost;
        }

        tNum++;
    }

    cout << "TRANSACTION PROCESSING REPORT" << endl;
    cout << "\tTransactions processed: \t" << tNum-1 << endl;
    cout << "\tUnits sold: \t\t\t" << uSold << endl;
    cout << "\tAverage Units per Order:\t" << setprecision(2) << fixed << avgU(uSold, tNum) << endl;
    cout << "\tLargest Transaction:\t\t" << setprecision(2) << fixed << maxPrice << endl;
    cout << "\tSmallest Transaction:\t\t" << setprecision(2) << fixed << minPrice << endl;
    cout << "\tAverage Revenue:\t\t" << setprecision(2) << fixed << total / (tNum-1) << endl;
    
    return 0;
}

/* 
Test run 
1. 
    Enter transactions -99 0 to stop
    Transaction # 1:        30 9.75
    Transaction # 2:        22 8.50
    Transaction # 3:        15 7.95
    Transaction # 4:        12 9.00
    Transaction # 5:        16 8.55
    Transaction # 6:        36 7.99
    Transaction # 7:        100 10.75
    Transaction # 8:        43 9.99
    Transaction # 9:        14 6.95
    Transaction # 10:       13 8.98
    Transaction # 11:       -99 0
    TRANSACTION PROCESSING REPORT
            Transactions processed:         10
            Units sold:                     301
            Average Units per Order:        44.44
            Largest Transaction:            1075.00
            Smallest Transaction:           97.30
            Average Revenue:                284.98
*/

