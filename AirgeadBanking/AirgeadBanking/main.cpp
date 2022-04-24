#include <iostream>
#include <iomanip>	// setfill(), setw()
#include <stdlib.h> // system("CLS")


using namespace std;

#include "InterestCalculator.h"	// Include header file so class InterestCalculator can be used

void main() {

	// Initialize variables to -1
	double investment = -1;
	double deposit = -1;
	double interest = -1;
	int years = -1;
	char val = 'Y';

	InterestCalculator obj1; // Create object to use with class functions
	
	while (val == 'Y') {	// Loop to continue input until user selects "N"
		
		obj1.DisplayInputMenu(investment, deposit, interest, years);	// Call initial display menu

		cout << "Enter investment amount: $" << endl;
		cin >> investment;
		cout << "Enter deposit amount: $" << endl;
		cin >> deposit;
		cout << "Enter interest amount:% " << endl;
		cin >> interest;
		cout << "Enter number of years: " << endl;
		cin >> years;
		system("CLS");	// Clear screen for less clutter
		cout << endl;

		obj1.DisplayInputMenu(investment, deposit, interest, years);	// Display user's inputs
		obj1.DisplayInterestWithoutDeposit(investment, deposit, interest, years);	// Display Interest table without deposits
		obj1.DisplayInterestWithDeposit(investment, deposit, interest, years);	// Display Interest table with deposits
		system("CLS");
		
		cout << "Would you like to try again? Y/N" << endl;
		cin >> val;
		val = toupper(val);	// Makes sure user input is uppercase
		system("CLS");	// Clear screen for less clutter
		
		while (val != 'Y' && val != 'N') {
			cout << "Please input \"Y\" or \"N\"";
			cin >> val;
			val = toupper(val);
			system("CLS");	// Clear screen for less clutter

			if (val == 'N') {	// Exit
				cout << "Completing Program. . .";
				exit;
			}
		}
	}	

	

	
}
