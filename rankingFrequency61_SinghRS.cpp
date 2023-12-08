/*-------------------------------------------
// Course: COMP 150
// Last Name: Singh
// First Name: Rajveer
// Student ID: 300202522
// 
// File: rankingFrequency61_SinghRS
//
// Summary: Assigns pre-determined values in an integer array and counts the number of
			values that are apart of 10 interval frequencies from 0 to 100. First the 
			intervals are outputted without the count, and then they are again outputted
			with the counts included.            	           
//
*-------------------------------------------*/

#include<iostream>
using namespace std;

// Function prototypes
int arrayFrequency(int array[], int size, int min_interval, int max_interval);

int main()
{
	int a[]={75,25,56,78,43,86,100,73,80,90,0,73,35,65,100,78,80,85,35,50};
	int i,rank, Num = 20;
	int histo[11];
	
	for (i=0;i<Num;i++){
		cout <<a[i]<<" ";
	}
	
	// Before assigning frequency
	cout<<"\nBefore assigning frequency:"<<endl;
	cout<<"\t10 interval frequency across 0 to 100:" <<endl;
	for (i=0;i<=10;i++){
		histo[i]=0;
		if(i != 10)
			cout<<" \t"<< i*10 <<"-"<<(i+1)*10-1<< ":" << histo[i] <<endl;
		else
			cout<<" \t"<< i*10<< ":" << histo[i] <<endl;
	}
	
	// After assigning frequency
	cout << "\nAfter assigning frequency:" << endl;
	cout << "\t10 interval frequency across 0 to 100:" << endl;
	for (i=0;i<=10;i++){
		histo[i]=0;
		if(i != 10)
			cout<<" \t"<< i*10 <<"-"<<(i+1)*10-1<< ":" << arrayFrequency(a, Num, i*10, (i+1)*10-1) << endl;
		else
			cout<<" \t"<< i*10<< ":" << arrayFrequency(a, Num, i*10, i*10) <<endl;
	}
	
	 return 0; 
}

//Functions

/*-----------------------------------------------------------------------------------------*/
/* This function checks and counts the frequency a given interval in an array     		   */
/* Preconditions: array to check, array size, and minimum and maximum interval values      */
/* Postcondition: returns the number of times an interval occurs in the array              */
int arrayFrequency(int array[], int size, int min_interval, int max_interval)
{
	// Storing loop index and frequency starters 
	int i, frequency{0};
	
	// Searching array for frequencies
	for (i=0;i<size;i++)
	{
		if ((array[i] >= min_interval && array[i] <= max_interval))
		{
			frequency += 1;
		}
	}
	
	return frequency;
}
