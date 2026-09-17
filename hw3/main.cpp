#include <iostream>
#include "header.hpp"
#include <print>
using std::println;
int main(){
  int user_value;
  std:: cin >> user_value;
  int sequence_length = Collatz_Conjecture(user_value);
  println("{}", sequence_length);
  return 0;
}
      
	  
