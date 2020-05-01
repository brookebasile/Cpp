//Author: Brooke Basile 
//Class: CMPSC121 
//Experiment: 09
//File: E:\Documents\CMPSCI121\Labs\lab09.cpp
//Purpose: Functions
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

bool isLeapYear(short);
short getCenturyValue(short);
short getYearValue(short);
short getMonthValue(short, short, short);

int main(){
	short mm, dd, yy, dayOfWeek;
	char verify;
	std::string weekDay;

	do{
		std::cout << "Enter a date in the form month day year, e.g. 4 24 1939" << std::endl;
		std::cin >> mm >> dd >> yy;
		
		if((mm > 12 || ((mm == 1 || mm == 3 || mm == 5 || mm == 6 || mm == 7 || mm == 8) && dd > 31)) || ((mm == 4 || mm == 6 || mm == 9) && dd > 30) || ((mm == 2 && dd >= 29) && isLeapYear(yy) == false)){
			std::cout << "Error: invalid date." << std::endl;
		}
		else{
			dayOfWeek = ((dd + getMonthValue(mm, dd, yy) + getYearValue(yy) + getCenturyValue(yy))%7);
			switch(dayOfWeek){
				case 0:
					weekDay = "Sunday";
					break;
				case 1:
					weekDay = "Monday";
					break;
				case 2:
					weekDay = "Tuesday";
					break;
				case 3:
					weekDay = "Wednesday";
					break;
				case 4:
					weekDay = "Thursday";
					break;
				case 5:
					weekDay = "Friday";
					break;
				case 6:
					weekDay = "Saturday";
					break;
			}
			
			std::cout << mm << "/" << dd << "/" << yy << " is a " << weekDay << std::endl;
		}

		std::cout << "Do you wish to enter another date? Y or N \t";
		std::cin >> verify;

	}while(verify == 'y' || verify == 'Y');
}

bool isLeapYear(short yy){
	if((yy % 400 == 0) || ((yy % 4 == 0) && (!(yy % 100 == 0)))){
		return true;
	}
	else{
		return false;
	}
}

short getCenturyValue(short yy){
	short century = yy/100;
	short remainder = yy%4;
	return ((3 - remainder)*2);
}

short getYearValue(short yy){
	short lastTwo = yy%100;
	return ((lastTwo/4) + lastTwo);
}

short getMonthValue(short mm, short dd, short yy){
	if(isLeapYear(yy) == true){
		switch(mm){
			case 1:
				return 0;
				break;
			case 2:
				return 3;
				break;
			case 3:
				return 4;
				break;
			case 4:
				return 6;
				break;
			case 5:
				return 1;
				break;
			case 6:
				return 4;
				break;
			case 7:
				return 6;
				break;
			case 8:
				return 2;
				break;
			case 9:
				return 5;
				break;
			case 10:
				return 0;
				break;
			case 11:
				return 3;
				break;
			case 12:
				return 5;
				break;
		}
	}
	else{
		switch(mm){
			case 1:
				return 6;
				break;
			case 2:
				return 2;
				break;
			case 3:
				return 3;
				break;
			case 4:
				return 6;
				break;
			case 5:
				return 1;
				break;
			case 6:
				return 4;
				break;
			case 7:
				return 6;
				break;
			case 8:
				return 2;
				break;
			case 9:
				return 5;
				break;
			case 10:
				return 0;
				break;
			case 11:
				return 3;
				break;
			case 12:
				return 5;
				break;
		}
	}
	return 0;
}

/*
 Sample runs
 	Enter a date in the form month day year, e.g. 4 24 1939
	02 30 2019
	Error: invalid date.
	Do you wish to enter another date? Y or N       Y
	Enter a date in the form month day year, e.g. 4 24 1939
	10 26 2016
	10/26/2016 is a Wednesday
	
	Enter a date in the form month day year, e.g. 4 24 1939
	12 26 2016
	12/26/2016 is a Monday
*/
