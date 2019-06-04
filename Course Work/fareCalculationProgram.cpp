
#include <iostream>
#include <string>

using namespace std;

int main()
{

	cout << "Age of rider: ";
	double age;					//DOUBLE???
	cin >> age;
	cin.ignore(10000, '\n');

	cout << "Student? (y/n): ";
	string student;
	getline(cin, student);

	cout << "Destination: ";
	string destination;
	getline(cin, destination);

	cout << "Number of zone boundaries crossed: ";
	int zones;
	cin >> zones;
							//cin.ignore(10000, '\n');

	double fare;
	cout.setf(ios::fixed);  //UNNECESSARY
	cout.precision(2);


	if (age < 18 && age >= 0 && (zones == 0 || zones == 1) && (student == "y" || student == "n") && destination != "")   //close trip discount
	{
		fare = 0.65;
		cout << "---" << endl;
		cout << "The fare to " << destination << " is $" << fare << endl;
	}

	else if (age >= 18 && age < 65 && student == "y" && (zones == 0 || zones == 1) && destination != "")   //student discount
	{
	
	fare = 0.65;
	cout << "---" << endl;
	cout << "The fare to " << destination << " is $" << fare << endl;
	}

	else if (age >= 65 && student == "y" && zones == 1 && destination != "")   //senior student discount
	{
		fare = 0.65;
		cout << "---" << endl;
		cout << "The fare to " << destination << " is $" << fare << endl;
	}

	else if (age >=65 && zones == 0 && (student == "y" || student == "n") && destination != "") //senior zero zones discount
	{
		fare = 0.45;
		cout << "---" << endl;
		cout << "The fare to " << destination << " is $" << fare << endl;
	}

	else if (age >= 65 && (student == "y" || student == "n") && zones >= 0 && destination != "")  //senior fare
	{
		fare = 0.55 + 0.25 * zones;
		cout << "---" << endl;
		cout << "The fare to " << destination << " is $" << fare << endl;
	}

	else if (age < 65 && age >= 0 && (student == "y" || student == "n") && zones >= 0 && destination != "") //non senior fare
	{
		fare = 1.35 + 0.55 * zones;
		cout << "---" << endl;
		cout << "The fare to " << destination << " is $" << fare << endl;
	}

	else if (age < 0)													//start of error messages
	{
		cout << "The age must not be negative" << endl;
	}

	else if (destination=="")
	{
		cout << "You must enter a destination" << endl;
	}

	else if (zones < 0)
	{
		cout << "The number of zone boundaries crossed must not be negative" << endl;
	}

	else if (student != "y" || student != "n")			//keep at bottom?
	{
		cout << "You must enter y or n" << endl;
	}

	}



