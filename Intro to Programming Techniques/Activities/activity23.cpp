#include <iostream>
#include <time.h>

int main(){
	const int SIZE = 10;
	int nums[SIZE] = {5, 4, 2, 7, 6, 8, 5, 2, 8, 14};
	srand(time(0));

	//#1 Square each number
	std::cout << "Square each number" << std::endl;
	for (int i=0;i<SIZE;i++){
		nums[i] = nums[i] * nums[i];
		std::cout << nums[i] << " ";
	}
	//#2 Add a random number between zero and 10 to each number.
	std::cout << "\nAdd a random number between zero and 10 to each number." << std::endl;
	for (int &val : nums){
		val += rand() % 11;
		std::cout << val << " ";
	}
	//#3 Add to each number the number that follows in the array.  Skip the last value in the array. 
	std::cout << "\nAdd to each number the number that follows in the array.  Skip the last value in the array." << std::endl;
	for (int i=0;i<9;i++){
		nums[i] += nums[i+1];
		std::cout << nums[i] << " ";
	}
	//#4 Calculate the sum of all the numbers.
	std::cout << "\nCalculate the sum of all the numbers" << std::endl;
	int total = 0;
	for (int i=0;i<SIZE;i++){
		total += nums[i];
	}
	std::cout << total << std::endl;
	//#5 Display the largest number in the array 
	std::cout << "Display the largest number in the array" << std::endl;
	int highest = nums[0];
	for (int i=0;i<SIZE;i++){
		if (nums[i] > highest){
			highest = nums[i];
		}
	}
	std::cout << highest << std::endl;

	return 0;
}
