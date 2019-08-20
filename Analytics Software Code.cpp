#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int y;

//GLOBAL VARIABLES FOR NUMBER OF GATES
const int RegionalGates = 5,
DomesticShortGates = 10,
DomesticLongGates = 10,
InternationalGates = 5;
const int totalgates = 30;

//GLOBAL VARIABLES FOR DOMESTIC & INTERNATIONAL FLIGHTS PER GATE
const double Gate_Regional = 12,
Gate_DomesticShort = 10,
Gate_DomesticLong = 10,
Gate_International = 7;
const int totalflights = 39;

//GLOBAL VARIABLES FOR GATE PREDICTED GROWTH
const double Growth_Regional = 1.04,
Growth_DomesticShort = 1.05,
Growth_DomesticLong = 1.06,
Growth_International = 1.10;

//GLOBAL VARIABLES FOR AVERAGE NUMBER OF SEATS ON FLIGHT
const double Seats_Regional = 100,
Seats_DomesticShort = 166,
Seats_DomesticLong = 150,
Seats_International = 230;

//GLOBAL VARIABLES FOR NUMBER OF DAYS & YEARS
const int years = 10,
months = 12,
days = 356;
const int t = 1;

//Global Variables For Regional Aircraft Usage Calculators
double aircraftseats = 120;
double annualregionalflights = RegionalGates * Gate_Regional * days;
double annualregionalseats = annualregionalflights * aircraftseats;

//Global Variables For Short Domestic Aircraft Usage Calculators
double dsaircraftseats = 180;
double annualdsflights = DomesticShortGates * Gate_DomesticShort * days;
double annualdsseats = annualdsflights * dsaircraftseats;

//Global Variables For Long Domestic Aircraft Usage Calculators
double dlaircraftseats = 162;
double annualdlflights = DomesticLongGates * Gate_DomesticLong * days;
double annualdlseats = annualdlflights * dlaircraftseats;

//Global Variables For International Aircraft Usage Calculators
double internationalseats = 243;
double annualintlflights = InternationalGates * Gate_International * days;
double annualintlseats = annualintlflights * internationalseats;


struct Calculations
{
	double timespan[t];
	double total[days];
};

struct flightinformation
{
	double dailyregional;
	double dailydomesticshort;
	double dailydomesticlong;
	double dailyinternational;
};

struct futureuse 
{
	double regionaldemand;
	double domesticshortdemand;
	double domesticlongdemand;
	double internationaldemand; 
};
struct flightdata
{
	Calculations airplane;
	flightinformation passengers;
	futureuse analizer;
};

//FUNCTION PROTOTYPES
void Daily(struct flightdata Annual[], int);
void Yearly(struct flightdata Annual[], int);
void Monthly(struct flightdata Annual[], int);
void PassengerData(struct flightdata Annual[], int);
void RegionalCalculations(struct flightdata Annual[], int);
void Report(struct flightdata Annual[], int);

int main()
{
	flightdata Annual[years];
	cout << "MG Aircraft Data Calculator " << endl
		<< " " << endl
		<< "For How Many Years Would You Like To Forecast Gate Traffic Trends?" << endl;
	cin >> y;

	while (y > 10 || y < 0)//validating input data
	{
		cout << "Invaild Number Of Years." << endl;
		cout << "Enter Number Of Years In-Between 1 - 10 " << endl;
		cin >> y;
	}

	for (int airport = 0; airport < 1; airport++)
	{
		Daily(Annual, airport);
		Yearly(Annual, airport);
		Monthly(Annual, airport);
		PassengerData(Annual, airport);
		RegionalCalculations(Annual, airport);
		Report(Annual, airport);
	}
	return 0;
}

void Daily(struct flightdata Annual[], int airport)
{
	Annual[airport].airplane.total[1] = (totalgates) * (totalflights);
}

void Monthly(struct flightdata Annual[], int airport)
{
	Annual[airport].airplane.total[30] = Annual[airport].airplane.total[1] * 30;
}

void Yearly(struct flightdata Annual[], int airport)
{
	Annual[airport].airplane.total[356] = Annual[airport].airplane.total[1] * days;
	Annual[airport].airplane.timespan[1] = Annual[airport].airplane.total[356] * y;
}

