#include "Water.h"


std::string Water::getWaterName() {
    return waterName_;
}

int Water::getCatchingFishChance() {
    return catchingFishChance_;
}

void Water::setWaterName( const std::string& name ) {
    waterName_ = name;
}

void Water::setcatchingFishChance( int chance ) {
    catchingFishChance_ = chance;
}

bool River::fishPresence( std::string fishName ) {
    if( fishName == "Perch" )
        return false;
    return true;
}

bool Lake::fishPresence( std::string fishName ) {
    if( fishName == "Pike" )
        return false;
    return true;
}

bool Reservoir::fishPresence( std::string fishName ) {
    return true;
}
