#include "data_manager.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
using namespace std;

// === Add a new measurement ===
void DataManager::addMeasurement(float value, const string& timestamp) {
    data.push_back({ value, timestamp });
}

// === Print all stored measurements ===
void DataManager::printData() const {
    cout << "\n=== Measurements ===" << endl;
    if (data.empty()) {
        cout << "No measurements available.\n";
        return;
    }

    for (const auto& m : data)
        cout << m.timestamp << " : " << m.value << endl;
}

// === Calculate the average of all values ===
float DataManager::calculateAverage() const {
    if (data.empty()) return 0;
    float sum = 0;
    for (auto& m : data) sum += m.value;
    return sum / data.size();
}

// === Find the smallest value ===
float DataManager::findMin() const {
    if (data.empty()) return 0;
    float minVal = data[0].value;
    for (auto& m : data)
        if (m.value < minVal) minVal = m.value;
    return minVal;
}

// === Find the largest value ===
float DataManager::findMax() const {
    if (data.empty()) return 0;
    float maxVal = data[0].value;
    for (auto& m : data)
        if (m.value > maxVal) maxVal = m.value;
    return maxVal;
}

// === Calculate standard deviation ===
float DataManager::calculateStdDev() const {
    if (data.size() < 2) return 0;
    float avg = calculateAverage();
    float sumSq = 0;
    for (auto& m : data)
        sumSq += pow(m.value - avg, 2);
    return sqrt(sumSq / (data.size() - 1));
}

// === Save all measurements to a file (CSV format) ===
void DataManager::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) {
        cerr << "Could not save to file: " << filename << endl;
        return;
    }

    for (auto& m : data)
        file << m.timestamp << "," << m.value << endl;

    cout << "Data saved to file: " << filename << endl;
}

// === Load measurements from a file (CSV format) ===
void DataManager::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "No previous file found. Starting with empty data.\n";
        return;
    }

    data.clear();
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string timestamp;
        float value;

        if (getline(ss, timestamp, ',') && ss >> value)
            data.push_back({ value, timestamp });
    }

    cout << "Loaded data from file: " << filename << endl;
}
