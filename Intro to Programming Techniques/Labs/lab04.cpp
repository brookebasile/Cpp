//Author: Brooke Basile 
//Class: CMPSC121 
//Experiment: 04
//File: E:\Documents\CMPSCI121\Labs\lab04.cpp
//Purpose: Selection logic.
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
#include <string>
using namespace std;

float amtDue(int hours1, int hours2, float rate1, float rate2)
{
    return ((rate1*hours1)+(rate2*hours2));
}

int main()
{
    char vehType; 
    int hours, hours1, hours2;
    float rate1, rate2;
    string vehOutput;

    cout << "Enter type of vehicle (C for car, T for truck, B for bus)" << endl;
    vehType = cin.get();

    if (!(vehType == 'C' || vehType == 'c' || vehType == 'T' || vehType == 't' || vehType == 'B' || vehType == 'b'))
        {
            cout << "Error: Please enter only C, T, or B." << endl;
            return 0;
        }

    cout << "\nEnter the number of hours parked." << endl;
    cin >> hours;

    if (vehType == 'C' || vehType == 'c')
        {
            vehOutput = "Car";
            rate1 = 1.25;
            rate2 = 1.50;

            if (hours <= 2)
                {
                    hours1 = hours;
                    hours2 = 0;
                }
            else
                {
                    hours1 = 2;
                    hours2 = hours - 2;
                }
        }
    else if (vehType == 'T' || vehType == 't')
        {
            vehOutput = "Truck";
            rate1 = 2.75;
            rate2 = 3.75;

            if (hours <= 2)
                {
                    hours1 = hours;
                    hours2 = 0;
                }
            else 
                {
                    hours1 = 2;
                    hours2 = hours - 2;
                }
        }
    else if (vehType == 'B' || vehType == 'b')
        {
            vehOutput = "Bus";
            rate1 = 9.50;
            rate2 = 6.75;

            if (hours <= 1)
                {
                    hours1 = hours;
                    hours2 = 0;
                }
            else 
                {
                    hours1 = 1;
                    hours2 = hours - 1;
                }
        }
    
    cout << "\nCrunchum Parking Lots, Inc." << endl;
    cout << "We usually find your vehicle!" << endl;
    cout << "=============================" << endl;
    cout << "Vehicle Type:\t" << vehOutput << endl;
    cout << "Time:\t\t" << hours << " hours" << endl;
    cout << "Amount Due:\t" << "$" << setprecision(2) << fixed << amtDue(hours1, hours2, rate1, rate2) << endl;
    cout << "=============================" << endl;

    return 0;

}

/*
Test runs:
    1. 
        Enter type of vehicle (C for car, T for truck, B for bus)
        c

        Enter the number of hours parked.
        7

        Crunchum Parking Lots, Inc.
        We usually find your vehicle!
        =============================
        Vehicle Type:   Car
        Time:           7 hours
        Amount Due:     $10.00
        =============================
    2. 
        Enter type of vehicle (C for car, T for truck, B for bus)
        t

        Enter the number of hours parked.
        10

        Crunchum Parking Lots, Inc.
        We usually find your vehicle!
        =============================
        Vehicle Type:   Truck
        Time:           10 hours
        Amount Due:     $35.50
        =============================
    3. 
        Enter type of vehicle (C for car, T for truck, B for bus)
        b

        Enter the number of hours parked.
        8

        Crunchum Parking Lots, Inc.
        We usually find your vehicle!
        =============================
        Vehicle Type:   Bus
        Time:           8 hours
        Amount Due:     $56.75
        =============================
    4. 
        Enter type of vehicle (C for car, T for truck, B for bus)
        k
        Error: Please enter only C, T, or B.
    5. 
        Enter type of vehicle (C for car, T for truck, B for bus)
        C

        Enter the number of hours parked.
        1

        Crunchum Parking Lots, Inc.
        We usually find your vehicle!
        =============================
        Vehicle Type:   Car
        Time:           1 hours
        Amount Due:     $1.25
        =============================
*/