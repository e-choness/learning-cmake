#include "Box.hpp"

bool operator<(const Box &thisBox, const Box &otherBox) {
    if(thisBox.mL < otherBox.mL) return true;
    if(thisBox.mB < otherBox.mB && thisBox.mL == otherBox.mL) return true;
    if(thisBox.mH < otherBox.mH && thisBox.mB == otherBox.mB && thisBox.mL == otherBox.mL) return true;
    return false;
}

std::ostream &operator<<(std::ostream &os, const Box &box) {
    return os << box.mL << " " << box.mB << " " << box.mH;
}
