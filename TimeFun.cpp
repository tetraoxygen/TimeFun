/*
	Program:		TimeFun
	Author:			Charlie Welsh
	Date:			2020-11-25
	Dev Env:		Would be a rant -- you know what I use
	Description:	Converts between 24 and 12-hour time.
*/

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

// MARK: Prototypes

void getTime24(int &hour, int &minute);
void printTime24(int hour, int minute);
void printTime12(int hour, int minute);
void printTime12(int hour, int minute, bool isPM);
bool userWantsToContinue();

int main()
{
	do {
		int hour, minute;
		getTime24(hour, minute);
		
		std::cout << "That time in 12 hour format is: ";
		printTime12(hour, minute);
		std::cout << std::endl;
		
		std::cout << "That time in 24 hour format is: ";
		printTime24(hour, minute);
		std::cout << std::endl << std::endl;
	} while (userWantsToContinue());
	
	return 1;
}

// MARK: Functions

/*
	Function:		getTime24
	Description:	Gets 24 hour time from the user and passes the hours and minutes of the user-entered time by reference to their respective variables.
	Arguments:
		hour (i&):		variable to pass hour from input to
		minute (i&):	variable to pass minute from input to
	Return Value:
		None, all passed by reference.
*/

void getTime24(int &hour, int &minute){
	char ch;
	// this is more elegant than a do/while loop, I promise, because I have to print the error message anyways
	while (true) {
		std::cout << "Enter a time in 24 hour format (for example 21:41): ";
		std::cin >> hour >> ch >> minute;  
		
		// If cin 
		if (!std::cin.good() || hour > 23 || minute > 59) {
			std::cout << "That wasn't a valid time. ";
		} else {
			break;
		}
	}
	
	// Many things break if I don't clear the cin.good status and ignore whatever's on the current line (future cin calls get prefilled data, and that if statement would always get true).
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/*
	Function:		printTime24
	Description:	Prints 24 hour time from a given hour and minute value
	Arguments:
		hour (i):		hour to print as part of time
		minute (i):	minute to print as part of time
	Return Value:
		None
*/

void printTime24(int hour, int minute){
	std::cout << hour << ":" << std::setfill('0') << std::setw(2) << minute; // setw(2) and setfill(0) is there for the special case of the o'clocks -- otherwise you get 12:0, which isn't a time. 
}

// Strictly speaking, the latter printTime12() is the one I was asked to implement, but the former seemed significantly more elegant, so I used that instead. Still implemented the former, just to make sure.

/*
	Function:		printTime12
	Description:	Prints 12 hour time from a given hour and minute value
	Arguments:
		hour (i):		hour to print as part of time
		minute (i):	minute to print as part of time
	Return Value:
		None
*/

void printTime12(int hour, int minute){
	bool isPM = false;
	
	if (hour > 12) {
		hour = hour - 12;
		isPM = true;
	} else if (hour == 12) { // hour 12 presents a special case: there is no 00:00 p.m., but it's also not 12:00 a.m.
		isPM = true;
	}
	
	std::cout << hour << ":" << std::setfill('0') << std::setw(2) << minute; // setw(2) and setfill(0) is there for the special case of the o'clocks -- otherwise you get 12:0, which isn't a time. 
	
	if (isPM) {
		std::cout << " p.m.";
	} else {
		std::cout << " a.m.";
	}
}

/*
	Function:		printTime12
	Description:	Prints 12 hour time from a given hour and minute value, and a manually specified AM/PM
	Arguments:
		hour (i):		hour to print as part of time
		minute (i):		minute to print as part of time
		isPM (b):		if the specified time is PM. if false, time defaults to AM.
	Return Value:
		None
*/

void printTime12(int hour, int minute, bool isPM){
	std::cout << hour << ":" << std::setfill('0') << std::setw(2) << minute; // setw(2) and setfill(0) is there for the special case of the o'clocks -- otherwise you get 12:0, which isn't a time. 
	
	if (isPM) {
		std::cout << " p.m.";
	} else {
		std::cout << " a.m.";
	}
}
	
/*
	Function:		userWantsToContinue
	Description:	Prompts the user if they want to run the program again.
	Arguments:
		None
	Return Value:
		true if user wants to continue, false otherwise.
*/
	
bool userWantsToContinue(){
	std::string userInput;
	bool shouldContinue = false;
	
	std::cout << "Would you like to continue (y/N)? "; // changed this to follow the convention I've seen in a bunch of UNIX CLI utilities (which is also why I'm not using std::cin. 	
	
	getline(std::cin, userInput);
	
	// It's not worth importing another library just to convert this one string to lowercase. So I just hardcoded it. If the user puts anything other than y here, it just returns the existing value of shouldContinue, which is false. 
	if (userInput == "y" || userInput == "Y"){
		shouldContinue = true;
	}
	
	return shouldContinue;
}