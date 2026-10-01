#include <print>
using std::println;
#include <cmath>
#include <functional>
using std::function;
#include <iostream>

// newton's method:
double newton_root(function<double(double)> f, function<double(double)> fprime){
  double x = 1.0;
  for (int i = 0; i < 500; i++){
    x = x - f(x)/fprime(x);
  }
  return x;
}

// Added new function:
double newton_root(function<double(double)> f){
  double h = 1e-6;

  auto fprime = [f, h](double x){
    return (f(x+h)-f(x-h)) / (2.0*h);
  };

  return newton_root(f, fprime);
}

int main(){
  double num = 7;
  //The Parent Function
  auto f = [num](double x){return x*x-num;};

  //The deretive function
  auto fprime = [f](double x, double h = 1e-5){
    return (f(x+h)-f(x-h)) / (2.0*h);
  };

  println("{}", f(5.0));

  println("{}", fprime(5.0));

  double sqrt7 = newton_root(f);
  println("{}",sqrt7);
}
