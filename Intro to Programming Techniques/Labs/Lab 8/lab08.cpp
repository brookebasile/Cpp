//Author: Brooke Basile 
//Class: CMPSC121 
//Experiment: 08
//File: E:\Documents\CMPSCI121\Labs\lab08.cpp
//Purpose: Random numbers.
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
#include <cstdlib>
#include <time.h>
using namespace std;

float batAvg(float, float, float);

int main(){
    srand(time(0));
    char verify;
    float bat = 1000;
    float rng; 
    do { 
        float out = 0, walk = 0, single = 0, dbl = 0, triple = 0, homeRun = 0, hit = 0; //Place in do-while but before for loop to reset values after each iteration
        for(float i=0;i<1000;i++) {
            rng = rand()%1000+1;    //Produces a number in the array {0,1000}
            if(rng<580){
                out++;
            }
            else if(rng>580 && rng<677){
                walk++;
            }
            else if(rng>677 && rng<897){
                single++;
                hit++;
            }
            else if(rng>897 && rng<968){
                dbl++;
                hit++;
            }
            else if(rng>958 && rng<983){
                triple++;
                hit++;
            }
            else if(rng>983){
                homeRun++;
                hit++;
            }
        }
        cout << "Simulation of the mighty Casey at-bat 1000 times:" << endl;
        cout << "\n";
        cout << right << setw(11) << "Out:";
        cout << right << setw(11) << setprecision(1) << fixed << out/10 << "%" << endl;
        cout << right << setw(11) << "Walk:";
        cout << right << setw(11) << setprecision(1) << fixed << walk/10 << "%" << endl;
        cout << right << setw(11) << "Single:";
        cout << right << setw(11) << setprecision(1) << fixed << single/10 << "%" << endl;
        cout << right << setw(11) << "Double:";
        cout << right << setw(11) << setprecision(1) << fixed << dbl/10 << "%" << endl;
        cout << right << setw(11) << "Triple:";
        cout << right << setw(11) << setprecision(1) << fixed << triple/10 << "%" << endl;
        cout << right << setw(12) << "Home Run:\t";
        cout << right << setw(6) << setprecision(1) << fixed << homeRun/10 << "%" << endl;
        cout << "\n";
        cout << "Casey's batting average was:\t" << setprecision(3) << fixed << batAvg(hit, bat, walk) << endl;
        cout << "\n";
        cout << "Would you like to run another simulation (Y/N)?\t";
        cin >> verify;
    }while (verify!='N');

    cout << "Thanks for playing!" << endl;

    return 0;
}

float batAvg(float hit, float bat, float walk){
    return (hit/(bat-(walk/100)));
}

/*
    create a range of values representing the percentages: 
        rng = rand(1,1000)

        rng < 580: out
        rng > 580 && rng < 677 walk
        rng > 677 && rng < 897 single
        rng > 897 && rng < 958 double
        rng > 958 && rng < 983 triple 
        rng > 983 home run 
*/

/*
Trial runs 
    Simulation of the mighty Casey at-bat 1000 times:

        Out:       57.4%
        Walk:        9.8%
        Single:       21.4%
        Double:        7.1%
        Triple:        1.8%
    Home Run:        2.5%

    Casey's batting average was:    0.328

    Would you like to run another simulation (Y/N)? Y
    Simulation of the mighty Casey at-bat 1000 times:

        Out:       53.9%
        Walk:        9.6%
        Single:       24.6%
        Double:        7.0%
        Triple:        2.4%
    Home Run:        1.7%

    Casey's batting average was:    0.357

    Would you like to run another simulation (Y/N)? Y
    Simulation of the mighty Casey at-bat 1000 times:

        Out:       58.3%
        Walk:       10.7%
        Single:       21.5%
        Double:        7.0%
        Triple:        1.4%
    Home Run:        0.7%

    Casey's batting average was:    0.306

    Would you like to run another simulation (Y/N)? N
    Thanks for playing!
*/ 