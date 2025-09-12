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

// *** Task: Add any extra helper functions you want here *** //
int main() {
  // Let's declare our variables!
  float my_number, my_other_number; // Calculation operands
  float result_number;
  char my_operator; // Character representing operation to perform

  getNumber(cout, cin, my_number);
  while (getOperator(cout, cin, my_operator)){
    cerr << "Error: specified operation ("<< my_operator <<") not recognized" << endl;
  }
  if (my_operator == 'q'){
    cout << "Calculator: quitting now\n";
    return 0;
        }
  getNumber(cout, cin, my_other_number);
  if (my_operator == '/' && my_other_number == 0){
    cerr << "Error: Divide by zero attempted!!!\n";
    return -1;
  }
  performOperation(my_number, my_operator, my_other_number, result_number);
  cout << my_number << " " << my_operator << " " << my_other_number << " = " << result_number << endl;
  my_number = result_number;
  
while (true){
  while(getOperator(cout, cin, my_operator)){
    cerr << "Error: specified operation ("<< my_operator <<") not recognized" << endl;
  }
  if (my_operator == 'q'){
    cout << "Calculator: quitting now\n";
    return 0;
        }
  getNumber(cout, cin, my_other_number);
  if (my_operator == '/' && my_other_number == 0){
    cerr << "Error: Divide by zero attempted!!!\n";
    return -1;
  }
  performOperation(my_number, my_operator, my_other_number, result_number);

  cout << my_number << " " << my_operator << " " << my_other_number << " = " << result_number << endl;
  my_number = result_number;
}

}
