#include <iostream>
#include <string>

int getProdNum(const int&, const int&);
int binarySearch(const int [], const int&, const int&);
void displayProd(std::string [], std::string [], double [], const int&);

int main(){
	const int NUM_PRODS = 9, MIN_PRODNUM = 914, MAX_PRODNUM = 922;
	int id[NUM_PRODS] = {914, 915, 916, 917, 918, 919, 920, 921, 922};
	std::string title[NUM_PRODS] = {"Six Steps to Leadership", "Six Steps to Leadership", "The Road to Excellence", "Seven Lessons of Quality", "Seven Lessons of Quality",	"Seven Lessons of Quality", "Teams Are Made, Not Born", "Leadership for the Future", "Leadership for the Future"};
	std::string description[NUM_PRODS] = {"Book", "Audio CD", "DVD", "Book", "Audio CD", "DVD", "Book", "Book", "Audio CD"};
	double prices[NUM_PRODS] = {12.95, 14.95, 18.95, 16.95, 21.95, 31.95, 14.95, 14.95, 16.95};
	int prodNum, position;

	prodNum = getProdNum(MIN_PRODNUM, MAX_PRODNUM);
	position = binarySearch(id, NUM_PRODS, prodNum);
	displayProd(title, description, prices, position);

	return 0;
}

int getProdNum(const int& MIN_PRODNUM, const int& MAX_PRODNUM){
	int prodNum;
	std::cout << "Enter a product number." << std::endl;
	while ((prodNum < 914) || (prodNum > 922)){
		std::cin >> prodNum;
		if ((prodNum < 914) || (prodNum > 922)){
			std::cout << "Error, invalid product number." << std::endl;
		}
	}
	return prodNum;	
}

int binarySearch(const int id[], const int &NUM_PRODS, const int &prodNum){
	int first = 0;
	int last = NUM_PRODS - 1;
	int position = -1; 
	bool found = false;
	while (!(found == true) && (first <= last)){
		int middle = (first + last)/2;
		if (id[middle] == prodNum){
			found = true;
			position = middle;
		}
		else if (id[middle] > prodNum){
			last = middle--;
		}
		else{
			first = middle++;
		}
	}
	return position;
}

void displayProd(std::string title[], std::string description[], double prices[], const int &position){
	std::cout << "Title: " <<  title[position] << std::endl;
	std::cout << "Description: " << description[position] << std::endl;
	std::cout << "Price: $" << prices[position] << std::endl;
}

