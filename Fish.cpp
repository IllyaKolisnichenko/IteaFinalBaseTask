#include "Fish.h"

unsigned int Fish::getFishWeight() {
    return rand() % maxFishWeight_ + minFishWeight_;
}

std::string Fish::getFishName() {
    return fishName_;
}

void Fish::setFishName( const std::string& name ) {
    fishName_ = name;
}

void Fish::setMinMaxFishWeight( int min, int max ) {
    minFishWeight_ = min;
    maxFishWeight_ = max;
}

bool Crucian::baitPreferenses( std::string baitName ) {
    if( baitName == "Maggot" )
        return false;
    return true;
}

bool Perch::baitPreferenses( std::string baitName ) {
    if( baitName == "Bloodworm" || baitName == "Maggot" )
        return false;
    return true;
}

bool Pike::baitPreferenses( std::string baitName ) {
    return true;
}

