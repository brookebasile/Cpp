#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

void lineA(short, float);
void lineB(short, float);
void lineC(short, float);
void lineD(short, float);
void lineU(short, float);

int main()
{
    short countA = 0, countB = 0, countC = 0, countD = 0, countU = 0;
    float invA = 0, invB = 0, invC = 0, invD = 0, invU = 0;
    char part;
    short stock;
    string partNumber;
    float cost;

    ifstream inputFile("parts.txt");

    if(inputFile.fail())
    {
        cout << "Error opening file." << endl;
        return 0;
    }

    while (inputFile >> partNumber >> part >> stock >> cost)
    {
        switch(part)
        {
            case 'A':
                countA++;
                invA += cost * stock;
                break;
            case 'B':
                countB++;
                invB += cost * stock;
                break;
            case 'C':
                countC++;
                invC += cost * stock;
                break;
            case 'D':
                countD++;
                invD += cost * stock;
                break;
            default:
                countU++;
                invU += cost * stock;
                break;
        }
        
    }
    inputFile.close();
    cout << ".................INVENTORY REPORT...................." << endl;
    lineA(countA, invA);
    lineB(countB, invB);
    lineC(countC, invC);
    lineD(countD, invD);
    lineU(countU, invU);
    return 0;
}

void lineA(short countA, float invA)
{
    cout << "A parts     " << "Count: " << countA << "     " << "Value of inventory: " << setprecision(2) << fixed << invA << endl;
}
void lineB(short countB, float invB)
{
    cout << "B parts     " << "Count: " << countB << "     " << "Value of inventory: " << setprecision(2) << fixed << invB << endl;
}
void lineC(short countC, float invC)
{
    cout << "C parts     " << "Count: " << countC << "     " << "Value of inventory: " << setprecision(2) << fixed << invC << endl;
}
void lineD(short countD, float invD)
{
    cout << "D parts     " << "Count: " << countD << "     " << "Value of inventory: " << setprecision(2) << fixed << invD << endl;
}
void lineU(short countU, float invU)
{
    cout << "Unknown     " << "Count: " << countU << "     " << "Value of inventory: " << setprecision(2) << fixed << invU << endl;
}

/* 
Sample
.................INVENTORY REPORT....................
A parts     Count: 85     Value of inventory: 191180.05
B parts     Count: 69     Value of inventory: 74764.16
C parts     Count: 77     Value of inventory: 50322.30
D parts     Count: 60     Value of inventory: 22416.49
Unknown     Count: 13     Value of inventory: 4282.68
*/ 