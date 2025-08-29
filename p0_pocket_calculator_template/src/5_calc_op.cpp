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
    return a / b;
}

int main() {
    float first_number;
    float second_number;
    float result;
    string operation;

    cout << "Please type a number and press enter: ";
    cin >> first_number;
    cout << "Please type a math operator (one of: + - * or /): ";
    cin >> operation;
    cout << "Please type another number and press enter: ";
    cin >> second_number;

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
        if(second_number == 0){
        cout << "Error: Divide by zero attempted!!!" << endl;
        return -1;
    }
        result = divide(first_number, second_number);
    }
    else {
        cout << "Error: specified operation "<< operation <<" not recognized." << endl;
        return -1;
    }

    cout << "Here's the result of the operation!\n" << first_number << operation << second_number << " = " << result << endl;

}