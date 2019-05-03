
#pragma once

class Banitsa
{
private:
	int size;
	int calories;
	char* Manufacturer;
public:
	void setSize(int size)
	{
		this->size = size;
	}
	void setCalories(int calories)
	{
		this->calories = calories;
	}
	void setManufacturer(char* Manufacturer)
	{
		int len = strlen(Manufacturer);
		char* name = new char[len];
		strcpy_s(this->Manufacturer, len, Manufacturer);
	}
	Banitsa();
	~Banitsa();
	char* getManufacturer()
	{
		return this->Manufacturer;
	}
}; 