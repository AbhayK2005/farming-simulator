#include <string>

#include "carrot.hpp"

std::string Carrot::symbol() {
    if(age == 0) {
        return "v";
    } else if (age == 1) {
        return "V";
    } else {
        return "W";
    }
}

void Carrot::end_day() {
    age += 1;
}

bool Carrot::is_empty() {
    return false;
}

bool Carrot::is_mature() {
    return age >= 1;
}
