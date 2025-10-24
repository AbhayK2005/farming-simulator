#include "soil.hpp"

std::string Soil::symbol() {
    return ".";
}

void Soil::end_day() {
    // no-op
}

bool Soil::is_empty() {
    return true;
}

bool Soil::is_mature() {
    return false;
}