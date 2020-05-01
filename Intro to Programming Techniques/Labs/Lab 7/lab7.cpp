//Author: Brooke Basile 
//Class: CMPSC121 
//Experiment: 07
//File: E:\Documents\CMPSCI121\Labs\Lab07\lab07.cpp
//Purpose: Loops & reading text files.
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
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

float avgMPG(float, float);

int main(){
    string vehID;
    string bID = "";
    string wID = "";
    float miles, gallons, mpg;
    float totMiles = 0;
    float totGallons = 0;
    short count = 0;
    float bMPG = 0;
    float wMPG = 999;

    ifstream inf("FleetInput.txt");

    cout << "AMSCO Fleet Report" << endl;
    cout << "Vehicle ID" << setw(10) << "Miles" << setw(10) << "Gallons" << setw(10) << "MPG" << setw(10) << endl;
    cout << "----------------------------------------------------------------" << endl;

    while(inf >> vehID >> miles >> gallons){
        mpg = miles/gallons;
        cout << setprecision(1) << fixed << vehID << setw(10) << miles << setw(10) << gallons << setw(10) << mpg << setw(10) << endl;
        count++;
        totMiles += miles;
        totGallons += gallons;

        if (mpg > bMPG){
            bMPG = mpg;
            bID = vehID;
        }
        if (mpg < wMPG){
            wMPG = mpg;
            wID = vehID;
        }
    }
    cout << "----------------------------------------------------------------" << endl;
    cout << setw(30) << left << "Count:" << count << endl;
    cout << setw(30) << left << "Total Miles:" << totMiles << endl;
    cout << setw(30) << left << "Average MPG:" << avgMPG(totMiles, totGallons) << endl;
    cout << setw(30) << left << "Vehicle ID with Best MPG:" << bID << "\t" << bMPG << endl;
    cout << setw(30) << left << "Vehicle ID with Worst MPG:" << wID << "\t" << wMPG <<  endl;
    return 0;
}

float avgMPG(float totMiles, float totGallons){
    return (totMiles/totGallons);
}

/*
Sample output:

AMSCO Fleet Report
Vehicle ID     Miles   Gallons       MPG
----------------------------------------------------------------
279BX6KY2Z     582.2      20.5      28.4
802MX8BZ4Q     723.6      25.1      28.8
671AY6DZ3N     756.9      27.5      27.5
845DH6AJ3B     660.2      25.4      26.0
566GJ6KV2U     510.2      30.8      16.6
109QW2RP2Y     301.2       8.3      36.3
135TR4YC6H     387.6      12.2      31.8
122AC6UG7P     228.9      14.7      15.6
136VW8TD2Z     331.2      19.1      17.3
448WQ2DX1M     543.9      33.6      16.2
721GZ1LJ5N     629.8      27.9      22.6
779FS3MB4Y     651.2      28.4      22.9
553SB5LK8O     444.4      26.8      16.6
----------------------------------------------------------------
Count:                        13
Total Miles:                  6751.3
Average MPG:                  23.6
Vehicle ID with Best MPG:     109QW2RP2Y        36.3
Vehicle ID with Worst MPG:    122AC6UG7P        15.6

*/ 
