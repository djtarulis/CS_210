#define _CRT_SECURE_NO_WARNINGS
#include <time.h>       /* time_t, struct tm, time, localtime */
#include <iostream>	// std::cout, std::endl
#include <iomanip>	// std::setfill, std::setw
#include <stdlib.h>	// system(CLS);
#include <stdio.h>
using namespace std;

int DisplayClocks(int hours12, int minutes12, int seconds12, int hours24, int minutes24, int seconds24) {	// Function to write both clocks to screen	

	std::cout << std::setfill('*') << std::setw(26) << "     " << std::setfill('*') << std::setw(26) << " " << endl;	// First line of "*"
	std::cout << "*" << std::setfill(' ') << std::setw(16) << "12 Hour Clock" << std::setfill(' ') << std::setw(4) << "  *" << "     "
		<< "*" << std::setfill(' ') << std::setw(18) << "24 Hour Clock" << std::setfill(' ') << std::setw(6) << "  *" << endl;
		// 12 hour clock
	std::cout << "*" << std::setfill(' ') << std::setw(6) << " " << std::setfill('0') << std::setw(2) << hours12 << ":" << std::setfill('0') << std::setw(2) 
		<< minutes12 << ":" << std::setfill('0') << std::setw(2) << seconds12 << std::setfill(' ') << std::setw(6) << "  *" << "     "
		// 24 hour clock
		<< "*" << std::setfill(' ') << std::setw(8) << " " << std::setfill('0') << std::setw(2) << hours24 << ":" << std::setfill('0') << std::setw(2) << minutes24 << ":" << std::setfill('0') << std::setw(2)
		<< seconds24 << std::setfill(' ') << std::setw(8) << "  *" << endl;
	std::cout << std::setfill('*') << std::setw(26) << "     " << std::setfill('*') << std::setw(26) << " " << endl;	// Last line of "*"
		
	return 0;

}

void DisplaySelection() {	// Function to display selection menu for user
	
	std::cout << std::setfill('*') << std::setw(26) << " " << endl;
	std::cout << "*" << std::setfill(' ') << std::setw(19) << "1 - Add One Hour" << std::setfill(' ') << std::setw(5) << "  *" << endl;
	std::cout << "*" << std::setfill(' ') << std::setw(20) << "2 - Add One Minute" << std::setfill(' ') << std::setw(4) << "  *" << endl;
	std::cout << "*" << std::setfill(' ') << std::setw(20) << "3 - Add One Second" << std::setfill(' ') << std::setw(4) << "  *" << endl;
	std::cout << "*" << std::setfill(' ') << std::setw(19) << "4 - Exit Program" << std::setfill(' ') << std::setw(5) << "  *" << endl;
	std::cout << std::setfill('*') << std::setw(26) << " " << endl;

}

void main()
{
	
	time_t current_time; // Get local time from system clock
	struct tm  local_time;

	time(&current_time);
	localtime_s(&local_time, &current_time);

	int Hour12 = local_time.tm_hour % 12;	// Set Variables that can be used with display function	
	int Min12 = local_time.tm_min;	
	int Sec12 = local_time.tm_sec;	
	int Hour24 = local_time.tm_hour;
	int Min24 = local_time.tm_min;
	int Sec24 = local_time.tm_sec;
	string userVal;	// userVal that will be entered by user
	
	DisplayClocks(Hour12, Min12, Sec12, Hour24, Min24, Sec24);	// Call displayClocks on program start
	DisplaySelection();	// Call DisplaySelection after display clocks
	cin >> userVal;	// Take user input to modify clock display

	while (!( userVal == "Exit")) {
		if (userVal == "1") {
			// Add One Hour to Clocks
			if (Hour12 >= 12) {
				Hour12 = 1 ;
			}
			else {
				Hour12 += 1;
			}
			if (Hour24 == 23) {
				Hour24 = 0;
			}
			else {
				Hour24 += 1;
			}
			system("CLS"); // Clear screen test... working...
			DisplayClocks(Hour12, Min12, Sec12, Hour24, Min24, Sec24);	// Call displayClocks on program start
			DisplaySelection();	// Call DisplaySelection after display clocks
			cin >> userVal;
		}

		else if (userVal == "2") {
			// Add One Minute to Clocks
			if ((Min12 == 59) || (Min24 == 59)) {
				Min12 = 0;
				Min24 = 0;
			}
			else {
				Min12 += 1;
				Min24 += 1;
			}
			system("CLS"); // Clear screen test... working...
			DisplayClocks(Hour12, Min12, Sec12, Hour24, Min24, Sec24);	// Call displayClocks on program start
			DisplaySelection();	// Call DisplaySelection after display clocks
			cin >> userVal;
		}

		else if (userVal == "3") {
			// Add One Second to Clocks
			if ((Sec12 == 59) || (Sec24 == 59)) {
				Sec12 = 0;
				Sec24 = 0;
			}
			else {
				Sec12 += 1;
				Sec24 += 1;
			}
			system("CLS"); // Clear screen test... working...
			DisplayClocks(Hour12, Min12, Sec12, Hour24, Min24, Sec24);	// Call displayClocks on program start
			DisplaySelection();	// Call DisplaySelection after display clocks
			cin >> userVal;
		}

		else if (userVal == "4") {
			// Exit Program
			cout << "Program Ended" << endl;
			break;
		}

		else{
			// Prompt user to input correct selection when not userVal ! (1-4)
			system("CLS"); // Clear screen test... working...
			DisplayClocks(Hour12, Min12, Sec12, Hour24, Min24, Sec24);
			DisplaySelection();
			cout << "Error: Enter a selection 1 - 4." << endl;
			cin >> userVal;
		}	
	}
}