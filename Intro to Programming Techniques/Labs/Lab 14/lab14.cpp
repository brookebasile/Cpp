//Author: Brooke Basile 
//Class: CMPSC121 
//Experiment: 04
//File: ~/CMPSC121/Labs/'Lab 14'/lab14.cpp 
//Purpose: Vectors
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
// Sources of logic assistance:  C++ Discord server, Stackoverflow 
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

struct Parts{
	std::string partNum;
	char partClass;
	int stock;
	double cost;
};

std::istream &operator >> (std::istream &is, Parts &part){
	if (is >> part.partNum >> part.partClass >> part.stock){
		is >> part.cost;
	}
	return is;
}

bool readFile(std::vector <Parts> &pVector);
int displayMenu();
double totalCost(const std::vector <Parts> &pVector);
void countByClass(const std::vector <Parts> &pVector, std::vector <int> &classCounts);
double costForClass(const char &classIn, const std::vector <Parts> &pVector);
std::string highestCost(const std::vector <Parts> &pVector);
std::string lowestCost(const std::vector <Parts> &pVector);
void displayCounts(const std::vector <int> &classCounts);

int main(){
	std::vector <Parts> pVector;
	std::vector <int> classCounts;
	
	std::cout << std::setprecision(2) << std::fixed;

	if (!readFile(pVector)){
		std::cout << "Error reading file!" << std::endl;
	}
	else{
		int choice = 0;
		while (choice != 6){
			choice = displayMenu();
			switch (choice){
				case 1:
					std::cout << "Total cost of inventory is $" << totalCost(pVector) << std::endl;
					break;
				case 2:
					countByClass(pVector, classCounts);
					displayCounts(classCounts);
					break;
				case 3:
					char classIn;
					std::cout << "Which class?" << std::endl;
					std::cin >> classIn;
					std::cout << "Cost of inventory for class " << classIn << " is $" << costForClass(classIn, pVector) << std::endl;
					break;
				case 4:
					std::cout << "The part with the highest cost of inventory is " << highestCost(pVector) << std::endl;
					break;
				case 5:
					std::cout << "The part with the lowest cost of inventory is " << lowestCost(pVector) << std::endl;
					break;
			}
		}
	}

	return 0;
}

bool readFile(std::vector <Parts> &pVector){
	std::ifstream inputFile("parts.txt");
	
	if (inputFile.fail()){
		std::cout << "Error reading file!" << std::endl;
		return false;
	}
	else{
		Parts part;
		while (inputFile >> part){
			pVector.emplace_back(part);
		}
		return true;
	}
}

int displayMenu(){
	int selection;
	
	std::cout << "\t R E P O R T S   M E N U\t" << std::endl;
	std::cout << "1. Total cost of inventory." << std::endl;
	std::cout << "2. A count of parts of each class." << std::endl;
	std::cout << "3. Cost of inventory for a class." << std::endl;
	std::cout << "4. Part with the highest cost of inventory." << std::endl;
	std::cout << "5. Part with the lowest cost of inventory." << std::endl;
	std::cout << "6. Exit." << std::endl;
	std::cin >> selection;
	
	std::cout << "\033[2J\033[1;1H";	//Works with UNIX & Windows (?)

	if (selection < 6){
		std::cout << "Your choice was " << selection << std::endl;
	}

	
	return selection;
}

double totalCost(const std::vector <Parts> &pVector){
	double total = 0;
	for (int i=0;i < pVector.size();i++){
		total += pVector[i].cost * pVector[i].stock;
	}
	return total;
}

void countByClass(const std::vector <Parts> &pVector, std::vector <int> &classCounts){
	for (int i=0;i<6;i++){
		classCounts.emplace_back(0);
	}
	for (int i=0;i < pVector.size();i++){
		//The index of classCounts is A B C D E F = 6, where A=0, B=1, C=2,...,; A's ASCII value is 65, so we subtract 65 from the value found at pVector[i].partClass to determine where in the index of classCounts it lies.
		int x = static_cast<int>(pVector[i].partClass)-'A';
		classCounts[x]++;
	}
}

double costForClass(const char &classIn, const std::vector <Parts> &pVector){
	double total = 0;
	for (int i=0;i < pVector.size();i++){
		if (pVector[i].partClass == classIn){
			total += pVector[i].cost * pVector[i].stock;
		}
	}
	return total;
}

void displayCounts(const std::vector <int> &classCounts){
	char c = 'A';
	std::cout << "Count of parts by class" << std::endl;
	for (int i=0;i<6;i++, c++){
		std::cout << c << "\t" << classCounts[i] << std::endl;
	}
}

std::string highestCost(const std::vector <Parts> &pVector){
	int highIndex = 0;
	for (int i=0;i < pVector.size();i++){
		if (pVector[i].cost > pVector[highIndex].cost){
			highIndex = i;
		}
	}
	return pVector[highIndex].partNum;
}

std::string lowestCost(const std::vector <Parts> &pVector){
	int lowIndex = 0 ;
	for (int i=0;i < pVector.size();i++){
		if (pVector[i].cost < pVector[lowIndex].cost){
			lowIndex = i;
		}
	}
	return pVector[lowIndex].partNum;
}

/* Sample run
	Your choice was 1
 	Total cost of inventory is $342965.70
	
	Your choice was 2
	Count of parts by class
	A	85
	B	69
	C	77
	D	60
	E	5
	F	8
	
	Your choice was 3
	Which class?
	A
	Cost of inventory for class A is $191180.07

	Your choice was 4
	The part with the highest cost of inventory is P-27345
	
	Your choice was 5
	The part with the lowest cost of inventory is P-31071
 */
