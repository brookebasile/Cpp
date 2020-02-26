#include <iostream>
using namespace std;
int main()
{
	float num1, num2, num3, sum, quot, remainder, total;
	cout << "Enter 3 numbers\n";
	cin >> num1 >> num2 >> num3;
	sum = num1 + num2;
	cout << "The sum of the first two numbers entered is " << sum << '\n'; 

	if (num3 != 0)
	{
		float quot = (float)sum / (float)num3;
		cout << "The sum divided by the third number is " << quot << endl;
	}
	else
	{
		cout << "Unable to divide by zero" << endl;
	}

	return 0;
}
