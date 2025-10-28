#pragma once
#include <string>

// A simple struct that stores one measurement
// Each measurement has a numeric value and a timestamp.
struct Measurement {
    float value;           // The measurement value (for example temperature)
    std::string timestamp; // The time when the measurement was taken
};
