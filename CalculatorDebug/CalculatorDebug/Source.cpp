/*
 * Calculator.cpp
 *
 *  Date: [03/12/2022]
 *  Author: [Daniel Tarulis]
 */

#include <iostream>

using namespace std;

void main()
{
	char statement[100];
	double op1, op2;	// int switched to double to take in double from the user
	char operation;
	char answer = 'Y';		// Missing a semicolon and variable *char* must use single quotes
		while (toupper(answer) == 'Y') // Added toupper to include 'y' and 'Y'
		{
			cout << "Enter expression" << endl;
			cin >> op1 >> operation >> op2; // Op1 and Op2 swapped causing incorrect expressions
			
			// Added proper brackets to all if statments instead of semicolons

			if (operation == '+') {	// Must use single quotes when dealing with *char*
				cout << op1 << " + " << op2 << " = " << (op1 + op2) << endl;	// Arrows facing wrong direction for *cout*
			}
			if (operation == '-') {
				cout << op1 << " - " << op2 << " = " << (op1 - op2) << endl;	// Arrows facing wrong direction for *cout*
			}
			if (operation == '*') {
				cout << op1 << " * " << op2 << " = " << (op1 * op2) << endl;	// Missing semicolon at end of line, wrong symbol in output
			}
			if (operation == '/') {	// Indentation is wrong
				cout << op1 << " / " << op2 << " = " << (op1 / op2) << endl; // Wrong symbol in output
			}

			cout << "Do you wish to evaluate another expression? " << endl;
			cin >> answer;

			if (toupper(answer) == 'N') {	// Added if statement to end if user inputs 'n' or 'N'
				cout << "Program Finished";
			}
		}
}




