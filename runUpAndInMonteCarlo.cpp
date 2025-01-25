#include "runUpAndInMonteCarlo.h"
#include "getOneGaussianByBoxMueller.h"
#include <cmath>

extern "C" {
  // Definition of the Up-and-In Call option pricing function
  double runUpAndInMonteCarlo(double Expiry,
                              double Strike,
                              double Spot,
                              double Vol,
                              double r,
                              double Barrier,
                              unsigned long int NumberOfPaths) {
    
    double variance = Vol * Vol * Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;
    double movedSpot = Spot * exp(r * Expiry + itoCorrection);
    
    double thisSpot;
    double runningSum = 0;
    
    for (unsigned long i = 0; i < NumberOfPaths; i++) {
      double barrierHit = 0;
      double thisGaussian = getOneGaussianByBoxMueller();
      thisSpot = movedSpot * exp(rootVariance * thisGaussian);
      
      // Check if the barrier is breached
      if (thisSpot >= Barrier) {
        barrierHit = 1;
      }
      
      // If the barrier is hit, calculate the payoff
      if (barrierHit) {
        double thisPayoff = thisSpot - Strike;
        if (thisPayoff > 0) runningSum += thisPayoff;
      }
    }
    
    // Discount the mean payoff to present value
    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r * Expiry);
    return mean;
  }
}
