#pragma once
#pragma once
#include <iostream>
#include <string>
#include "fishes.h"




class Lake {
public:
	Lake()
	{
		name_ = "Lake" ;
	}

	static std::string getNameWater() {
		return name_;

	}

	std::string WhatIsFish() {
		int f{};
		f = rand() % 100;
		if (0 <= f >= 40) {
			return Carp::getSpecies();
		}
		if (41 <= f >= 80) {
			return Crucian::getSpecies();
		}
		if (81 <= f >= 100) {
			return Pike::getSpecies();

		}

	}
private:
	static std::string name_;

};