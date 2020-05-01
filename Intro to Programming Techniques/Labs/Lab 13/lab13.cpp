//Author: Brooke Basile 
//Class: CMPSC121 
//Experiment: 13
//File: ~/CMPSC121/Labs/'Lab 13'/lab13.cpp
//Purpose: Arrays and reading files
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
#include <time.h>
#include <iomanip>

bool readFile(std::string [], int &);
void getVotes(int [], int);
void calculatePercents(int [], double [], int);
void displayResults(std::string [], int [], double [], int);

int main(){
	//Declare size of array 
	const int CAPACITY=25;
	
	//Size gets a separate value because the size of the array is greater than the # of strings in the text file
	int size = CAPACITY;
	std::string candidates[size];
	int votes[size];
	double percents[size];
	
	//File verification
	if (readFile(candidates, size) == false){
		std::cout << "Error reading file" << std::endl;
	}
	else{
		getVotes(votes, size);
		calculatePercents(votes, percents, size);
		displayResults(candidates, votes, percents, size);
	}
	return 0;
}

bool readFile(std::string c[], int &size){
	std::ifstream inputFile("candidates.txt");
	if (inputFile.fail()){
		return false;
	}
	else{
		std::string line;
		int i = 0;
		while (inputFile >> line){
			c[i] = line;
			i++;
		}
		size = i;
	}
	inputFile.close();
	return true;
}

void getVotes(int v[], int size){
	srand(time(0));
	for (int i=0;i<size;i++){
		v[i] = (rand() % (25000 - 15000 + 1)) + 1500;
	}
}

void calculatePercents(int v[], double p[], int size){
	int totalVotes = 0;
	for (int i=0;i<size;i++){
		totalVotes += v[i];
	}
	for (int i=0;i<size;i++){
		p[i] = (static_cast<double>(v[i])/(totalVotes))*100;
	}
}

void displayResults(std::string c[], int v[], double p[], int size){
	//Calculate largest value in v[]
	int highest = v[0];
	std::string winner = c[0];
	for (int i=0;i<size;i++){
		if (v[i] > highest){
			highest = v[i];
			winner = c[i];
		}
	}	
	//Output results
	std::cout << std::setw(12) << std::left << "Candidate"; 
	std::cout << std::setw(10) << "Votes";
	std::cout << std::setw(10) << std::left << "Percent" << std::endl;

	for (int i=0;i<size;i++){
		std::cout << std::setw(12) << std::left << c[i];
		std::cout << std::setw(10) << v[i];
		std::cout << std::setw(10) << std::right << std::setprecision(1) << std::fixed << p[i] << "%" << std::endl;
	}

	std::cout << "The winner is " << winner << " with " << highest << " votes!" << std::endl;
}

/*
 * Sample runs
 * 1. 
 * 	Candidate   Votes     Percent   
	Rubio       3280             2.6%
	Bush        4762             3.7%
	Christie    11283            8.9%
	Paul        10325            8.1%
	O'Malley    5455             4.3%
	Cruz        11370            8.9%
	Clinton     11008            8.6%
	Trump       2993             2.4%
	Kasich      3355             2.6%
	Sanders     6368             5.0%
	Carson      3442             2.7%
	Gilmore     10703            8.4%
	Fiorina     7180             5.6%
	Santorum    2781             2.2%
	Huckabee    7299             5.7%
	Graham      3878             3.0%
	Jindal      3046             2.4%
	Walker      10656            8.4%
	Perry       8086             6.4%
	The winner is Cruz with 11370 votes!
* 2.
* 	Candidate   Votes     Percent   
	Rubio       9181             7.5%
	Bush        5833             4.7%
	Christie    8660             7.0%
	Paul        6210             5.0%
	O'Malley    8788             7.1%
	Cruz        4551             3.7%
	Clinton     6645             5.4%
	Trump       6013             4.9%
	Kasich      3751             3.0%
	Sanders     4960             4.0%
	Carson      3363             2.7%
	Gilmore     3103             2.5%
	Fiorina     11212            9.1%
	Santorum    5226             4.2%
	Huckabee    4667             3.8%
	Graham      11248            9.1%
	Jindal      7754             6.3%
	Walker      10046            8.2%
	Perry       1872             1.5%
	The winner is Graham with 11248 votes!
* 3. 
* 	Candidate   Votes     Percent   
	Rubio       6822             5.1%
	Bush        5080             3.8%
	Christie    10687            7.9%
	Paul        3682             2.7%
	O'Malley    11062            8.2%
	Cruz        6497             4.8%
	Clinton     8716             6.5%
	Trump       2951             2.2%
	Kasich      11366            8.4%
	Sanders     10679            7.9%
	Carson      7567             5.6%
	Gilmore     10668            7.9%
	Fiorina     7106             5.3%
	Santorum    6704             5.0%
	Huckabee    7271             5.4%
	Graham      6535             4.9%
	Jindal      6108             4.5%
	Walker      1909             1.4%
	Perry       3255             2.4%
	The winner is Kasich with 11366 votes!
*/
