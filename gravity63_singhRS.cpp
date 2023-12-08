/*-------------------------------------------
// Course: COMP 150
// Last Name: Singh
// First Name: Rajveer
// Student ID: 300202522
// 
// File: gravity63_singhRS
//
// Summary: Calculates the weight of a car in newtons and pounds that is located on either Earth or the Moon.
			The weight is calculated based on the mass of the car, which is given in kg by the user by entering
			the mass or choosing it from a list. The mass in pounds and weight in newtons is outputted to the user.
			
			Earth gravity value from: https://www.calculatorsoup.com/calculators/physics/weight.php
			Moon gravity value from: https://www.vcalc.com/wiki/weight-on-the-moon          	           
//
*-------------------------------------------*/

#include<iostream>
#include<string>
using namespace std;

// Function prototypes
double carWeightNewton(double mass, int location);
double kgToPounds (double kilograms);
void carSelectionList (string &selected_car, double &mass);
void inputError(int &input, int start_num, int end_num);

int main()
{
	// Storing information, selections, and calculations
	int location_selection, mass_selection, exit_program; 
	string car_locations[2] = {"Earth", "the Moon"}, car_model; 
	double car_mass, car_weight, mass_pounds;
	
	// Outputting the welcome message and program description
	cout << "\n\n=============================================================================" << endl;
	cout << "\t\t# Welcome to the CAR WEIGHT CALCULATOR #" << endl;
	cout << "\n\n---> Calculates the weight of a car on Earth or the Moon, based on its mass."
			"\n---> Allows user to enter the mass of a car, or choose from a list of cars."
			"\n---> Takes mass value in kg, but outputs the weight in newtons and lb." << endl;
	cout << "=============================================================================\n\n" << endl;
	
	
	// Looping until user selects to exit the program
	do {
		// Prompting the user to select the calculation for Earth or the Moon
		cout << "Select the car location:" << endl;
		cout << "[1] Earth"
				"\n[2] Moon" << endl;
		cout << "\nSelection: ";
		cin >> location_selection;
		inputError(location_selection, 1, 2); // error checking
		
		// Prompting the user to select the operation used to choose the mass  
		cout << "\nSelect the car mass operation:" << endl;
		cout << "[1] Manually enter the mass of a car"
				"\n[2] Choose from a list of available cars" << endl;
		cout << "\nSelection: ";
		cin >> mass_selection;
		inputError(mass_selection, 1, 2); // error checking

		// Getting a mass value inputted by the user
		if (mass_selection == 1)
		{
			cout << "\nEnter the mass of a car (in kg): ";
			cin >> car_mass;
			while(car_mass < 0) // error checking
			{
				cout << "\nError. Mass cannot be less than 0." << endl;
				cout << "Enter a correct value: ";
				cin >> car_mass;
			}
		}
		// Getting a mass value from a list of cars
		else if (mass_selection == 2)
		{
			cout << endl << endl;
			carSelectionList(car_model, car_mass); 
		}
		
		// Calculating the weight in newtons and pounds
		car_weight = carWeightNewton(car_mass, location_selection);
		mass_pounds = kgToPounds(car_mass);
		
		
		// Outputting the prompt displaying the car weight in newtons and pounds depending on the mass operation 
		cout << "\n--------------------------------------------------------------------------------------------------------------" << endl;
		if (mass_selection == 1) // Mass inputed by the user operation
		{
			cout << "A " << car_mass << " mass car on " << car_locations[location_selection-1] << " weighs " << car_weight << " in Newtons." << endl;
			cout << "A " << car_mass << " mass car weighs " << mass_pounds << " in Pounds." << endl;
		}
		else if (mass_selection == 2) // Mass selected from a list operation
		{
			cout << "The " << car_model << " on " << car_locations[location_selection-1] << " weighs " << car_weight << " in Newtons." << endl;
			cout << "The " << car_model << " weigns " << mass_pounds << " in Pounds." << endl;
		}
		cout << "--------------------------------------------------------------------------------------------------------------" << endl;
		
		
		// Prompting user to calculate again or exit program
		cout << "\n\nCalculate another weight or EXIT?" << endl;
		cout << "[1] Calculate another weight"
				"\n[2] EXIT program" << endl;
		cout << "\nSelection: ";
		cin >> exit_program;
		inputError(exit_program, 1, 2); // error checking 
		cout << endl << endl; 
		
	} while(exit_program != 2); // End of loop
	
	// Exiting the program
	cout << "Exiting program..." << endl;
	cout << "PROGRAM TERMINATED." << endl;
	
	return 0;
}

