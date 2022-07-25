#pragma once
#include<string>
#include<iostream>
#include "water.h"

class Fishes {

public:
	Fishes()
	{

	}
	
	//virtual int getSaturation() = 0;
	//virtual std::string getSpecies() = 0;


protected:
   static constexpr int maxWeigt_{3000};
   static constexpr int saturation_{10};
	


};

class Carp : public Fishes {
public:
	Carp()
	{
		std::string species_ = "Carp";
	}

	static int getWeight()  {
		return 100 + rand() % maxWeigt_;

	}
	static int getSaturation() {
		return 1 + rand() % saturation_;

	}

	static std::string getSpecies()  {
		return species_;

	}
private:
	static std::string species_;

};


class Crucian : public Fishes {
public:
	Crucian()
	{
		std::string species_ = "Crucian";
	}

	int getWeight()  {
		return 100 + rand() % maxWeigt_;

	}
	int getSaturation() {
		return 1 + rand() % saturation_;

	}

	static std::string getSpecies() {
		return species_;

	}
private:
	static std::string species_;


};


class Pike : public Fishes {
public:
	Pike()
	{
		std::string species{ "Pike" };
	}

	int getWeight() {
		return 100 + rand() % maxWeigt_;

	}
	 int getSaturation() {
		return 1 + rand() % saturation_;

	}

	static std::string getSpecies() {
		return species_;

	}
private:
	static std::string species_;


};
