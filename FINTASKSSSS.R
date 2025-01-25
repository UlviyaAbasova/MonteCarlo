.rs.restartR()

devtools::build()
setwd("/Users/ulviyaabasova/Desktop/AF-RCPP-2024-2025-main/packages/optionPricer1")
devtools::build()
devtools::install()
library(optionPricer1)
remove.packages("optionPricer1")
Sys.setlocale("LC_ALL", "en_US.UTF-8")

devtools::clean_dll()   # Clean old dynamic libraries
devtools::document()    # Regenerate documentation
devtools::install()     # Reinstall the package
# Reinstall the package

Rcpp::sourceCpp("/Users/ulviyaabasova/Desktop/AF-RCPP-2024-2025-main/packages/optionPricer1/src/main.cpp")

# Call the function from R
result <- getCallPrice(Expiry = 1.0, Strike = 100, Spot = 95, Vol = 0.2, r = 0.05, Barrier = 110, NumberOfPaths = 10000)
print(result)


