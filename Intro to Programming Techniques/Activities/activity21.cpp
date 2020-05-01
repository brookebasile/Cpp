#include <iostream>
#include <fstream>

std::ofstream outputFile("output.txt");

struct dataVars{
	std::string partNumber, partName;
	char partClass;
	int stock;
	double unitPrice;
}; 

void writeData(struct dataVars userInput);

int main(){
	char verify;
	dataVars userInput;

	do{
		std::cin >> userInput.partNumber;
		std::cin >> userInput.partName;
		std::cin >> userInput.partClass;
		std::cin >> userInput.stock;
		std::cin >> userInput.unitPrice;
		
		writeData(userInput);

		std::cout << "More parts? Y or N" << std::endl;
		std::cin >> verify;

	}while ((verify == 'y') || (verify == 'Y'));
	
	outputFile.close();

	return 0;
}

void writeData(dataVars userInput){
	outputFile << userInput.partNumber << " " << userInput.partName << " " << userInput.partClass << " " << userInput.stock << " " << userInput.unitPrice;
}
