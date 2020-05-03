#include <iostream>
#include <vector>
#include <string>
#include <fstream> 
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

//fills vector
bool get_data(std::vector <Parts> &pVector);
//Does a binary search 
int bin_search(std::string key, const std::vector <Parts> &pVector);
//Asks user for a part number to search for
std::string get_target();
//gets remaining info to add a part number
void get_more_data(Parts &userInput);
//Inserts part number data into vector
void insert_data(std::vector <Parts> &pVector, std::string key, Parts userInput);
//Displays info on part number
void display(std::vector <Parts> &pVector, const int &finder);
//sorts vectors (Calls swapper)
void sort(std::vector <Parts> &pVector);
//prints search stats
void print_stats(const int &searches, const int &found, const int &notFound);
//writes out file when program ends, so additions are saved to file
void put_data(std::vector <Parts> &pVector);
//templated swap function - Swaps two items in a vector of any type
template <class CType>
void swapper(CType &a, CType &b){
	CType temp;
	temp = a;
	a = b; 
	b = temp;
}

int main(){
	std::vector <Parts> pVector;
	int searches = 0, notFound = 0, found = 0;
	Parts userInput;

	if (!(get_data(pVector))){
		std::cout << "Error reading file!" << std::endl;
	}
	else{
		char cont;
		do{
			sort(pVector);
			std::string key = get_target();
			int finder = bin_search(key, pVector);
				if (finder == -1){
					char verify;
					notFound++;
					std::cout << "Add this part?" << std::endl;
					std::cin >> verify;
					if (verify == 'y' || verify == 'Y'){
						get_more_data(userInput);
						insert_data(pVector, key, userInput);
					}
				}
				else{
					display(pVector, finder);
					found++;
				}
			searches++;
			std::cout << "Would you like to do another search? <Y or N>" << std::endl;
			std::cin >> cont;
		}while (cont == 'Y' || cont == 'y');
	}

	print_stats(searches, found, notFound);
	put_data(pVector);
	
	return 0;
}

bool get_data(std::vector <Parts> &pVector){
	std::ifstream inputFile("parts.txt");

	if (inputFile.fail()){
		return false;
	}
	else{
		Parts part;
		while (inputFile >> part){
			pVector.emplace_back(part);
		}
		inputFile.close();
		return true;
	}
}

int bin_search(std::string key, const std::vector <Parts> &pVector){
	int first = 0;
	int last = pVector.size() - 1;
	int position = -1;
	bool found = false;
	while (!(found == true) && (first < last)){  //Changed to first < last because if string isn't in the vector, first = last
		int middle = (first + last)/2;
		if (pVector[middle].partNum == key){
			found = true;
			position = middle;
		}
		else if (pVector[middle].partNum > key){
			last = middle--;
		}
		else{
			first = middle++;
		}
	}
	return position;
}

std::string get_target(){
	std::string key; 
	std::cout << "What part number would you like to look for?" << std::endl;
	std::cin >> key;
	return key;
}

void get_more_data(Parts &userInput){
	std::cout << "What class is this part number in?" << std::endl;
	std::cin >> userInput.partClass;
	std::cout << "What is the on hand balance of this part?" << std::endl;
	std::cin >> userInput.stock;
	std::cout << "What is the cost of this part?" << std::endl;
	std::cin >> userInput.cost;
}

void insert_data(std::vector <Parts> &pVector, std::string key, Parts userInput){
	userInput.partNum = key;
	pVector.emplace_back(userInput);
}

void display(std::vector <Parts> &pVector, const int &finder){
	double value = pVector[finder].cost * pVector[finder].stock;
	std::cout << std::setprecision(2) << std::fixed;
	std::cout << "There are " << pVector[finder].stock << " of Part Number " << pVector[finder].partNum << " in inventory.  It is a class " << pVector[finder].partClass << " part.  The cost is $ " << pVector[finder].cost << ".  The value of that inventory is $" << value << "." << std::endl;	
}

void sort(std::vector <Parts> &pVector){
	bool flag = true;
	int i;
	int d = pVector.size();
	while (flag || (d>1)){
		flag = false;
		d = (d+1)/2;
		for (i=0;i<((pVector.size()-d));i++){
			if (pVector[i+d].partNum < pVector[i].partNum){
				swapper(pVector[i+d], pVector[i]);
				flag = true;
			}
		}
	}
}

void print_stats(const int &searches, const int &found, const int &notFound){
	switch (searches){
		case 1:
			std::cout << "There was " << searches << " search performed today." << std::endl;
			break;
		default:
			std::cout << "There were " << searches << " searches performed today." << std::endl;
	}
	switch (found){
		case 1:
			std::cout << found << " of them was successful." << std::endl;
			break;
		default:
			std::cout << found << " of them were successful." << std::endl;
	}
	switch (notFound){
		case 1:
			std::cout << notFound << " of them was not in the system." << std::endl;
			break;
		default:
			std::cout << notFound << " of them were not in the system." << std::endl;
	}
}

void put_data(std::vector <Parts> &pVector){
	std::ofstream outputFile("report.txt");
	for (int i=0;i<pVector.size();i++){
		outputFile << pVector[i].partNum << " " << pVector[i].partClass << " " << pVector[i].stock << " " << pVector[i].cost << std::endl;
	}
	outputFile.close();
	std::cout << "The file is now updated." << std::endl;
}
