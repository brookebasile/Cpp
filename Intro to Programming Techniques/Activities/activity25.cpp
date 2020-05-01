/*
 * Write a program to fill a vector with 5000 random numbers. Then display:
    The smallest number
    The largest number
    The number of odd values
    The number of even values
    The total of the values
    The average of the values
    Ask the user for an integer and display the subscript of the cell where it was found or NOT FOUND! if it isn’t found. 
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include "time.h"


struct valSigns{
	int odd;
	int even;
} evenOdd;

void numCreator(std::vector <int>&, int&);
void shellSort(std::vector <int>&, const int&);
void swapper(int&, int&);
valSigns oddEven(std::vector <int>&, const int&, valSigns&);
long total(std::vector <int>&, const int&);
double average(const int&, const long&);
void displayValues(int&, int&, valSigns&, long&, double&);
void binarySearch(std::vector <int>&, int&, const int&);

int main(){
	//Seed the random number generator
	srand(time(0));

	//Define vector of type ints named randomNums
	std::vector <int> randomNums;
	
	//Define variable for vector size (to be modified by numCreator)
	int size, userInput;
	
	//Function call to numCreator with vector randomNums, size as arguments
	numCreator(randomNums, size);
	
	//Function call to shell sort: get vector in sequential order so that binary search may be used
	shellSort(randomNums, size);
	
	//Vector is in order, so smallest value is at 0
	int smallestVal = randomNums.at(0);
	
	//Largest value is at 4999
	int largestVal = randomNums.at(4999);
	
	//Function call to oddEven
	oddEven(randomNums, size, evenOdd);
	
	//Function call to total assigning return value to valsTotal
	long valsTotal = total(randomNums, size);
	
	//Function call to average assigning return value to valsAvg
	double valsAvg = average(size, valsTotal);
	
	//Print out values
	displayValues(smallestVal, largestVal, evenOdd, valsTotal, valsAvg);
	
	//Ask the user to input a number
	bool inRange;
	do{
		std::cout << "Enter an integer: ";
		std::cin >> userInput;
		
		if (userInput < 0 || userInput > 499){
			std::cout << "ERROR: Invalid entry." << std::endl;
			inRange = false;
		}
		else{
			inRange = true;
		}
	}while (inRange == false);
	//Function call to binarySearch
	binarySearch(randomNums, size, userInput);

	return 0;
}

void numCreator(std::vector <int> &randomNums, int &size){
	for (int i=0;i<5000;i++){
		randomNums.push_back(rand() % 500);
	}
	
	size = randomNums.size();
}

void shellSort(std::vector <int> &randomNums, const int &size){
	bool flag = true;
	int d = size;
	
	while (flag || (d>1)){	//bool flag
		flag = false; 	//reset flag to 0 to check for future swaps
		d = (d+1)/2;
		
		for (int i=0;i<(size - d);i++){
			if (randomNums[i+d] < randomNums[i]){
				swapper(randomNums[i], randomNums[i+d]);
				flag = true;	//tells swap has occurred
			}
		}
	}
}

void swapper(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

valSigns oddEven(std::vector <int> &randomNums, const int &size, valSigns &evenOdd){
	for (int i=0;i<size;i++){
		if (randomNums.at(i) % 2 == 0){
			evenOdd.even++;
		}
		else{
			evenOdd.odd++;
		}
	}
	
	return evenOdd;
}

long total(std::vector <int> &randomNums, const int  &size){
	long valsTotal;
	
	for (int i=0;i<size;i++){
		valsTotal += randomNums.at(i);
	}
	
	return valsTotal;
}

double average(const int &size, const long &valsTotal){
	double average = valsTotal/static_cast<double>(size);
	
	return average;
}

void displayValues(int &s, int &l, valSigns &evenOdd, long &valsTotal, double &valsAvg){
	std::cout << "The smallest number is: " << s << std::endl;
	std::cout << "The largest number is: " << l  << std::endl;
	std::cout << "The number of evens is: " << evenOdd.even << std::endl;
	std::cout << "The number of odds is: " << evenOdd.odd << std::endl;
	std::cout << "The total of the values is: " << valsTotal << std::endl;
	std::cout << "The average of the values is: " << std::setprecision(2) << std::fixed << valsAvg << std::endl;
}

void binarySearch(std::vector <int> &randomNums, int &size, const int &userInput){
	int first = 0;
	int last = size-1;
	int position = -1;
	bool found = false;

	while (!(found == true) && (first <= last)){
		int middle = (first+last)/2;
		
		if (randomNums.at(middle) == userInput){
			found = true;
			position = middle;
		}
		else if (randomNums.at(middle) > userInput){
			last = middle--;
		}
		else{
			first = middle++;
		}
	}

	if (position == -1){
		std::cout << "NOT FOUND!" << std::endl;
	}
	else{
		std::cout << userInput << " was found at position " << position << std::endl;
	}
}
