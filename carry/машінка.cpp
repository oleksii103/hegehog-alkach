#include "машінка.H"
using namespace std;

double car::HorsePower()
{
	double HorsePower = engineVolume * pistonCount * RevolutionsPerMinute * Efficiency / 5252;
	return HorsePower;
}

car::car()
{
	engineVolume = 5.3;
	weight = 1625;
	pistonCount = 4;
	sitCount = 2;
	tankVolume = 47;
	RevolutionsPerMinute = 7500;
	Efficiency = 80;
	meinFuel = fuelType::A95;
}

