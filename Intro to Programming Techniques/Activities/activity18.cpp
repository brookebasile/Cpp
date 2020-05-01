#include <iostream>
#include <string>

void convertUpper(std::string&);

int main(){
	std::string name;
	std::cout << "Enter a name first mi last" << std::endl;
	getline(std::cin, name);
	convertUpper(name);
	
	return 0;
}

void convertUpper(std::string& name){
	char mi = toupper(name.at(name.find(".") - 1));
	char last = toupper(name.at(name.find(".") + 2));
	char first = toupper(name.at(0));
	std::cout << first << " " << mi << " " << last << std::endl;
}
