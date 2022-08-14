#pragma once
#include <iostream>
#include <string>

class waterBody {
public:

	void createWaterBody(std::string waterType_) {
		std::ifstream waterFile;
		waterFile.open(path);

		if (!waterFile.is_open())
		{
			std::cout << "Can't open file with water data" << std::endl;
		}
		while (!waterFile.eof())
		{
			std::string str;
			waterFile >> str;
			if (str == waterType_)
			{
				waterFile >> str;
				rowDimension = stoi(str);
				waterFile >> str;
				colDimension = stoi(str);
				waterFile >> str;
				fish1 = str;
				waterFile >> str;
				fish2 = str;
				waterFile >> str;
				fish3 = str;
				waterFile >> str;
				fish4 = str;
				break;
			}
		}
		waterFile.close();

		waterArray = new int* [colDimension];
		for (int i = 0; i < colDimension; i++)
		{
			waterArray[i] = new int[rowDimension];
		}

		for (int i{ 0 }; i < colDimension; i++)
		{
			for (int j{ 0 }; j < rowDimension; j++)
			{
				waterArray[i][j] = 0;
			}
		}

		for (int i{ 0 }; i < colDimension; i++) //placement of fish in water body
		{
			for (int j{ 0 }; j < rowDimension; j += rand() % 10)
			{
				waterArray[i][j] = rand() % 5; //choosing one of four types of fish 
			}
		}
	}

	void deleteWaterBody() {
		for (int i{ 0 }; i < colDimension; i++)
		{
			delete[] waterArray[i];
		}
		delete[] waterArray;
	}

	void printWaterBody() {
		std::cout << "  ";
		for (int i{ 0 }; i < colDimension; i++) {
			if (i < 10) std::cout << " " << i << " ";
			else std::cout << i << " ";
		}
		std::cout << std::endl;
		std::cout << "  ";
		for (int i{ 0 }; i < colDimension; i++) {
			std::cout << "---";
		}
		std::cout << std::endl;

		for (int i{ 97 }; i < (rowDimension + 97); i++) //97 is char "a" acording to ascii table
		{
			std::cout << char(i) << "|";
			for (int j{ 0 }; j < colDimension; j++) {
				std::cout << " " << char(126) << " "; //126 is char "~" acording to ascii table  

			}
			std::cout << std::endl;
		}
	}

	void setwaterType(std::string waterType_) {
		waterType = waterType_;
	}

	std::string getwaterType() {
		return waterType;
	}

	void setfishingPoint() {
		char r;
		std::string c;
		do {
			std::cout << "Enter row of fishing:";
			std::cin >> r;
			y = r - 97; //97 is char "a" acording to ascii table
			std::cout << "Enter colum of fishing:";
			std::cin >> c;
			x = stoi(c);
		} while (y < 0 || y > rowDimension || x < 0 || x > colDimension);
	}

	std::string getFish() {
		switch (waterArray[x][y]) {
		case 1:
			return fish1;
		case 2:
			return fish2;
		case 3:
			return fish3;
		case 4:
			return fish4;
		case 0:
			return "No fish";
		}

	}

	void deleteFish() {
		waterArray[x][y] = 0;
	}

private:
	int rowDimension;
	int colDimension;
	int x, y;
	int** waterArray;
	std::string fish1, fish2, fish3, fish4;
	std::string waterType;
	std::string path = "Water.txt";
};