#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

// Define a structure for history
struct History {
    string expression;
    double result;
};

int main() {
    vector<History> history;
    int choice;
    double result = 0;

    while (true) {
        cout << "Welcome To Simple Command Line Calculator!" << endl;
        cout << "Select an option:" << endl;
        cout << "1. Basic Calculator (Addition, Subtraction, Multiplication, Division)" << endl;
        cout << "2. Temperature Conversion (Celsius <-> Fahrenheit)" << endl;
        cout << "3. Currency Conversion (USD <-> INR)" << endl;
        cout << "4. Length Conversion (Meters <-> Kilometers)" << endl;
        cout << "5. Time Conversion (Hours <-> Minutes)" << endl;
        cout << "6. View History" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice (1-7): ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: {
                cout << "Enter the expression (e.g., 50+50-50*2): ";
                string expression;
                getline(cin, expression);

                result = 0;
                double num = 0;
                char op = '+';
                stringstream ss(expression);

                while (ss >> num) {
                    if (op == '+') result += num;
                    else if (op == '-') result -= num;
                    else if (op == '*') result *= num;
                    else if (op == '/') result /= num;

                    ss >> op;
                }

                history.push_back({expression, result});
                cout << "Result: " << result << endl;
                break;
            }
            case 2: {
                char tempUnit;
                double tempValue;
                cout << "Enter the temperature (C/F): ";
                cin >> tempValue >> tempUnit;

                if (tempUnit == 'C' || tempUnit == 'c') {
                    result = (tempValue * 9 / 5) + 32;
                    cout << tempValue << " Celsius = " << result << " Fahrenheit" << endl;
                } else if (tempUnit == 'F' || tempUnit == 'f') {
                    result = (tempValue - 32) * 5 / 9;
                    cout << tempValue << " Fahrenheit = " << result << " Celsius" << endl;
                } else {
                    cout << "Invalid input!" << endl;
                }

                history.push_back({"Temperature conversion", result});
                break;
            }
            case 3: {
                double amount;
                cout << "Enter amount in USD: ";
                cin >> amount;
                result = amount * 82.75;
                cout << amount << " USD = " << result << " INR" << endl;

                history.push_back({"Currency conversion", result});
                break;
            }
            case 4: {
                double length;
                char unit;
                cout << "Enter length and unit (M/K): ";
                cin >> length >> unit;

                if (unit == 'M' || unit == 'm') {
                    result = length / 1000;
                    cout << length << " meters = " << result << " kilometers" << endl;
                } else if (unit == 'K' || unit == 'k') {
                    result = length * 1000;
                    cout << length << " kilometers = " << result << " meters" << endl;
                } else {
                    cout << "Invalid unit!" << endl;
                }

                history.push_back({"Length conversion", result});
                break;
            }
            case 5: {
                double time;
                char unit;
                cout << "Enter time and unit (H/M): ";
                cin >> time >> unit;

                if (unit == 'H' || unit == 'h') {
                    result = time * 60;
                    cout << time << " hours = " << result << " minutes" << endl;
                } else if (unit == 'M' || unit == 'm') {
                    result = time / 60;
                    cout << time << " minutes = " << result << " hours" << endl;
                } else {
                    cout << "Invalid unit!" << endl;
                }

                history.push_back({"Time conversion", result});
                break;
            }
            case 6: {
                cout << "\nHistory of calculations: " << endl;
                if (history.empty()) {
                    cout << "No history available." << endl;
                } else {
                    for (int i = 0; i < history.size(); i++) {
                        cout << i + 1 << ". Expression: " << history[i].expression << " = " << history[i].result << endl;
                    }
                }
                break;
            }
            case 7: {
                cout << "Exiting calculator. Goodbye!" << endl;
                return 0;
            }
            default:
                cout << "Invalid choice! Please enter a number between 1 and 7." << endl;
        }
    }

    return 0;
}
