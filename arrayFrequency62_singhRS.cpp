/*-------------------------------------------
// Course: COMP 150
// Last Name: Singh
// First Name: Rajveer
// Student ID: 300202522
// 
// File: arrayFrequency62_singhRS
//
// Summary: Reads 10 integers from the user and stores them in an array. Within the array,
			the maximum number, the frequency of the maximum number, and the positions of
			the maximum number are found and outputted to the user.             	           
//
*-------------------------------------------*/
#include<iostream>
using namespace std;

// Storing the maximum size of arrays globally 
const int SIZE = 10;

int main()
{
	// Storing arrays, array sizes, maximum number, counter, and index position 
	int user_nums[SIZE], max_num_positions[SIZE], user_nums_size{0}, positions_size{0}; 
	int i, number, max_number{0}, count{0}, position;
	
	// Storing 10 integers from the user in an array
	cout << "Enter any number 10 times: " << endl;
	for (i=1; i<=10; i++)
	{
		cout << "\tNumber #" << i << ": ";
		cin >> number;
		if (user_nums_size < SIZE)
		{
			user_nums[i-1] = number;
			user_nums_size += 1;
		}
		// Calculating the maximum number
		if (number > max_number)
		{
			max_number = number;
		}
	}
	
	// Counting the number of max num occurrences and adding the positions to an array
	for (i=0, position=1; i<user_nums_size; i++, position++)
	{
		if (user_nums[i] == max_number)
		{
			count += 1;
			positions_size++;
			max_num_positions[positions_size-1] = position;
		}
	}
	
	// Outputting the numbers entered by the user
	cout << "You entered  ";
	for (i=0; i<user_nums_size; i++)
	{
		cout << user_nums[i] << " ";
	}
	
	// Outputting the summary
	cout << endl << endl << max_number << " is the largest number." << endl;
	cout << max_number << " appears " << count << " times, which is shown at ";
	
	for (i=0; i<positions_size; i++)
	{
		if (i == positions_size-1)
		{
			cout << "and #" << max_num_positions[i] << ".";
		}
		else
		{
			cout << "#" << max_num_positions[i] << ", ";
		}
	}
	
	return 0;
}
