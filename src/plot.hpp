#pragma once

#include <string>

class Plot {
public:
    virtual std::string symbol() = 0;
    virtual void end_day() = 0;
    virtual bool is_empty() = 0;
    virtual bool is_mature() = 0;
};