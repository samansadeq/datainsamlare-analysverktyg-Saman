#include <iostream>     // For input and output
#include <vector>       // To store the list of values
#include <algorithm>    // For sorting and min/max
#include <cmath>        // For sqrt() in standard deviation
#include <limits>       // For input validation

using namespace std;

// Function declarations
void addValues(vector<double>& values);
void showStatistics(const vector<double>& values);
void searchValue(const vector<double>& values);
void sortValues(vector<double>& values);
double calculateSum(const vector<double>& values);
double calculateMean(const vector<double>& values);
double calculateVariance(const vector<double>& values);
double calculateStandardDeviation(const vector<double>& values);

int main() {
    vector<double> values; // Stores all measurement values
    int choice;

    do {
        // === MENU INTERFACE ===
        cout << "\n===== MeasurementApp =====\n";
        cout << "1. Add new measurement values\n";
        cout << "2. Show statistics\n";
        cout << "3. Search for a value\n";
        cout << "4. Sort the list (ascending/descending)\n";
        cout << "5. Exit\n";
        cout << "Choose an option (1-5): ";

        cin >> choice;

        // Handle invalid input (letters instead of numbers)
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        // === MENU OPTIONS ===
        switch (choice) {
        case 1:
            addValues(values);
            break;
        case 2:
            showStatistics(values);
            break;
        case 3:
            searchValue(values);
            break;
        case 4:
            sortValues(values);
            break;
        case 5:
            cout << "Program ended. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please enter 1–5.\n";
        }

    } while (choice != 5);

    return 0;
}

// === 1. Add new values ===
void addValues(vector<double>& values) {
    double number;
    char more;

    do {
        cout << "Enter a value (integer or decimal): ";
        cin >> number;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
        }
        else {
            values.push_back(number);
        }

        cout << "Add another value? (y/n): ";
        cin >> more;

    } while (more == 'y' || more == 'Y');
}

// === 2. Show statistics ===
void showStatistics(const vector<double>& values) {
    if (values.empty()) {
        cout << "No values! Please add some first.\n";
        return;
    }

    cout << "\n===== Statistics =====\n";
    cout << "Count: " << values.size() << endl;
    cout << "Sum: " << calculateSum(values) << endl;
    cout << "Mean: " << calculateMean(values) << endl;
    cout << "Min: " << *min_element(values.begin(), values.end()) << endl;
    cout << "Max: " << *max_element(values.begin(), values.end()) << endl;
    cout << "Variance: " << calculateVariance(values) << endl;
    cout << "Standard Deviation: " << calculateStandardDeviation(values) << endl;
}

// === 3. Search for a value ===
void searchValue(const vector<double>& values) {
    if (values.empty()) {
        cout << "No values to search!\n";
        return;
    }

    double target;
    cout << "Enter the value to search for: ";
    cin >> target;

    bool found = false;
    for (double val : values) {
        if (val == target) {
            found = true;
            break;
        }
    }

    if (found)
        cout << "The value " << target << " was found!\n";
    else
        cout << "The value " << target << " was NOT found.\n";
}

// === 4. Sort the list ===
void sortValues(vector<double>& values) {
    if (values.empty()) {
        cout << "No values to sort!\n";
        return;
    }

    int order;
    cout << "Sort order: 1 = Ascending, 2 = Descending: ";
    cin >> order;

    if (order == 1) {
        sort(values.begin(), values.end());
        cout << "Sorted ascending.\n";
    }
    else if (order == 2) {
        sort(values.begin(), values.end(), greater<double>());
        cout << "Sorted descending.\n";
    }
    else {
        cout << "Invalid choice! Sorting canceled.\n";
        return;
    }

    cout << "Sorted values: ";
    for (double val : values) cout << val << " ";
    cout << endl;
}

// === Helper functions ===
double calculateSum(const vector<double>& values) {
    double sum = 0;
    for (double val : values) sum += val;
    return sum;
}

double calculateMean(const vector<double>& values) {
    return calculateSum(values) / values.size();
}

double calculateVariance(const vector<double>& values) {
    double mean = calculateMean(values);
    double variance = 0;
    for (double val : values)
        variance += pow(val - mean, 2);
    return variance / values.size();
}

double calculateStandardDeviation(const vector<double>& values) {
    return sqrt(calculateVariance(values));
}
