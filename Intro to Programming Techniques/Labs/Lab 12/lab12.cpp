//Author: Brooke Basile 
//Class: CMPSC121 
//Experiment: 12
//File: ~/CMPSC121/Labs/lab12.cpp
//Purpose: Structs.
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
#include <iomanip>

struct sales{
	std::string invoiceNumber;
	char equipmentCode;
	float partsCost;
};

struct stats{
	float totalSales;
	float capPercent;
	float eqpPercent;
	float prtPercent;
};

void accumulate(const sales &, float &, float &, float &);
stats getStats(float, float, float);
void writeReport(float, float, float, stats);

int main(){
	std::ifstream inputFile("sales.txt");
	
	sales record;
	stats salesStats;
	float capSales = 0, eqpSales = 0, prtSales = 0;

	if (inputFile.fail()){
		std::cout << "Error reading file \"sales.txt\"" << std::endl;
	}
	else{
		while (inputFile >> record.invoiceNumber >> record.equipmentCode >> record.partsCost){
			accumulate(record, capSales, eqpSales, prtSales);
		}
		inputFile.close();
	}

	salesStats = getStats(capSales, eqpSales, prtSales);
	
	writeReport(capSales, eqpSales, prtSales, salesStats);

	return 0;
}

void accumulate(const sales &record, float &capSales, float &eqpSales, float &prtSales){
	switch (record.equipmentCode){
		case 'A':
			capSales += record.partsCost;
			break;
		case 'B':	
			eqpSales += record.partsCost;
			break;
		case 'C':
			prtSales += record.partsCost;
			break;
	}
} 

stats getStats(float capSales, float eqpSales, float prtSales){
	stats tempSalesStats;
	tempSalesStats.totalSales = (capSales + eqpSales + prtSales);
	tempSalesStats.capPercent = (capSales / tempSalesStats.totalSales)*100; 
	tempSalesStats.eqpPercent = (eqpSales / tempSalesStats.totalSales)*100;
	tempSalesStats.prtPercent = (prtSales / tempSalesStats.totalSales)*100;

	return tempSalesStats;
}

void writeReport(float capSales, float eqpSales, float prtSales, stats salesStats){
	std::ofstream outputFile("inventoryReport.txt");
	outputFile << "\t S A L E S    R E P O R T\t" << std::endl;
	outputFile << std::setw(23) << std::left << "Capital Equipment";
	outputFile << "$" << std::setprecision(2) << std::fixed << capSales << "\t";
	outputFile << std::setprecision(2) << std::fixed << salesStats.capPercent << "%" << std::endl;
	outputFile << std::setw(23) << std::left << "Expensed Equipment";
	outputFile << "$" << std::setprecision(2) << std::fixed << eqpSales << "\t";
	outputFile << std::setprecision(2) << std::fixed << salesStats.eqpPercent << "%" << std::endl;
	outputFile << std::setw(23) << std::left << "Small Parts";
	outputFile << "$" << std::setprecision(2) << std::fixed << prtSales << "\t";
	outputFile << std::setprecision(2) << std::fixed << salesStats.prtPercent << "%" << std::endl;
	outputFile << std::setw(32) << std::right << "---------" << std::endl;
	outputFile << std::setw(23) << std::left << "Total Sales"; 
	outputFile << "$" << std::setprecision(2) << salesStats.totalSales << std::endl;
	outputFile.close();
}

/* 
 * Sample run
 * 	 S A L E S    R E P O R T
 *Capital Equipment      $24093.18	26.31%
 *Expensed Equipment     $22222.80	24.27%
 *Small Parts            $45251.98	49.42%
 *                       ---------
 *Total Sales            $91567.95
 *
 */
