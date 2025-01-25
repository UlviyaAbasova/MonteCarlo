\name{optionPricer1-package}
\alias{optionPricer1-package}
\alias{optionPricer1}
\docType{package}

\title{Monte Carlo Option Pricing for Up-and-In Call Options}

\description{
  This package provides a Monte Carlo simulation method for pricing up-and-in call options.
  The package uses a barrier option model and simulates asset prices using geometric Brownian motion.
}

\details{
  The main function of this package is \code{\link{getCallPrice}}, which computes the theoretical price of an up-and-in call option.
  The simulation is based on a Monte Carlo approach, where asset price paths are simulated and the option payoff is calculated if the barrier is breached.
  The user can customize the strike price, spot price, volatility, risk-free rate, barrier level, and the number of simulation paths.
}

\author{Your Name, maintainer: Your Name <your@email.com>}

\references{
  This package uses Monte Carlo methods for option pricing and can be compared with classical pricing models such as the Black-Scholes model.
}

\keyword{package}

\seealso{
  \code{\link{getCallPrice}}, \code{\link{runUpAndInMonteCarlo}}
}

\examples{
  \dontrun{
    ## Example of using the getCallPrice function to price an up-and-in call option:
    Expiry <- 0.75
    Strike <- 110
    Spot <- 105
    Vol <- 0.2
    r <- 0.05
    Bar
