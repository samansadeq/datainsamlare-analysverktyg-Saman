#pragma once
#include <vector>
#include <string>
#include "measurement.h"

// The DataManager class handles all the logic of the program.
// It stores all measurements and can calculate statistics or save/load data.
class DataManager {
private:
    std::vector<Measurement> data; // A list that stores all measurements

public:
    // Add a new measurement
    void addMeasurement(float value, const std::string& timestamp);

    // Show all measurements
    void printData() const;

    // Statistical calculations
    float calculateAverage() const;
    float findMin() const;
    float findMax() const;
    float calculateStdDev() const;

    // File handling: save and load data
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};
