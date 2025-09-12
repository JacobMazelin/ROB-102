#include <iostream>
using namespace std;

float add(float a, float b){
    return a + b;
}

float subtract(float a, float b){
    return a - b;
}

float multiply(float a, float b){
    return a * b;
}

float divide(float a, float b){
    return a / b;
}

int main() {
    float first_number;
    float second_number; 
    float result;
    char operation;

    cout << "Please type a number and press enter: ";
    cin >> first_number;
    cout << "Please type a math operator (one of: + - * or /): ";
    cin >> operation;
    cout << "Please type another number and press enter: ";
    cin >> second_number;

    if (operation == '+') {
        result = add(first_number, second_number);
    }
    else if (operation == '-') {
        result = subtract(first_number, second_number);
    }
    else if (operation == '*') {
        result = multiply(first_number, second_number);
    }
    else if (operation == '/') {
        if(second_number == 0){
        cerr << "Error: Divide by zero attempted!!!" << endl;
        return -1;
    }
        result = divide(first_number, second_number);
    }
    else {
        cerr << "Error: specified operation ("<< operation <<") not recognized." << endl;
        return -1;
    }

    cout << "Here's the result of the operation!\n" << first_number << " " << operation << " " << second_number << " = " << result << endl;

}