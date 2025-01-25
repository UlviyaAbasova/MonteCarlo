#include "getOneGaussianByBoxMueller.h"
#include <cmath>
#include <random>  // C++11 random number generation

double getOneGaussianByBoxMueller(){
  static std::random_device rd;
  static std::mt19937 gen(rd());  // Mersenne Twister random number generator
  static std::uniform_real_distribution<> dis(-1.0, 1.0);  // Uniform distribution between -1 and 1
  
  double x, y, sizeSquared, result;
  
  do {
    x = dis(gen);  // Generate random x
    y = dis(gen);  // Generate random y
    sizeSquared = x * x + y * y;
  } while (sizeSquared >= 1.0);  // Ensure uniform distribution
  
  result = x * sqrt(-2 * log(sizeSquared) / sizeSquared);  // Box-Muller transformation
  
  return result;
}
