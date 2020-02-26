#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float shares, price, commission, sale, stockCost, purchaseCommission, saleRev, saleCommission, purchTotal, saleTotal;
    cout << "Enter number of shares purchased\t";
    cin >> shares;
    cout << "Enter purchase price of stock\t\t";
    cin >> price;
    cout << "Enter commission rate\t\t\t";
    cin >> commission; 
    cout << "Enter sale price\t\t\t";
    cin >> sale;

    {
        stockCost = shares*price;
        saleRev = shares*sale;
        saleCommission = commission*saleRev;
        purchaseCommission = commission*stockCost;
        purchTotal = stockCost+purchaseCommission;
        saleTotal = saleRev-saleCommission; 
    }
    
    cout << "\n************** TRANSACTION DETAILS **************" << endl; 
    cout << "Cost of stock before commission\t\t" << "$" << setw(10) << setprecision(2) << fixed << stockCost << endl; 
    cout << "Commission on purchase\t\t\t" << "$" << setw(10) << setprecision(2) << fixed << purchaseCommission << endl; 
    cout << "Total cost of purchase\t\t\t" << "$" << setw(10) << setprecision(2) << fixed << purchTotal << endl; 
    cout << "\nSale revenue before commission\t\t" << "$" << setw(10) << setprecision(2) << fixed << saleRev << endl;
    cout << "Commission on sale\t\t\t" << "$" << setw(10) << setprecision(2) << fixed << saleCommission << endl;
    cout << "Total cost of sale\t\t\t" << "$" << setw(10) << setprecision(2) << fixed << saleTotal << endl; 
    cout << "\nProfit or loss on sale\t\t\t" << "$" << setw(10) << setprecision(2) << fixed << saleTotal-purchTotal << endl;

    return 0;

}