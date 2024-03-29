#include <iostream>

using namespace std;

int main() {
    double num1, num2, result;
    char operation;
    
    cout << "Welcome to the Simple Calculator!\n";
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;
    
    switch(operation) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
            } else {
                cout << "Error: Division by zero!\n";
            }
            break;
        default:
            cout << "Invalid operation! Please choose from +, -, *, or /\n";
            break;
    }
    
    return 0;
}
