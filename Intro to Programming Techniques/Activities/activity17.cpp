#include <iostream>
#include <cmath>
#include <iomanip>

void requestVariables(short&, short&, short&);
void longestPole(short, short, short);

int main(){
	short l, w, h;
	requestVariables(l, w, h);
	longestPole(l, w, h);
	return 0;
}

void requestVariables(short& l, short& w, short& h){
	std::cout << "Enter the length, width, and height of a room in meters:" << std::endl;
	std::cin >> l >> w >> h;
}

void longestPole(short l, short w, short h){
	float longest = sqrt(l*l+w*w+h*h);
	std::cout << "The longest pole that can fit in this room is: " << std::setprecision(2) << std::fixed << longest << std::endl;
}
