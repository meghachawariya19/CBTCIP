#include <iostream>
using namespace std;

void displayMenu() {
    cout << "Digital Calculator Menu:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

void performAddition() {
    double num1, num2;
    cout << "Enter two numbers to add: ";
    cin >> num1 >> num2;
    cout << "Result: " << num1 + num2 << endl;
}

void performSubtraction() {
    double num1, num2;
    cout << "Enter two numbers to subtract: ";
    cin >> num1 >> num2;
    cout << "Result: " << num1 - num2 << endl;
}

void performMultiplication() {
    double num1, num2;
    cout << "Enter two numbers to multiply: ";
    cin >> num1 >> num2;
    cout << "Result: " << num1 * num2 << endl;
}

void performDivision() {
    double num1, num2;
    cout << "Enter two numbers to divide: ";
    cin >> num1 >> num2;
    if (num2 != 0) {
        cout << "Result: " << num1 / num2 << endl;
    } else {
        cout << "Error: Division by zero is not allowed." << endl;
    }
}

int main() {
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                performAddition();
                break;
            case 2:
                performSubtraction();
                break;
            case 3:
                performMultiplication();
                break;
            case 4:
                performDivision();
                break;
            case 5:
                cout << "Exiting the calculator. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    }
    return 0;
}
