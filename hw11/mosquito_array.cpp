#include <iostream>
#include <array>
#include <random>
#include <cmath>
#include <chrono>
#include "cxxopts.hpp"
using std::cout;
using std::array;

using myclock = std::chrono::high_resolution_clock;

array<float,2> random_step() {
  // static: a single generator instance is ever created
  static std::random_device r;
  static std::default_random_engine generator{ r() };
  std::uniform_real_distribution<float> distribution(0.,2*M_PI);

  array<float,2> inc;
  auto random_angle= distribution(generator);
  // set to random unit vector
  inc.at(0) = std::cos(random_angle);
  inc.at(1) = std::sin(random_angle);
  return inc;
}

int main(int argc,char** argv) {

  cxxopts::Options options("mosquito_array","mosquito random walk");
  options.add_options()
    ("n","number of steps",cxxopts::value<int>()->default_value("1000"))
    ;
  auto result = options.parse(argc,argv);
  int n = result["n"].as<int>();

  auto start_time = myclock::now();

  array<float,2> position{0.f,0.f};
  for ( int step=0; step<n; ++step ) {
    auto increment = random_step();
    /* add increment to position */
    for (int id=0; id<position.size(); ++id)
      position.at(id) += increment.at(id);
  }
  // evaluate final distance
  float distance = std::sqrt( position.at(0)*position.at(0)
                              + position.at(1)*position.at(1) );

  auto duration = myclock::now()-start_time;
  auto microsec_duration =
    std::chrono::duration_cast<std::chrono::microseconds>
                (duration);

  cout << "array: n=" << n << ", final distance=" << distance << "\n";
  cout << "This took "
       << microsec_duration.count() << "usec\n";

  return 0;
};
