/*
 * Write a program using parallel vectors and a function which fills each of them with 500 random numbers between 1 and 100. The program should then pass both vectors to a function which will return an integer indicating a count of how many times both vectors had even numbers in the same location. So if vector01[0] contained 4 and vector02[0] contained 12, you would add one to count. If vector01[1] contained 3 and vector02[1] contained 4, you would not add one to count.

main would display something like:

The Vectors contain 128 cells where both values are even.

Note: create a much smaller vector (20 numbers perhaps) to test your program on. This way you can test your program correctness much easier.
 *
 */

#include <iostream> 
#include <vector>
#include <time.h>

int isEven(const std::vector<short>&, const std::vector<short>&);

int main(){
	//Seed random # generator
	srand(time(0));
	
	//Declaring vectors
	std::vector<short> nums01; 
	std::vector<short> nums02;

	//Populate vectors with random numbers
	for (int i=0;i<500;i++){
		nums01.push_back(rand() % 100 + 1);
		nums02.push_back(rand() % 100 + 1);
	}
	
	std::cout << "The Vectors contain " << isEven(nums01, nums02) << " cells where both values are even." << std::endl;
	return 0;
}

int isEven(const std::vector<short> &nums01, const std::vector<short> &nums02){
	int even = 0;
	for (int i=0;i<500;i++){
		if ((nums01[i]%2==0) && (nums02[i]%2==0)){
			even++;
		}
	}
	return even;
} 
