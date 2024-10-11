#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <fstream>

#pragma region Classes

#pragma region Distance Classes

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
		kilometresMultiplier = 1.0/1094.0;
		metresMultiplier = 1.0/1.094;
		centimetresMultiplier = 91.44;
		milesMultiplier = 1.0/1760;
		yardsMultiplier = 1093.613298;
	}
};
#pragma endregion

#pragma endregion

using namespace std;

enum UnitCategories { Distance, Energy, Mass, Time, Temperature, Area, Volume };

map<UnitCategories, vector<string>> units;

void DisplayMenu();

void ChoiceMenu();

void DisplayUnitsInCategory(UnitCategories category);

void DistanceConversionLogic(int unitOne, int unitTwo, double amount);

void LogCalculation(double amount, string originalUnitSuffix, double convertedAmount, string convertedUnitSuffix);

int main()
{
	vector<string> distanceUnits = { "Kilometre", "Metre", "Centimetre", "Mile", "Yard" };
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
	UnitCategories unitCategory = static_cast<UnitCategories>(unitCategoryInput);
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
#pragma region Display Functions

void DisplayMenu()
{
	cout << "Which unit type would you like to convert?\n";

	ChoiceMenu();
}

void ChoiceMenu()
{
	cout << "[0] Distance\n"
		<< "[1] Energy\n"
		<< "[2] Mass\n"
		<< "[3] Time\n"
		<< "[4] Area\n"
		<< "[5] Volume\n";
}

void DisplayUnitsInCategory(UnitCategories category)
{
	for (size_t i = 0; i < units[category].size(); i++)
	{
		cout << "[" << i << "] " << units[category][i] << endl;
	}
}

#pragma endregion

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
			unitOneSuffix = "km";
			break;
		
		// M
		case 1:
			unit = Metre(amount);
			unitOneSuffix = "m";
			break;
		
		// CM
		case 2:
			unit = Centimetre(amount);
			unitOneSuffix = "cm";
			break;
		
		// Mi
		case 3:
			unit = Mile(amount);
			unitOneSuffix = "mi";
			break;
		
		// Yards
		case 4:
			unit = Yard(amount);
			unitOneSuffix = "yd";
			break;
	}

	// Convert unit
	switch (unitTwo)
	{
		// to KM
	case 0:
		convertedAmount = unit.ConvertToKilometres();
		unitTwoSuffix = "km";
		break;

		// to M
	case 1:
		convertedAmount = unit.ConvertToMetres();
		unitTwoSuffix = "m";
		break;

		// to CM
	case 2:
		convertedAmount = unit.ConvertToCentimetres();
		unitTwoSuffix = "cm";
		break;

		// to Mi
	case 3:
		convertedAmount = unit.ConvertToMiles();
		unitTwoSuffix = "mi";
		break;

		// to Yards
	case 4:
		convertedAmount = unit.ConvertToYards();
		unitTwoSuffix = "yd";
		break;

	default:
		cout << "Invalid entry entered" << endl;
		break;
	}
	
	cout << "The amount " << amount << unitOneSuffix << " equals " << convertedAmount << unitTwoSuffix << endl;

	// Log output to file
	LogCalculation(amount, unitOneSuffix, convertedAmount, unitTwoSuffix);
}

#pragma endregion

void LogCalculation(double amount, string originalUnitSuffix, double convertedAmount, string convertedUnitSuffix)
{
	const string FILE_NAME = "log.txt";

	ofstream logFile(FILE_NAME, ios::app);
	
	if (logFile.is_open())
	{
		logFile << "Original amount: " << amount << " " << originalUnitSuffix << ", converted amount: " << convertedAmount << " " << convertedUnitSuffix << endl;
		logFile.close();
		return;
	}

	cerr << "Log file cannot be opened. Output was not saved\n";
}
