/* 
For rolling a pair of dice you can treat each die as a separate variable, with identical expressions-- each die contains a value between 1 and 6, with equal probability of rolling a value between 1 and 6. 
This directly models the real world as you'd be throwing identical die with identical probabilities. 
*/ 

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(0)); //Seed the random number generator
    short d1 = rand()%6+1; //Produces a number in the array {0, 1, 2, 3, 4, 5, 6}
    short d2 = rand()%6+1;
    short roll = d1+d2; //Total of both dies 
    cout << "Die 1:\t" << d1 << endl;
    cout << "Die 2:\t" << d2 << endl;
    cout << "You rolled " << roll << endl;

    return 0;
}