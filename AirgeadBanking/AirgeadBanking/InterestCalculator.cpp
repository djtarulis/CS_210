#include <iostream>
#include <iomanip>	// setfill(), setw()

using namespace std;

#include "InterestCalculator.h" //Include header file so class InterestCalculator can be used

void InterestCalculator::SetInitialInvestment(double t_investmentAmount) {
	m_investment = t_investmentAmount;
}

void InterestCalculator::SetMonthlyDeposit(double t_monthlyDeposit) {
	m_deposit = t_monthlyDeposit;
}

void InterestCalculator::SetAnnualInterest(double t_annualInterest) {
	m_interest = t_annualInterest;
}

void InterestCalculator::SetNumberYears(int t_numYears) {
	m_years = t_numYears;
}

int i = 1;

void InterestCalculator::DisplayInputMenu(double t_investmentAmount, double t_monthlyDeposit, double t_annualInterest, int t_numYears) {	// Function to display initial user input menu
	cout << setfill('*') << setw(40) << " " << endl;
	cout << setfill('*') << setw(14) << "*" << "Data Input" << setfill('*') << setw(15) << "" << endl;
	cout << fixed << setprecision(2); // Include 2 decimal places for initial investment and monthly deposits
	cout << "Initial Investment Amount: $" << t_investmentAmount << endl;
	cout << "Monthly Deposit: $" << t_monthlyDeposit << endl;
	cout << fixed << setprecision(0); // No decimal places for interest and years
	cout << "Annual Interest: %" << t_annualInterest << endl;
	cout << "Number of Years: " << t_numYears << endl;
	system("pause");	// Press any key to continue . . .
	cout << endl;
}

void InterestCalculator::DisplayInterestWithDeposit(double t_investmentAmount, double t_monthlyDeposit, double t_annualInterest, int t_numYears) {
	cout << "==========Balance and Interest With Additional Monthly Deposits===========" << endl;
	cout << "Year" << setfill(' ') << setw(15) << " " << "Year End Balance" << setfill(' ') << setw(15) << " " << "Year End Earned Interest" << endl;
	cout << endl;
	for (i = 1; i <= t_numYears; ++i) {	// Loop that displays investment amount and interest for every year dictated by the user
		double monthlyInterest = ((t_investmentAmount + t_monthlyDeposit) * ((t_annualInterest / 100) / 12));	// Calculate monthly interest
		t_investmentAmount += (t_monthlyDeposit * 12) + (monthlyInterest * 12);
		cout << i << setfill(' ') << setw(24) << " " << fixed << setprecision(2) << t_investmentAmount << setfill(' ') << setw(24) << " " << monthlyInterest << endl;
		
	}
	cout << endl;
	system("pause");	// Press any key to continue . . .
}

void InterestCalculator::DisplayInterestWithoutDeposit(double t_investmentAmount, double t_monthlyDeposit, double t_annualInterest, int t_numYears) {
	cout << "==========Balance and Interest Without Additional Monthly Deposits===========" << endl;
	cout << "Year" << setfill(' ') << setw(15) << " " << "Year End Balance" << setfill(' ') << setw(15) << " " << "Year End Earned Interest" << endl;
	cout << endl;
	for (i = 1; i <= t_numYears; ++i) {	// Loop that displays investment amount and interest for every year dictated by the user
		double yearlyInterest = ((t_investmentAmount) * (t_annualInterest / 100));	// Calculate Yearly interest
		t_investmentAmount += yearlyInterest;
		cout << i << " " << setfill(' ') << setw(24) << " " << fixed << setprecision(2) << " " << t_investmentAmount << setfill(' ') << setw(24) << " " << yearlyInterest << endl;
	}
	cout << endl;
	system("pause");	// Press any key to continue . . .
}
