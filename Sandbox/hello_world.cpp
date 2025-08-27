#include <iostream>
using namespace std;

int add(int a, int b){
    return a + b;
}

int subtract(int a, int b){
    return a - b;
}

int multiply(int a, int b){
    return a * b;
}

int divide(int a, int b){
    if(b == 0){
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
    return a / b;
}

int main() {
    int first_number;
    int second_number;
    int result;
    string operation;

    cout << "Enter the first number: ";
    cin >> first_number;
    cout << "Enter the second number: ";
    cin >> second_number;
    cout << "Enter an operation (+, -, *, /):";
    cin >> operation;

    if (operation == "+") {
        result = add(first_number, second_number);
    }
    else if (operation == "-") {
        result = subtract(first_number, second_number);
    }
    else if (operation == "*") {
        result = multiply(first_number, second_number);
    }
    else if (operation == "/") {
        result = divide(first_number, second_number);
    }
    else {
        cout << "Invalid operation!" << endl;
    }

    cout << "Your Result is: " << result << endl;
}

