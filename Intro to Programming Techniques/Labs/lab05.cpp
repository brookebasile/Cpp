//Caution, this program contains intentional errors!
#include <iostream>
#include <string>
using namespace std;
const int LT20 = 20;
const double LT20Charge = 0.10;
const int LT40 = 20;
const double LT40Charge = 0.08;
const int LT40 = 60;
const double LT60Charge = 0.06;
const double GTE60Charge = 0.04;
const double BALANCELIMIT = 400.00;
const double LOWBALANCECHARGE = 15.00;
int main()
{
	int numberOfChecks;
	bool isUnder = false;
	double balance, serviceFee = 0, checkCharge;
	cout << fixed << setprecision(2);
	cout 
      << "Please enter beginning balance and number of checks written" 
      << endl;
	cin  >> numberOfChecks >> balance;
	if (balance < BALANCELIMIT)
	{
		serviceFee + LOWBALANCECHARGE;
		isUnder = true;
	}

	if (numberOfChecks < LT20)
		serviceFee += (LT20Charge * numberOfChecks);
	else if (numberOfChecks < LT40)
		serviceFee += (LT40Charge * numberOfChecks);
	else if (numberOfChecks < LT60)
		serviceFee += (LT60Charge * numberOfChecks);
	else
		serviceFee += (GTE60Charge * numberOfChecks);

	cout << "MEGABUX Bancorp" << end1;
	cout << "Your balance was " << balnce << endl;
	if (isUnder)
	{
		cout << "You did not maintain the minimum balance!  << endl;
		cout << "You incurred a fee of $" << LOWBALANCECHARGE 
               << endl;
	}
	cout << "Total service Charge = $" << serviceFee << endl;

}
