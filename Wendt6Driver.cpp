// written by brandon wendt on april 28th 2022
#include <iostream>
#include <iomanip>
#include <string>
#include "division.h"
using namespace std;

//Function Prototypes
int menu(); // constructor
Division getDivisionInfo(); //This function will prompt the user to enter all 4 data members of the class and store them in a Division object that will be returned to main
Division addToSales(Division &a); //This function will prompt the user to enter the amount by which the year to date sales figure should be increased and then call the increaseSales function to update the yearToDate member. Return the updated Division class object to main.
Division removeFromSales(Division &a); //This function will prompt the user to enter the amount by which the year to date sales figure should be decreased and then call the decreaseSales function to update the yearToDate member. Return the updated Division class object to main.
Division updateTarget(Division &a); //This function will prompt the user to enter the new target sales amount and then update the salesTarget member. Return the updated Division class object to main.

int main()
{
	// Declare a Division object
	Division northEast;

	// Call getDivisionInfo so the user can enter the information
  northEast = getDivisionInfo();
  
	int choice = 0;  // you will need to initialize choice to something prior to while
	while (choice != 4)
	{
		choice = menu();
		if (choice == 1)
		{
			// call addToSales
      addToSales(northEast);
		}
		else if (choice == 2)
		{
			// call removeFromSales
      removeFromSales(northEast);
		}
		else if (choice == 3)
		{
			// call updateTarget
      updateTarget(northEast);
		}
		else if (choice != 4)
		{
			cout << "Invalid menu choice" << endl;
		}

	}

	// Call the display function
  northEast.display();

	return 0;
}

//************************************
// menu function
//************************************
int menu()
{
	int choice;
	cout << "Menu choices : " << endl;
	cout << "1 - Add to Sales" << endl;
	cout << "2 - Remove from Sales" << endl;
	cout << "3 - Update target" << endl;
	cout << "4 - Quit" << endl;
	cout << "Enter your menu choice : ";
	cin >> choice;
	
	return choice;
}

//************************************
// funtion to input data into object
//************************************
Division getDivisionInfo()
{
  Division a;
  string temp1;
  int temp2;
  double temp3;
  double temp4;
  cout << "Enter division code " << endl;
  getline(cin, temp1);
  a.setDivCode(temp1);
  cout << "Enter number of employees in the division" << endl;
  cin >> temp2;
  a.setEes(temp2);
  cout << "Enter dollar amount representing the sales amount to date" << endl;
  cin >> temp3;
  a.setYearToDate(temp3);
  cout << "Enter the target dollar amount for sales" << endl;
  cin >> temp4;
  a.setSalesTarget(temp4);
  return a;
}

//***************************
// function to add to sales
//***************************
Division addToSales(Division &a)
{
  double temp1;
  cout << "Enter the amount by which the year to date sales figure should be increased" << endl;
  cin >> temp1;
  a.increaseSales(temp1);
  
  return a;
}

//***************************
// function to remove from sales
//***************************
Division removeFromSales(Division &a)
{
  double temp1;
  cout << "Enter the amount by which the year to date sales figure should be decreased" << endl;
  cin >> temp1;
  a.decreaseSales(temp1);
  return a;
}

//***************************
// function to update target
//***************************
Division updateTarget(Division &a)
{
  double temp1;
  cout << "Enter the updated target sales amount " << endl;
  cin >> temp1;
  a.setSalesTarget(temp1);
  
  return a;
}
