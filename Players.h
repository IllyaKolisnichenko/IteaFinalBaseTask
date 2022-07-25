#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "fishes.h"


class Players {

public:
	enum fishingGear {
		fishingRod,
		spinning,
		

	};
	enum bait {
		worms,
		maggot,
		spoon,
	
	};

	 void setName(std::string& name) {
		name_ = name;
	}

	 void setId(int id) {
		id_player_ = id;
	}

	static void writeToVector(std::vector<Players>& users, Players& pntrPlayer) {
		users.push_back(pntrPlayer);
	}

	 int getScore() {
		return score_;

	}

	 void setScore(int fishWeight) {
		score_=fishWeight;

	}
	
	static std::pair<fishingGear, int> getFishingGear(int &gear) {
		 std::pair<fishingGear, int> characterGear;
		 if (gear == 0) {
			 fishingGear playerGears(static_cast<fishingGear>(gear));
			 return characterGear = { playerGears, maxWeightFishesRod };
		 }
		 if (gear == 1) {
			 fishingGear playerGears(static_cast<fishingGear>(gear));
			 return characterGear = { playerGears, maxWeightFishesSpining };
		 }

	
	}

	static bait getBait(int &bait1) {
		bait choosenBait(static_cast<bait>(bait1));
		return choosenBait;
	}
	
	void cautchFish(std::pair<fishingGear, int> fishingGear, int saturation, int WeightFish, bait choosenBait) {

		if (saturation < 5 && fishingGear.first == fishingRod || spinning && choosenBait == worms || maggot) {
			std::cout << "nibble....nibble...(kluet.....kluet)\n";
			Sleep(5000);
			if (WeightFish < 1500 && fishingGear.second) {
				std::cout << "You cautch Carp\n";
				std::cout << "weight =" << WeightFish << " grams" << "\n";
				Players::setScore(WeightFish);
				
			}
			else if (WeightFish > 1500 && fishingGear.second) {
				std::cout << "You do not catch fish. it was a very big fish\n";
			}
			
		}
				
		
		
	}

	 std::string getName() {
		return name_;
	}
	int getId() {
		return id_player_;
	}
private:
	int id_player_;
	std::string name_;
	int score_;
	
	static constexpr int maxWeightFishesRod = 1500;
	static constexpr int maxWeightFishesSpining = 3000;
};