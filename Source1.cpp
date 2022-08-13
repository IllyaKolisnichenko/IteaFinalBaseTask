#include"Bigfish.h"
#include<iostream>
#include<ctime>
#include<Windows.h>
#include <string>
#include <algorithm>
#include <list>
using std::cout;
using std::endl;
ImportantInFishing::ImportantInFishing() {
	CostOfFishing_ ;
}

ImportantInFishing::ImportantInFishing(int co) {
	CostOfFishing_=co;
} 

int ImportantInFishing::Menu()
{
	return 0;
}

StartFishing::StartFishing() {
	biting_;
	bobber_;
}
StartFishing::StartFishing(int biti ) {
	 biting_= biti;
}

int StartFishing::beginningOne()
{
	{
		int  fjl = 0;
		static int wkl = 0;
		srand(time(0));
        for (bobber_ = 3;bobber_ >= 0;bobber_--)
		{
			wkl = rand() % 10 + 1;
			std::cout << "random = " << wkl;
			system("cls");

			if (wkl == 1)
			{
				std::cout << "\n_";
				Sleep(1000);
				system("cls");
				return change_location();
			}

			else if (wkl == 2)
			{
				std::cout << "\n/";
				Sleep(1000);
				system("cls");
			}

			else if (wkl == 3)
			{
				std::cout << "\n-";
				Sleep(1000);
				system("cls");
				return  change_location();
			}

			else if (wkl == 4)
			{
				std::cout << "\n-";
				Sleep(1000);
				system("cls");
				return  change_location();
			}

			else if (wkl >= 5)
			{
				std::cout << "\n\\";
				Sleep(1000);
				system("cls");
			}
		}
		return 0;
	}
}

int StartFishing::change_location()
{
	return biting_;
}

int StartFishing::operator ==(const StartFishing& po)const
{
	return (biting_ == po.biting_);
}

BitingProcess::BitingProcess() {
	bit_;
}

BitingProcess::BitingProcess(int b, int bo, int co):ImportantInFishing(co) {
	bit_=b;
	bob_=bo;
}

int BitingProcess::Menu()
{
	return 0;
}

int BitingProcess::bait_change()
{
	return bob_;
}
int BitingProcess::beginningTwo()
{
	{
		static int wkl = 0;

		srand(time(0));
		for (bit_ = 3;bit_ >= 0;bit_--)
		{
			wkl = rand() % 10 + 1;
			std::cout << "random = " << wkl;
			system("cls");
			if (wkl == 1)
			{
				std::cout << "\n-";
				Sleep(1000);
				system("cls");
				return  bait_change();
			}
			else if (wkl == 2)
			{
				std::cout << "\n/";
				Sleep(1000);
				system("cls");
			}
			else if (wkl == 3)
			{
				std::cout << "\n.";
				Sleep(1000);
				system("cls");
				return bait_change();
			}

			else if (wkl == 4)
			{
				std::cout << "\n_";
				Sleep(1000);
				system("cls");
				return  bait_change();
			}

			else if (wkl >= 5)
			{
				std::cout << "\n\\";
				Sleep(1000);
				system("cls");
			}
		}

	}
}

int BitingProcess::operator ==(const BitingProcess& po)const
{
	return (bob_ == po.bob_);
}

CatchInformation::CatchInformation() {
field_;
}
 
CatchInformation::CatchInformation(int fil, int b, int bo, int biti, int co): ImportantInFishing(co), StartFishing(biti), BitingProcess(b,bo, co) {////////////////////////////////////////////////
	field_ = fil;
}

int CatchInformation::Catch_In_formation()
{
	std::cout << "Well, it's time to throw the bait?!\n1. Yes, put 1 !\n2.Or maybe change location right now.There is a better place ? If ok, put 2 ! \n";
	std::cin >> field_;
	if (field_ == 1)
		return beginningOne();
	else
		return beginningTwo();
}

int CatchInformation::Menu()
{
	std::cout << "Hello fisher!\n";
	std::cout << "How are you! Are you want catsh some fishs?! Ok!\n";
	std::cout << "Then I have a great fishing rod for you!\n";
	std::cout << "But, this business costs some money!\n";
	std::cout << "I have a good bite!\n";
	std::cout << "Therefore, the cost of 1 minute of fishing costs 1 dollar!\n";
	std::cout << "What you catch in a minute is yours!\n";
	std::cout << "I have a fishing rod, a spinning rod and a screen in my arsenal!\n";
	std::cout << "You can expect a good dinner tonight!\n";
	std::cout << "If everything suits you here, follow me!\n";
	std::cout << "\t\t  Menu:\n";
	return 0;
}

CatchInformation CatchInformation::assistant(CatchInformation& dsf)const
{
	CatchInformation we;
	we.field_ = field_ + dsf.field_;
	return we;
}
