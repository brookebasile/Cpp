#include <iostream>
#include <iomanip>

void currentBal(float, float*);

int main(){
	
	char verify;
	float transaction;
	float finalBal;
	do{
		std::cout << "Enter amount of transaction, positive for deposit, negative for withdrawal" << std::endl;
		std::cin >> transaction;
	
		currentBal(transaction, &finalBal); //Explicit referencing to pass an address (points to fin) 
	
		std::cout << "Do you have more transactions? Y or N" << std::endl;
		std::cin >> verify;
		
		if(!(verify == 'Y' || verify == 'y' || verify == 'N' || verify == 'n')){
			std::cout << "Error: please enter [Y] or [N]." << std::endl;
			std::cin >> verify;
		}
	}while(verify == 'Y' || verify == 'y');
	std::cout << "Final balance " << finalBal << std::endl; //Prints value held by the address of fin, which is equal to balance
	return 0;	
}

void currentBal(float transaction, float *fin){
	
	static float balance;
	float newBal = balance + transaction; 

	if(newBal < 0){
		std::cout << "Impermissible withdrawal, insufficient funds!" << std::endl;
	}
	else if (newBal >= 0){	
		std::cout << std::setprecision(2) << std::fixed << "Current balance = " << newBal << std::endl; 
		balance += transaction;
		*fin = balance; //Value pointed to by fin = balance 	
	}	
}
