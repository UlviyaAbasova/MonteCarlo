#include <Rcpp.h>
#include "runUpAndInMonteCarlo.h"  // Include the header for your Up-and-In Monte Carlo function
using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
double getCallPrice(
    double Expiry = 0.5,          // Time to maturity
    double Strike = 100,          // Strike price
    double Spot = 120,            // Spot price
    double Vol = 0.2,             // Volatility
    double r = 0.06,              // Risk-free rate
    double Barrier = 110,         // Barrier level for up-and-in call
    unsigned long NumberOfPaths = 10000  // Number of simulations
) {
  // Call the modified Monte Carlo function with the barrier parameter
  double result = runUpAndInMonteCarlo(Expiry, Strike, Spot, Vol, r, Barrier, NumberOfPaths);
  return result;
}
