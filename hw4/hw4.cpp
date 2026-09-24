#include<print>
using std::println;
#include<cmath>
#include <functional>
using std::function;
#include <iostream>
using std::cin;
// newton's method:
double newton_root(function<double(double)> f, function<double(double)> fprime){
  double x = 1.0;
  for (int i = 0; i < 500; i++){
    x = x - f(x)/fprime(x);

  }
  return x;

}

int main(){
  double num;
  cin >> num;
  if (num == 0) {
   println("0");
   return 0;
  }
  //The Parent Function
  auto f = [num] (double x) {return x*x-num;};


  //The deretive function
  auto fprime  = [f](double x, double h = 1e-5){return (f(x+h)-f(x-h)) / (2.0*h);};
  

  double sqrt7 = newton_root(f,fprime);
  println("{}",sqrt7);

}

