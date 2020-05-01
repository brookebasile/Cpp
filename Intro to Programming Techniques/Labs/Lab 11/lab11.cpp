//Author: Brooke Basile
////Class: CMPSC121
////Experiment: 11
////File: ~/CMPSC121/Labs/lab08.cpp
////Purpose: String handling.
///********************************************************************\
//* Academic Integrity Affidavit:                                      *
//* I certify that, this program code is my work.  Others may have     *
//* assisted me with planning and concepts, but the code was written,  *
//* solely, by me.                                                     *
//* I understand that submitting code which is totally or partially    *
//* the product of other individuals is a violation of the Academic    *
//* Integrity Policy and accepted ethical precepts. Falsified          *
//* execution results are also results of improper activities. Such    *
//* violations may result in zero credit for the assignment, reduced   *
//* credit for the assignment, or course failure.                      *
//\********************************************************************/
//// Sources of logic assistance:  121 Study Group:  Peter Parker,
//// Bruce Wayne, and Clark Kent

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>

std::string fixName(std::string); //Takes in the name and returns it in the right format
std::string fixSSN(std::string); //Fixes SSN
std::string fixPhone(std::string); //Fixes phone number
std::string fixAddress(std::string); //Fixes address
std::string fixCity(std::string);  //Fixes city
std::string fixState(std::string); //Fixes state
std::string extractField(std::string&); //Extracts a field eg name from the input string & deletes it & the # that follows it
void buildLine(std::string&, std::string); //Concatenates field and comma to string s

int main(){
	std::string line,s;

	std::ifstream inputFile("badnames.txt");

	if (inputFile.fail()){
		std::cout << "Error reading file." << std::endl;
	}
	else{
		while (inputFile){
			
			std::getline(inputFile, line);

			if(!line.empty()) {
				s = "";
				buildLine(s,fixName(extractField(line)));
				buildLine(s,fixSSN(extractField(line)));
				buildLine(s,fixPhone(extractField(line)));
				buildLine(s,fixAddress(extractField(line)));
				buildLine(s,fixCity(extractField(line)));
				buildLine(s,fixState(extractField(line)));
				buildLine(s,extractField(line));
				line = "";
			
				std::cout << s << std::endl;
			}
		}
	}
	
	return 0;
}

std::string extractField(std::string &line){
	std::string field;
	int firstOcto = line.find('#');
	field = line.substr(0, firstOcto);
	line = line.substr(firstOcto+1);
	return field;
}

void buildLine(std::string &s, std::string field)
{
	if (s.empty()){
		s = field;
	} 
	else{
		s += ','+field;
	}
}

std::string fixName(std::string name)
{
	std::string firstName = name.substr(0, name.find(" "));
	std::string lastName = name.substr(name.find(" ")+1);
	firstName[0] = toupper(firstName[0]);
	lastName[0] = toupper(lastName[0]);
	return firstName + ',' + lastName;
}

std::string fixSSN(std::string ssn)
{
	return ssn.substr(0, 3) + '-' + ssn.substr(3, 2) + '-' + ssn.substr(5, 9);
}

std::string fixPhone(std::string phone)
{
	return phone.substr(0, 3) + '-' + phone.substr(3, 3) + '-' + phone.substr(4, 4);
}

std::string fixAddress(std::string address)
{
	int len = address.length();
	for (int i = 0;i<len;i++){
		if (address[i] == ' ') {
			address[i+1] = toupper(address[i+1]);
		}
	}	
	return address;
}

std::string fixCity(std::string city)
{
	city[0] = toupper(city[0]);
	return city;
}

std::string fixState(std::string state)
{
	transform(state.begin(), state.end(), state.begin(), ::toupper);
	return state;
}

/*
 Sample run
	John,Smith,165-98-0076,814-833-3379,3rd & State St,Erie,PA,16506
	Martin,Gardner,164-90-5543,440-354-5427,5244 Heisley Rd,Mentor,OH,44123
	Sarah,Vendetti,164-87-9987,330-254-5411,29 Millhaven St.,Akron,OH,44532
	Judy,Golumbiewski,194-40-9976,716-334-3476,6187 Fillmore Ave,Rochester,NY,07654
	Terry,Merz,193-97-6554,800-243-4357,19876 Elm Avenue,Manchester,MO,63166
	Kenisha,Jones,198-43-2265,919-361-6104,902 East Taylor Rd,Apex,NC,27709
	Phil,Yee,176-40-9976,630-860-6026,1976 Wacker Drive,Chicago,IL,60191
	Jean,Caron,167-45-3321,973-887-8747,1429 Delben Street,Whippany,NJ,07981
	Sandy,Alicea,176-41-9006,305-442-4282,12 La Habana East,Miami,FL,33134
	Rob,Williams,206-33-7765,334-271-7154,9854 Fremont Blvd,Montgomery,AL,36109
	Jancy,Hilfiger,201-87-6987,814-881-8176,3012 State St,Pittsburgh,PA,15011
*/
