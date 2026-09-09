#include <print>
using std::println;

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
int main(){
  int max_num = 0;
  int max_sequence_length = 0;
  for(int i = 1; i <=1000;i++){
    int current_sequence_length = Collatz_Conjecture(i);
    if(current_sequence_length > max_sequence_length){
      max_sequence_length = current_sequence_length ;
      max_num = i;
      println("The new max number between 1 - 1000 is {} with the sequence length of {}",
	      max_num, max_sequence_length);
    }
    }
    
    return 0;
}


  
    
    
    
    
