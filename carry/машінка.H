#pragma once

enum fuelType {
	A92, A95, Disel 
};

class car
{
public:
	double HorsePower();
	car();
private:
	double engineVolume;
	int weight;
	int pistonCount;
	int sitCount;
	int tankVolume;
	int RevolutionsPerMinute;
	int Efficiency;
	fuelType meinFuel;
};
