//Author: Brooke Basile 
//Class: CMPSC121 
//Experiment: 03
//File: E:\Documents\CMPSCI121\Labs\Lab03\Lab03_2.cpp
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

int main()
{
    float P, n, s, T, D;
    cout << "Enter values for horsepower (P), rpm (n), and shear strength (s)" << endl; 
    cin >> P >> n >> s;
    T = 63000*P/n;
    D = cbrt(16*T/s);
    cout << setprecision(3) << fixed;
    cout << right << setw(10) << "P(HP)" << setw(10) << "N(rpm)" << setw(10) << "S(psi)" << setw(13) << "T(torque)" << setw(15) << "D(diameter)" << endl;
    cout << right << setw(10) << P << setw(10) << n << setw(10) << s << setw(13) << T << setw(10) << D << " inches" << endl;

    return 0;
}

/*
Sample outputs:
    1) 
        Enter values for horsepower (P), rpm (n), and shear strength (s)
        20 1500 5000
            P(HP)    N(rpm)    S(psi)    T(torque)    D(diameter)
            20.000  1500.000  5000.000      840.000     1.390 inches
    2) 
        Enter values for horsepower (P), rpm (n), and shear strength (s)
        20 50 5000
            P(HP)    N(rpm)    S(psi)    T(torque)    D(diameter)
            20.000    50.000  5000.000    25200.000     4.320 inches
    3) 
        Enter values for horsepower (P), rpm (n), and shear strength (s)
        270 40 6500
            P(HP)    N(rpm)    S(psi)    T(torque)    D(diameter)
            270.000    40.000  6500.000   425250.000    10.154 inches