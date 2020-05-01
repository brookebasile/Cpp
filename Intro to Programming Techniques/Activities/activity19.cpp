/*
The area of a triangle can be calculated given its base and height, or given the lengths of its sides.  You can find the formulas for each of these methods on the web.  Write a program with two overloaded functions both named triangleArea.  In main, randomly ask the user to enter either base and height or the lengths of the three sides and then make the appropriate call to triangleArea. triangleArea should return the area to main where it will be displayed. The program should contain an outer loop which asks if the user wishes to continue. A typical run would be:
*/
#include <iostream>
#include <ctime>
#include <cmath>
#include <cctype>

float triangleArea(short, short);
float triangleArea(short, short, short);

int main(){
	srand(time(0));
	char userVerify;
	short b, h, l1, l2, l3;

	do{
		short r = rand()%2;

		if (r == 0){
			printf("Enter base and height of a triangle.\n");
			scanf("%hd %hd",&b,&h);
			printf("The area is %g\0.2f", triangleArea(b, h));
		}
		else if (r == 1){
			printf("Enter the lengths of the sides of a triangle.\n");
			scanf("%hd %hd %hd",&l1,&l2,&l3);
			printf("The area is %g\0.2f", triangleArea(l1, l2, l3));
		}

		printf("\nRun again? Y or N\n");
		scanf("%s", &userVerify);

	}while(toupper(userVerify) == 'Y');
	return 0;
}

float triangleArea(short b, short h){
	float area = 0.5*b*h;
	return area;
}

float triangleArea(short l1, short l2, short l3){
	float p = (l1+l2+l3)/2;
	float area = sqrt(p*(p-l1)*(p-l2)*(p-l3));
	return area;
}
