#ifndef RUNUPANDINMONTECARLO_H
#define RUNUPANDINMONTECARLO_H

// Declare the function using extern "C" to prevent name mangling
extern "C" {
  double runUpAndInMonteCarlo(double Expiry,
                              double Strike,
                              double Spot,
                              double Vol,
                              double r,
                              double Barrier,
                              unsigned long int NumberOfPaths);
}

#endif
