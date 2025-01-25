library(Rcpp)

# Function to calculate the up-and-in call option price using the C++ Monte Carlo simulation
monte_carlo_option_price <- function(S0, K, sigma, r, t, Barrier, N, M) {
  # Ensure the C++ function is called with the correct arguments
  price <- .Call("runUpAndInMonteCarlo", t, K, S0, sigma, r, Barrier, N)
  return(price)
}
