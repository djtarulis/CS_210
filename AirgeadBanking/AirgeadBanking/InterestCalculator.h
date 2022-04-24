#ifndef AIRGEADBANKING_INTERESTCALCULATOR_H
#define AIRGEADBANKING_INTERESTCALCULATOR_H

#include <string>
using namespace std;

class InterestCalculator	// Define class
{
public:
	// Declare all needed functions and variables for class
	void SetInitialInvestment(double t_investmentAmount);
	void SetMonthlyDeposit(double t_monthlyDeposit);
	void SetAnnualInterest(double t_annualInterest);
	void SetNumberYears(int t_numYears);
	void DisplayInputMenu(double t_investmentAmount, double t_monthlyDeposit, double t_annualInterest, int t_numYears);
	void DisplayInterestWithDeposit(double t_investmentAmount, double t_monthlyDeposit, double t_annualInterest, int t_numYears);
	void DisplayInterestWithoutDeposit(double t_investmentAmount, double t_monthlyDeposit, double t_annualInterest, int t_numYears);

private:
	double m_investment = 0;
	double m_deposit = 0;
	double m_interest = 0;
	int m_years = 0;
};

#endif