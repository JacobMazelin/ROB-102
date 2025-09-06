/*
 * File: 6_pocket_calc.cpp
 *
 * Let's write an infix calculator program for real numbers with variables
 * that takes numbers from user input, uses functions for modularity,
 * and performs calulations with infinitely many consecutive operations!
 */

#include <iostream>
using namespace std;

// *** Task: Add any extra helper functions you want here *** //


float addTwoNumbers(float operand1, float operand2){
  /**
 * Adds two numbers and returns their sum.
 * @param  operand1 The first number to be added.
 * @param  operand2 The second number to be added.
 * @return  The sum of the arguments.
 */
  return operand1 + operand2; 
}

/**
 * Subtracts two numbers and returns the result.
 * @param  operand1 The number to be subtracted from.
 * @param  operand2 The amount to be subtracted.
 * @return  The difference of the arguments.
 */

float subtractTwoNumbers(float operand1, float operand2){
  return operand1 - operand2;
}

/**
 * Multiplies two numbers and stores the result in the third argument.
 * @param  operand1 The first number to be multipled.
 * @param  operand2 The second number to multiply the first by.
 * @param[out]  product The product of the arguments.
 */
void multiplyTwoNumbers(float operand1, float operand2, float &product){
  product = operand1 * operand2;
}

/**
 * Divides the first argument by the second argument and stores the result in the third argument.
 * @param  operand1 The numerator of the operation.
 * @param  operand2 the denominator of the operation.
 * @param[out]  quotient The quotient, unchanged if return is true.
 * @return  A bool, true if the denominator is zero, false otherwise.
 */
bool divideTwoNumbers(float operand1, float operand2, float &quotient){
  if(operand2 == 0){
    return true;
  } else {
    quotient = operand1 / operand2;
    return false;
  }
}
/**
 * Prompts the user to input a number and stores the value in the argument.
 * @param[out]  output_stream The stream on which to prompt the user.
 * @param[in, out]  input_stream The stream on which to take user input.
 * @param[out]  number The number collected from the user.
 *
 * NOTE: The user is assumed to input a valid floating point number on the input stream.
 */
void getNumber(std::ostream& output_stream, std::istream& input_stream, float &number){
  output_stream << "Please type a number and press enter: ";
  input_stream >> number;
}

bool getOperator(std::ostream& output_stream, std::istream& input_stream, char &operation){
    while (true){
        output_stream << "Please type a math operator (one of: + - * / or q to quit): ";
        input_stream >> operation;
        if (operation == 'q'){
            // exit(0);
            return false;
        }
        if (operation == '+' || operation == '-' || operation == '*' || operation == '/'){
            return true;
        } else {
            cerr << "Error: specified operation ("<< operation <<") not recognized." << endl;
        }
}
}

bool performOperation(float operand1, char operation, float operand2, float &result){
  switch(operation){
    case '+':
      result = addTwoNumbers(operand1, operand2);
      return false;
    case '-':
      result = subtractTwoNumbers(operand1, operand2);
      return false;
    case '*':
      multiplyTwoNumbers(operand1, operand2, result);
      return false;
    case '/':
      return divideTwoNumbers(operand1, operand2, result);
  }
  return true;
}


int main() {
  // Let's declare our variables!
  float my_number, my_other_number; // Calculation operands
  float result_number;
  char my_operator; // Character representing operation to perform

  getNumber(cout, cin, my_number);
  if (!getOperator(cout, cin, my_operator)){
        cout << "Calculator: quitting now\n\n";
        exit(0);
  }
  getNumber(cout, cin, my_other_number);
  if (my_operator == '/' && my_other_number == 0){
    cerr << "Error: Divide by zero attempted!!!\n\n";
    return -1;
  }
  performOperation(my_number, my_operator, my_other_number, result_number);
  cout << my_number << " " << my_operator << " " << my_other_number << " = " << result_number << endl;

while (true){
  if (!getOperator(cout, cin, my_operator)){
    cout << "Calculator: quitting now\n\n";
    exit(0);
  }
  //getOperator(cout, cin, my_operator);
  getNumber(cout, cin, my_other_number);
  if (my_operator == '/' && my_other_number == 0){
    cerr << "Error: Divide by zero attempted!!!\n\n";
    return -1;
  }
  cout << result_number;
  performOperation(result_number, my_operator, my_other_number, result_number);
  cout << " " << my_operator << " " << my_other_number << " = " << result_number << endl;
}

}
