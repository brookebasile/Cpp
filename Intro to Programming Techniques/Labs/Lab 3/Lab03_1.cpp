//Author: Brooke Basile 
//Class: CMPSC121 
//Experiment: 03
//File: E:\Documents\CMPSCI121\Labs\Lab03\Lab03_1.cpp
//Purpose: Output manipulation, floating point arithmetic, strings. 
/********************************************************************\
* Academic Integrity Affidavit:                                      *                                                                                         *                                                                    *
* I certify that, this program code is my work.  Others may have     *
* assisted me with planning and concepts, but the code was written,  *
* solely, by me.                                                                                                                                                *                                                                    *
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
#include <cmath>
using namespace std; 

const double PI = 3.14159; 

int main()
{
    float R, r, V, SA; 
    cout << "Enter radius of ring and radius of cross section" << endl;
    cin >> R >> r; 
    V = (2*pow(PI, 2))*(R*pow(r, 2));
    SA = (4*pow(PI, 2))*R*r;
    cout << setprecision(3) << fixed; //Set precision for all cout 
    cout << "For a ring with a radius of " << R << " and cross section radius of " << r << endl; 
    cout << "The volume is:\t\t" << V << endl;
    cout << "The surface area is:\t" << SA << endl;

    return 0;
}

/*

Sample run:

Enter radius of ring and radius of cross section
25.75 3
For a ring with a radius of 25.750 and cross section radius of 3.000
The volume is:          4574.554
The surface area is:    3049.703

*/ 