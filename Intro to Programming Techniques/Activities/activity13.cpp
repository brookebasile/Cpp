#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
	srand(time(0)); //Seed the random number generator
	float avg = 0;
	short n = 0;
	short flip;

	for(short i=0;i<10;i++){
		do{
			flip = rand() % 2; //Selects number in array {0, 1}
			if (flip){
				cout << "T"; //T = 1	
				n++; 
			} 
			else {
				cout << "H" << "\t\t"; //H = 0
				n += 1;
				cout << "You win $" << setprecision(2) << fixed << pow(2,n) << endl;
				avg += pow(2,n);
			}
		}while(flip != 0);
		n = 0;
	}
	cout << "The average payout was $" << avg/10 << endl;
	return 0;
}




