#1. load NutritionStudy
library(Lock5Data)
data("NutritionStudy")
attach(NutritionStudy)

#2.a. Compute 95% confidence interval of mean calories using standard error
## first we need to bootstrap the sample
n = 10000
boot.dist = rep(1,n)
for(i in 1:n){
  s = sample(Calories, replace = TRUE)
  boot.dist[i] = mean(s)
}
## 95% confidence interval is CI = xbar +- 2*sd
CI = mean(boot.dist) + c(-1,1)*sd(boot.dist)
CI 

#2.b. computer 99% confidence interval using percentiles
quantile(boot.dist,c(0.005,0.995))

#3.Bootstrap for smoker and computer 95% confidence interval for proportion of smoker
b = 10000
smoke.dist = rep(1,n)
for(i in 1:b){
  s = sample(Smoke, replace=TRUE)
  smoke.dist[i] = mean(s == "Yes")
}

quantile(smoke.dist,c(0.05,0.95))
