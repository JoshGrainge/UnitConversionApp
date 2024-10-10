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

	DistanceUnit() {}

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

class Metre : public DistanceUnit
{
public:
	Metre(double amount) : DistanceUnit(amount)
	{
		kilometresMultiplier = 0.001;
		metresMultiplier = 1;
		centimetresMultiplier = 100;
		milesMultiplier = 1.0/1609;
		yardsMultiplier = 1.0/1.094;
	}
};

class Centimetre : public DistanceUnit
{
public:
	Centimetre(double amount) : DistanceUnit(amount)
	{
		kilometresMultiplier = 1.0/100000;
		metresMultiplier = 0.01;
		centimetresMultiplier = 1;
		milesMultiplier = 1.0/160900;
		yardsMultiplier = 1.0/91.44;
	}
};

class Mile : public DistanceUnit
{
public:
	Mile(double amount) : DistanceUnit(amount)
	{
		kilometresMultiplier = 1.60934;
		metresMultiplier = 1609.34;
		centimetresMultiplier = 160934;
		milesMultiplier = 0.621371;
		yardsMultiplier = 1760;
	}
};

class Yard : public DistanceUnit
{
public:
	Yard(double amount) : DistanceUnit(amount)
	{
		kilometresMultiplier = 1.0/1094;
		metresMultiplier = 1.0/1.094;
		centimetresMultiplier = 91.44;
		milesMultiplier = 1.0/1760;
		yardsMultiplier = 1093.613298;
	}
};

using namespace std;

enum UnitCategories { Distance, Energy, Mass, Time, Temperature, Area, Volume };

map<UnitCategories, vector<string>> units;

void DisplayMenu();

void ChoiceMenu();

void DisplayUnitsInCategory(UnitCategories category);

void DistanceConversionLogic(int unitOne, int unitTwo, double amount);


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

	switch (unitCategory)
	{
		case Distance:
			DistanceConversionLogic(unitOneType, unitTwoType, amount);
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

# pragma region ConversionLogic
void DistanceConversionLogic(int unitOne, int unitTwo, double amount)
{
	DistanceUnit unit;
	string unitOneSuffix, unitTwoSuffix;
	double convertedAmount = 0;

	// TODO make this more elegant so that its not case 0. I don't want to make it strings either though due to spelling errors easily causing problems
	// Create object for first unit
	switch (unitOne)
	{
		// KM
		case 0:
			unit = Kilometre(amount);
			break;
		
		// M
		case 1:
			unit = Metre(amount);
			break;
		
		// CM
		case 2:
			unit = Centimetre(amount);
			break;
		
		// Mi
		case 3:
			unit = Mile(amount);
			break;
		
		// Yards
		case 4:
			unit = Yard(amount);
			break;
	}

	// Convert unit
	switch (unitTwo)
	{
		// to KM
	case 0:
		convertedAmount = unit.ConvertToKilometres();
		break;

		// to M
	case 1:
		convertedAmount = unit.ConvertToMetres();
		break;

		// to CM
	case 2:
		convertedAmount = unit.ConvertToCentimetres();
		break;

		// to Mi
	case 3:
		convertedAmount = unit.ConvertToMiles();
		break;

		// to Yards
	case 4:
		convertedAmount = unit.ConvertToYards();
		break;
	}

	cout << "The amount " << amount << unitOneSuffix << " equals " << convertedAmount << unitTwoSuffix << endl;
}

#pragma endregion