void PassengerData(struct flightdata Annual[], int airport)
{
	Annual[airport].passengers.dailyregional = RegionalGates * Gate_Regional * Seats_Regional;
	Annual[airport].passengers.dailydomesticshort = DomesticShortGates * Gate_DomesticShort * Seats_DomesticShort;
	Annual[airport].passengers.dailydomesticlong = DomesticLongGates * Gate_DomesticLong * Seats_DomesticLong;
	Annual[airport].passengers.dailyinternational = InternationalGates * Gate_International * Seats_International;
}

void RegionalCalculations(struct flightdata Annual[], int airport)
{
	Annual[airport].analizer.regionaldemand = RegionalGates * Seats_Regional * Gate_Regional * Growth_Regional * days;
	Annual[airport].analizer.domesticshortdemand = DomesticShortGates * Seats_DomesticShort * Gate_DomesticShort * Growth_DomesticShort * days;
	Annual[airport].analizer.domesticlongdemand = DomesticLongGates * Seats_DomesticLong * Gate_DomesticLong * Growth_DomesticLong * days;
	Annual[airport].analizer.internationaldemand = InternationalGates * Seats_International * Gate_International * Growth_International * days;
}


void Report(struct flightdata Annual[], int airport)
{
	cout << "The Total Number of Flights for " << y << " years" << endl
		<< Annual[airport].airplane.timespan[1] << endl
		<< "Total Number of Flights Daily " << endl
		<< Annual[airport].airplane.total[1] << endl
		<< "Total Number of Fights Monthly" << endl
		<< Annual[airport].airplane.total[30] << endl
		<< "Total Number of Flights Yearly" << endl
		<< Annual[airport].airplane.total[1] * days << endl;
	cout << "Categorized Flight Information" << endl
		<< Annual[airport].passengers.dailyregional << " Daily Regional Passengers" << endl
		<< Annual[airport].passengers.dailydomesticshort << " Daily Domestic Short Route Passengers" << endl
		<< Annual[airport].passengers.dailydomesticlong << " Daily Domestic Long Route Passengers" << endl
		<< Annual[airport].passengers.dailyinternational << " Daily International Passengers" << endl;

	cout << "The Annual Passenger Predicted Growth For Regional flights  is " << 
		Annual[airport].analizer.regionaldemand << " Passengers Per Year" << endl;
	if (Annual[airport].analizer.regionaldemand <= annualregionalseats)
	{
		cout << "Keep Using Embraer RJ-135" << endl;
	}
	else if (Annual[airport].analizer.regionaldemand >= annualregionalseats)
	{
		cout << "Purchase Airbus A220" << endl;
	}
	else 
	{ 
		cout << "Invalid Data" << endl;
	}

	cout << "The Annual Passenger Predicted Growth For Short Domestic flights  is " <<
		Annual[airport].analizer.domesticshortdemand << " Passengers Per Year" << endl;
	if (Annual[airport].analizer.regionaldemand <= annualdsseats)
	{
		cout << "Keep Using Boeing 737 Next Generation" << endl;
	}
	else if (Annual[airport].analizer.domesticshortdemand >= annualdsseats)
	{
		cout << "Purchase Boeing 737 MAXX" << endl;
	}
	else
	{
		cout << "Invalid Data" << endl;
	}

	cout << "The Annual Passenger Predicted Growth For Long Domestic flights  is " <<
		Annual[airport].analizer.domesticlongdemand << " Passengers Per Year" << endl;
	if (Annual[airport].analizer.domesticlongdemand <= annualdlseats)
	{
		cout << "Keep Using Boeing 737 Next Generation" << endl;
	}
	else if (Annual[airport].analizer.domesticlongdemand >= annualdlseats)
	{
		cout << "Purchase Airbus A320 NEO" << endl;
	}
	else
	{
		cout << "Invalid Data" << endl;
	}

	cout << "The Annual Passenger Predicted Growth For International flights  is " <<
		Annual[airport].analizer.internationaldemand << " Passengers per Year" << endl;
	if (Annual[airport].analizer.internationaldemand <= annualintlseats)
	{
		cout << "Keep Using Boeing 767-400" << endl;
	}
	else if (Annual[airport].analizer.internationaldemand >= annualintlseats)
	{
		cout << "Purchase Boeing 787" << endl;
	}
	else
	{
		cout << "Invalid Data" << endl;
	}
}
