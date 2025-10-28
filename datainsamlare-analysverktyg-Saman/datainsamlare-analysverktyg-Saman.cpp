#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include "data_manager.h"
using namespace std;

// === Project functions ===
void addValues(vector<double>& values);
void showStatistics(const vector<double>& values);
void searchValue(const vector<double>& values);
void sortValues(vector<double>& values);
double calculateSum(const vector<double>& values);
double calculateMean(const vector<double>& values);
double calculateVariance(const vector<double>& values);
double calculateStandardDeviation(const vector<double>& values);

// === MAIN PROGRAM ===
int main() {
    vector<double> values;
    DataManager manager;
    int mainChoice;

    // Load previous data for new project
    manager.loadFromFile("data.csv");

    do {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Use Basic MeasurementApp (old project)\n";
        cout << "2. Use Advanced DataManager (new project)\n";
        cout << "3. Exit\n";
        cout << "Choose an option (1-3): ";

        cin >> mainChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        // === BASIC MENU ===
        if (mainChoice == 1) {
            int choice;
            do {
                cout << "\n===== Basic MeasurementApp =====\n";
                cout << "1. Add new measurement values\n";
                cout << "2. Show statistics\n";
                cout << "3. Search for a value\n";
                cout << "4. Sort values\n";
                cout << "5. Back to main menu\n";
                cout << "Choose (1-5): ";
                cin >> choice;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input.\n";
                    continue;
                }

                switch (choice) {
                case 1: addValues(values); break;
                case 2: showStatistics(values); break;
                case 3: searchValue(values); break;
                case 4: sortValues(values); break;
                case 5: break;
                default: cout << "Invalid choice!\n";
                }
            } while (choice != 5);
        }

        // === ADVANCED MENU ===
        else if (mainChoice == 2) {
            int choice;
            do {
                cout << "\n===== Advanced DataManager =====\n";
                cout << "1. Add measurement\n";
                cout << "2. Show all data\n";
                cout << "3. Show statistics\n";
                cout << "4. Save to file\n";
                cout << "5. Back to main menu\n";
                cout << "Choose (1-5): ";
                cin >> choice;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input.\n";
                    continue;
                }

                switch (choice) {
                case 1: {
                    float val;
                    string time;
                    cout << "Enter value: ";
                    cin >> val;
                    cout << "Enter timestamp (e.g. 2025-10-27 09:00): ";
                    cin.ignore();
                    getline(cin, time);
                    manager.addMeasurement(val, time);
                    break;
                }
                case 2:
                    manager.printData();
                    break;
                case 3:
                    cout << "\nAverage: " << manager.calculateAverage();
                    cout << "\nMin: " << manager.findMin();
                    cout << "\nMax: " << manager.findMax();
                    cout << "\nStd Dev: " << manager.calculateStdDev() << endl;
                    break;
                case 4:
                    manager.saveToFile("data.csv");
                    break;
                case 5:
                    break;
                default:
                    cout << "Invalid choice.\n";
                }
            } while (choice != 5);
        }

        else if (mainChoice == 3) {
            cout << "Program ended. Goodbye!\n";
            manager.saveToFile("data.csv"); // save automatically
        }

    } while (mainChoice != 3);

    return 0;
}

// === FUNCTIONS ===
void addValues(vector<double>& values) {
    double number; char more;
    do {
        cout << "Enter a value: ";
        cin >> number;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!\n";
        }
        else values.push_back(number);
        cout << "Add another? (y/n): ";
        cin >> more;
    } while (more == 'y' || more == 'Y');
}

void showStatistics(const vector<double>& values) {
    if (values.empty()) {
        cout << "No values.\n"; return;
    }
    cout << "\nCount: " << values.size();
    cout << "\nSum: " << calculateSum(values);
    cout << "\nMean: " << calculateMean(values);
    cout << "\nMin: " << *min_element(values.begin(), values.end());
    cout << "\nMax: " << *max_element(values.begin(), values.end());
    cout << "\nVariance: " << calculateVariance(values);
    cout << "\nStandard Deviation: " << calculateStandardDeviation(values) << endl;
}

void searchValue(const vector<double>& values) {
    if (values.empty()) { cout << "No values.\n"; return; }
    double target;
    cout << "Enter value to search: ";
    cin >> target;
    bool found = false;
    for (double val : values)
        if (val == target) { found = true; break; }
    if (found) cout << "Value found!\n";
    else cout << "Value not found.\n";
}

void sortValues(vector<double>& values) {
    if (values.empty()) { cout << "No values.\n"; return; }
    int order;
    cout << "1 = Ascending, 2 = Descending: ";
    cin >> order;
    if (order == 1) sort(values.begin(), values.end());
    else sort(values.begin(), values.end(), greater<double>());
    cout << "Sorted values: ";
    for (double val : values) cout << val << " ";
    cout << endl;
}

double calculateSum(const vector<double>& values) {
    double sum = 0;
    for (double v : values) sum += v;
    return sum;
}
double calculateMean(const vector<double>& values) {
    return calculateSum(values) / values.size();
}
double calculateVariance(const vector<double>& values) {
    double mean = calculateMean(values);
    double variance = 0;
    for (double v : values)
        variance += pow(v - mean, 2);
    return variance / values.size();
}
double calculateStandardDeviation(const vector<double>& values) {
    return sqrt(calculateVariance(values));
}
