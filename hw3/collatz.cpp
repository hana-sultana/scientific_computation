#include "header.hpp"

int Collatz_Conjecture(int num){
  int count = 1;

  while (num != 1){
    count++;
    if (num%2 ==0){
      num = num/2;
    }
    else{
      num = 3 * num +1;
	}
  }
  return count;
}
