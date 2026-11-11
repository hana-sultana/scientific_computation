#include <ranges>
namespace rng = std::ranges;
#include <algorithm>
#include <print> //for println
using std::println;

int main() {

  auto isprime = [] ( int n ) {
    auto is_divisor =
      [n] ( int d ) -> bool {
	return n%d==0;
      };
    // going to test from 2 to n-1
    return rng::none_of( 
		rng::views::iota(2,n),
		is_divisor
		 );
  }; // end of the `isprime' lambda

  // lambda used by itself:
  // isprime(27)
  // however, that's not how you solve this exercise.

  for ( auto n :
	  rng::views::iota(2)// you start with the first prime number
          | rng::views::filter(isprime)//this evualtes each number to see if it it is prime
          | rng::views::take(20) )// this gives you the first 20 primes 
    println("{}",n);

  return 0;

}
