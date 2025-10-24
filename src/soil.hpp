#pragma once

#include <string>

#include "plot.hpp"

class Soil : public Plot {
public:
    std::string symbol() override;
    void end_day() override;
    bool is_empty() override;
    bool is_mature() override;
};