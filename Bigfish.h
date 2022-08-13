#include <iostream>
#include <string>
class ImportantInFishing {
public:
    ImportantInFishing();
    ImportantInFishing(int co);
    virtual int Menu() = 0;
private:
    int CostOfFishing_=0;
};

class StartFishing
{
private:
    int biting_=0;
    int bobber_=0;
public:
    StartFishing();
    StartFishing(int biti );
    int beginningOne();
    int change_location();
    int operator ==(const StartFishing& po)const;
};

class BitingProcess : public ImportantInFishing 
{
private:
    int bit_=0;
    int bob_=0;
public:
    BitingProcess();
    BitingProcess(int b, int bo, int co);
     int  beginningTwo();
     int bait_change();
    virtual int Menu()override;
    int operator ==(const BitingProcess& po)const;
};
  
class CatchInformation : public ImportantInFishing, public StartFishing, public BitingProcess
{
private:
    int field_=0;
public:
    CatchInformation();
    CatchInformation(int fil,  int b, int bo, int biti, int co);
    int Catch_In_formation();
    virtual int Menu()override;
    CatchInformation assistant(CatchInformation&)const;
};
   