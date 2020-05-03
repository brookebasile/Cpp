/* Display:
 * A list of the products in the order of their sales dollars (NOT units sold), from highest to lowest
 * The total number of all units sold
 * The total sales for the 6 month period
 */

#include <iostream>
#include <iomanip>

void calcSales(double [], const int [], const double [], const int &);	//Calculates each product's sales
void dualSort(double [], int [], const int &);	//Sorts the sales array so the elements are ordered highest to lowest; prodNum array is ordered so the product numbers correspond with the correct sales figures in the sorted sales array
void swap (double &, double &);	//Swaps the values of the 2 doubles that are passed by reference (overloaded)
void swap (int &, int &);	//Swaps the values of two ints that are passed by reference (overloaded)
void showOrder(const double [], const int [], const int &);	//Displays a list of the product #s and sales amounts from the sorted sales & prodNum arrays
void showTotals(const int [], const double [], const int &);	//Displays the total number of units sold and the total sales amount for the period

int main(){
	int prodNum[] = {914,915,916,917,918,919,920,921,922};
	int units[] = {842,416,127,514,437,269,97,492,212};
	const int NUM_PRODS = sizeof(prodNum)/sizeof(prodNum[0]);
	double prices[] = {12.95, 14.95, 18.95, 16.95, 21.95, 31.95, 14.95, 14.95, 16.95}; 
	double sales[NUM_PRODS];

	calcSales(sales, units, prices, NUM_PRODS);
	dualSort (sales, prodNum, NUM_PRODS);
	
	std::cout << std::setprecision(2) << std::fixed << std::showpoint; //showpoint = always show decimal point even for 0 vals

	showOrder(sales, prodNum, NUM_PRODS);
	showTotals(units, sales, NUM_PRODS);

	return 0;
}

void calcSales(double sales[], const int units[], const double prices[], const int &num){
	for (int i=0;i<num;i++){
		sales[i] = units[i]*prices[i];
	}
} 

//TODO: synchronize id & sales arrays with units & prices
void dualSort(double sales[], int id[], const int &size){
	int start, maxIndex, tempid;
	double maxValue;

	for (start=0;start<(size-1);start++){
		maxIndex = start;
		maxValue = sales[start];
		tempid = id[start];
		for (int index=start+1;index<size;index++){
			if (sales[index] > maxValue){
				maxValue = sales[index];
				tempid = id[index];
				maxIndex = index;
			}
		}
		swap(sales[maxIndex], sales[start]);
		swap(id[maxIndex], id[start]);
	}
}

void swap(double &a, double &b){
	double temp = a;
	a = b;
	b = temp;
}

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void showOrder(const double sales[], const int id[], const int &num){
	std::cout << "Product number\tSales\n"; 
	std::cout << "-----------------------------\n";
	for (int index=0;index<num;index++){
		std::cout << id[index] << "\t\t$";
		std::cout << std::setw(8) << sales[index] << std::endl;
	}
	std::cout << std::endl;
}

void showTotals(const int units[], const double sales[], const int &num){
	int totalUnits = 0;
	double totalSales = 0.0;
	for (int index=0;index<num;index++){
		totalUnits += units[index];
		totalSales += sales[index];
	}
	std::cout << "Total Units Sold: " << totalUnits << std::endl;
	std::cout << "Total Sales:	$" << totalSales << std::endl;
}
