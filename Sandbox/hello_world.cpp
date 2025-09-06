#include <iostream>
int main()
{
  int number_one = 102102;
  int number_two = 54;
  int number_three = 1890;
  int number_four = 42;
  std::cout << 8/2*2+2;
  std::cout << "What is "<< number_one <<" plus "<< number_two << "? " << number_one + number_two << "\n";
  std::cout << "What is "<< number_one <<" minus "<< number_two << "? " << number_one - number_two << "\n";
  std::cout << "What is "<< number_one <<" multiplied by "<< number_two << "? " << number_one * number_two << "\n";
  std::cout << "What is "<< number_one <<" divided by "<< number_two << "? " << number_one / number_two << "\n";
  std::cout << "What is the remainder of "<< number_one <<" divided by "<< number_two << "? " << number_one % number_two << "\n";
  std::cout << "Verify that "<< number_one <<" is equal to "<< number_three <<" * "<< number_two << " + "<< number_four <<" " << number_three * number_two + number_four << "\n";
}