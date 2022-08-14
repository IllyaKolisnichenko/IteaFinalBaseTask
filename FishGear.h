#pragma once

class fishingGear {
public:
	virtual bool pullFish() = 0;

	void setFishGear(std::string fishGear_) {
		fishGear = fishGear_;
	}

	std::string getFishingGear() {
		return fishGear;
	}

	void setBait(std::string bait_) {
		bait = bait_;
	}

	std::string getBait() {
		return bait;
	}

private:
	std::string fishGear;
	std::string bait;
};
class fishingRod : public fishingGear {
	bool pullFish() override
	{
		int poss = rand() % 101;
		if (poss < 60) { // 60%  possibility of losing fish
			return true;
		}
		else return false;
	}
};
class spinning : public fishingGear {
	bool pullFish() override
	{
		int poss = rand() % 101;
		if (poss < 80) { // 80%  possibility of losing fish
			return true;
		}
		else return false;
	}
};

