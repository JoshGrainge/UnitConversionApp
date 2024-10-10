#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>

class DistanceUnit
{
protected:
	double kilometresMultiplier = 1;
	double metresMultiplier = 1;
	double centimetresMultiplier = 1;
	double milesMultiplier = 1;
	double yardsMultiplier = 1;

public:
	double amount = 0;

	DistanceUnit(double _amount)
	{
		amount = _amount;
	}

	double ConvertToKilometres()
	{
		return amount * kilometresMultiplier;
	}

	double ConvertToMetres()
	{
		return amount * metresMultiplier;
	}

	double ConvertToCentimetres()
	{
		return amount * centimetresMultiplier;
	}

	double ConvertToMiles()
	{
		return amount * milesMultiplier;
	}

	double ConvertToYards()
	{
		return amount * yardsMultiplier;
	}

};

class Kilometre : public DistanceUnit
{
public:
	Kilometre(double amount) : DistanceUnit(amount)
	{
		kilometresMultiplier = 1;
		metresMultiplier = 100;
		centimetresMultiplier = 100000;
		milesMultiplier = 0.621371;
		yardsMultiplier = 1093.613298;
	}
};

using namespace std;

enum UnitCategories { Distance, Energy, Mass, Time, Temperature, Area, Volume };

map<UnitCategories, vector<string>> units;

void DisplayMenu();

void ChoiceMenu();

void DisplayUnitsInCategory(UnitCategories category);

int main()
{
	vector<string> distanceUnits = { "Kilometre", "Metre", "Centimetre", "Milimetre", "Mile", "Yard" };
	units[Distance] = distanceUnits;

	vector<string> massUnits = { "Kilograms", "Grams", "Miligrams", "Ounce", "Pound" };
	units[Mass] = massUnits;

	vector<string> timeUnits = { "Milliseconds", "Seconds", "Minutes", "Hours", "Days" };
	units[Mass] = massUnits;

	DisplayMenu();

	int unitCategoryInput;
	cin >> unitCategoryInput;

	system("CLS");
	cout << "Which measurement would you like to use?\n\n";

	// Get first measurment
	UnitCategories unitCategory = static_cast<UnitCategories>(unitCategoryInput - 1);
	DisplayUnitsInCategory(unitCategory);

	cout << endl;

	int unitOneType;
	cin >> unitOneType;

	// Get second measurment
	system("CLS");
	cout << "What measurement would you like to convert that to?\n\n";
	DisplayUnitsInCategory(unitCategory);

	int unitTwoType;
	cin >> unitTwoType;

	cout << "Enter amount in " << units[unitCategory][unitOneType] << endl << endl;
	double amount;
	cin >> amount;


	// Just testing kilometre conversion stuff
	Kilometre km = Kilometre(amount);
	cout << "Converted to metres: " << km.ConvertToMetres() << endl;
	cout << "Converted to centimetres: " << km.ConvertToCentimetres() << endl;
	cout << "Converted to miles: " << km.ConvertToMiles() << endl;
	cout << "Converted to yards: " << km.ConvertToYards() << endl;


	switch (unitCategoryInput)
	{
	case Distance:

		break;

	case Energy:

		break;

	case Mass:

		break;

	case Time:

		break;

	case Temperature:

		break;

	case Area:

		break;

	case Volume:

		break;

	defaut:
		cout << "Invalid entry please try again\n";
		break;
	}

	return 0;

}

void DisplayMenu()
{
	cout << "Which unit type would you like to convert?\n";

	ChoiceMenu();
}

void ChoiceMenu()
{
	cout << "[1] Distance\n"
		<< "[2] Energy\n"
		<< "[3] Mass\n"
		<< "[4] Time\n"
		<< "[5] Area\n"
		<< "[6] Volume\n";
}

void DisplayUnitsInCategory(UnitCategories category)
{
	for (size_t i = 0; i < units[category].size(); i++)
	{
		cout << "[" << i << "] " << units[category][i] << endl;
	}
}