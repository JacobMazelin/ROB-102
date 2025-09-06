/*
 * File: 6_pocket_calc.cpp
 *
 * Let's write an infix calculator program for real numbers with variables
 * that takes numbers from user input, uses functions for modularity,
 * and performs calulations with infinitely many consecutive operations!
 */

#include <iostream>
#include <pocket_calculator/common/utils.h>
using namespace std;

// *** Task: Add any extra helper functions you want here *** //
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
