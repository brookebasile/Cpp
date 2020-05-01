#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <iomanip>

void output(int [], int);

int main(){
	const int size = 50;
	int array[size];
	srand(time(0));

	for (int i=0;i<50;i++){
		array[i] = rand()%10000;
	}
	
	output(array, size);

	return 0;
}

void output(int array[], int size){
	for (int i=0;i<50;i++){
		((i != 0) && ((i % 10) == 9)) ? std::cout << std::setw(5) << std::fixed << array[i] << std::endl : std::cout << std::setw(5) << std::fixed << array[i] << " ";
	}
}
