/*
Write a program which asks the user to enter a string and then passes it to a void recursive function which displays the string in reverse. The prototype of the function would be:

void reverse(string s, int i);

The function call would be:

reverse(strIn, strIn.length());

A typical run will be:

Enter a string:

Four score and seven years ago ..

.. oga sraey neves dna erocs ruoF
*/

#include <iostream>
#include <string>

void reverse(std::string, int);

int main(){
	std::string input;
	
	std::cout << "Enter a string." << std::endl;
	
	getline(std::cin, input);
	
	int i = input.length() - 1;

	reverse(input, i);

	std::cout << std::endl;

	return 0;
}

void reverse(std::string input, int i){
	if (i >= 0){
		std::cout << input.at(i);
		i--;
		reverse(input, i);
	}
}