// Functions

/*------------------------------------------------------------*/
/* This function handles integer range value errors        	  */
/* Preconditions: variable to check, 2 numbers for the range  */
/* Postcondition: none										  */ 
void inputError(int &input, int start_num, int end_num)
{
	while (!(input >= start_num && input <= end_num))
	{
		cout << "\n******************************"  << endl;
		cout << "ERROR: Invalid value entered" << endl;
		cout << "******************************"  << endl;
		cout << "Try again, type a num " << start_num << " - " << end_num << ":  ";
		cin >> input;
	}
}

/*-----------------------------------------------------------------------------------------------------*/
/* This function displays a list of cars with corresponding masses for selection   					   */
/* Preconditions: variable to store the selected car name and mass                                     */
/* Postcondition: stores the name and mass of the selected car in variables selected_car and car_mass  */
void carSelectionList (string &selected_car, double &car_mass)
{
	int car_choice;
	string available_cars[9] = {"2015 Tesla Model S", "2014 Buick Verano", "2013 Ford Taurus", "2014 Nissan Versa", "2014 Kia Cadenza", "2013 Toyota Matrix", "2013 Dodge Durango", "2012 Nissan Cube", "2014 BMW 5-Series"};
	double available_cars_mass[9] = {2107.39, 1496.85, 1831.15, 1067.76, 1663.78, 1309.97, 2157.29, 1255.54, 1730.00};

	cout << "Choose a car from the list:" << endl;
	cout << "(1)  2015 Tesla Model S  ----> 2107.39  kg\n"
			"(2)  2014 Buick Verano   ----> 1496.85  kg\n"
			"(3)  2013 Ford Taurus    ----> 1831.15  kg\n"
			"(4)  2014 Nissan Versa   ----> 1067.76  kg\n"
			"(5)  2014 Kia Cadenza    ----> 1663.78  kg\n"
			"(6)  2013 Toyota Matrix  ----> 1309.97  kg\n"
			"(7)  2013 Dodge Durango  ----> 2157.29  kg\n"
			"(8)  2012 Nissan Cube    ----> 1255.54  kg\n"
			"(9)  2014 BMW 5-Series   ----> 1730.00  kg" << endl;
	
	cout << "\nEnter a number 1-9 to select the car: ";
	cin >> car_choice;
	inputError(car_choice, 1, 9);

	selected_car = available_cars[car_choice-1];
	car_mass = available_cars_mass[car_choice-1]; 	
}

/*--------------------------------------------------------------------------------*/
/* This function calculates the weight of a car on Earth or the Moon in newtons   */
/* Preconditions: the mass of the car and the car location (Earth/Moon)		      */
/* Postcondition: returns the weight of the car in newtons						  */
double carWeightNewton(double mass, int location)
{
	// Storing acceleration due to gravity for the earth and moon, and uncalculated weight
	const double earth_gravity{9.80665};
	const double moon_gravity{1.622};
	double weight;
	
	if (location == 1) // If location = earth
	{
		weight = mass * earth_gravity;  
	}
	else if (location == 2) // If location = the moon
	{
		weight = mass * moon_gravity;
	}
	
	return weight; 
}

/*----------------------------------------------------------*/
/* This function converts kilograms to pounds        	 	*/
/* Preconditions: the kilograms to be converted             */
/* Postcondition: returns the equivalent pounds	            */
double kgToPounds (double kilograms)
{
	double pounds;
	
	pounds = kilograms * 2.20462;
	return pounds; 
}
