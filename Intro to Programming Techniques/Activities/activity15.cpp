#include <iostream>
#include <iomanip>
using namespace std; 

float calculateValue(short, float);

int main(){
	short numItem;
	float cost;
	char confirm;
	float value;

	while(confirm != 'N'){
		cout << "Enter the number of items sold:\t\t";
		cin >> numItem;
		cout << "Enter the item's individual cost:\t";
		cin >> cost;

		value = calculateValue(numItem, cost);

		cout << "The extended amount is " << setprecision(2) << fixed << value << endl;
		cout << "Do you have another purchase to enter? [Y]es or [N]o" << endl;
		cin >> confirm;
	}

	cout << "Thank you!" << endl;
	return 0;
}

float calculateValue(short numItem, float cost){
	return numItem*cost;
}
