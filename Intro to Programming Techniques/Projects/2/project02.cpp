#include <iostream>
#include <fstream>
#include <iomanip>

std::ofstream outputFile; //Creates an ofstream (output file stream) object, part of std (global b/c being accessed by functions)

double calcCost(int, double, double);
double accTotal(double, double);
void printLine(std::string, std::string, int, double, double);
void printInvoiceHeader(std::string);
void printReportHeader();
void printTotal(double);

int main(){
	std::ifstream inputFile("input.txt"); //Creates & defines ifstream (input file stream) object named inputFile and calls object's open member function, passing "input.txt" as an argument -- opens file for reading)
	outputFile.open("Invoice.txt"); //Calls ofstream object's open member function, passing "Invoice.txt" as an argument -- creates new file in the directory for writing

	int items, quantity;
	double unitCost, totalCost, invoiceCost, newTotalCost;
	std::string date, name, itemNo;

	if (inputFile.fail()){ //Returns true if a reading operation fails (i.e. file is not writable, no space left), and also in the case of a format error (i.e. alphabet char extracted when trying to read an int)
		std::cout << "Error reading file." << std::endl;
	}
	else{
		if (outputFile.fail()){
			std::cout << "Error writing to file." << std::endl;
		}
		else{
			printReportHeader();
			while (inputFile >> items >> date){ //While int items & string date are found in the file (will terminate when they are not found, this is indicating end of file) 
				totalCost = 0; //
				invoiceCost = 0;
				printInvoiceHeader(date); //Call void function

				for(int i=0;i<items;i++){ //iterate through each line, terminating the loop at the end of the day's invoice as indicated by i < items 
					inputFile >> itemNo >> name >> quantity >> unitCost; //Stream of input data gets assigned to a string variable name, with a space (0x20) indicating where the end of each variable is located)
					totalCost = calcCost(quantity, unitCost, totalCost);
					invoiceCost += accTotal(totalCost, newTotalCost);
					printLine(itemNo, name, quantity, unitCost, totalCost);
				}
				printTotal(invoiceCost);
			}
		}
	}
	
	inputFile.close(); //Close the input file, flush buffers
	outputFile.close(); //Close the output file, flush buffers
	return 0;
}

double calcCost(int quantity, double unitCost, double totalCost){
	totalCost = quantity*unitCost;
	return totalCost;
}

double accTotal(double totalCost, double newTotalCost){
	newTotalCost = totalCost;
	return newTotalCost;
}

void printLine(std::string itemNo, std:: string name, int quantity, double unitCost, double totalCost){
	outputFile << std::setw(8) << itemNo << std::setw(13) << name << std::setw(5) << quantity << std::setw(8) << std::setprecision(2) << std::fixed << unitCost << std::setw(8) << std::setprecision(2) << std::fixed << totalCost << std::endl;
}

void printInvoiceHeader(std::string date){
	outputFile << "Invoice date: " << date << std::endl;
}

void printReportHeader(){
	outputFile << "Erie Industrial Supply Corporation" << std::endl;
}

void printTotal(double invoiceCost){
	outputFile << "Total ......................" << invoiceCost << std::endl;
}
