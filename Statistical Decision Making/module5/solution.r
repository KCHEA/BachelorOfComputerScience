#1. load NutritionStudy
library(Lock5Data)
data("NutritionStudy")
attach(NutritionStudy)

#2. Test for H0: p=0.2 , HA: p!=0.2 where signficance level is 0.05 or 5%
## compute the test statistic
phat = mean(Smoke == "Yes")
phat
## compute the randomisation distribution
b = 10000
n = length(Smoke)
rand.dist = rep(NA,b)
for(i in 1:b){
  s = sample(c(TRUE,FALSE),n,replace=T,c(0.2,0.8))
  rand.dist[i] = mean(s == TRUE)
}
hist(rand.dist)

## compute the pvalue, this is a two tail test
2*mean(rand.dist <= phat)
## the pvalue is 0.0048 or0.48 which is less than than the significance level of 0.05 
## so therefore we reject the NULL hypothesis

#3 test for mean calories, H0: mu = 1700, HA: mu > 1700 with significance level of 0.1
## compute the test statistic 
xbar = mean(Calories)
xbar

## Compute the randomisation distribution 
shifted_sample = Calories - phat + 1700
b = 10000
rand.Dist = rep(NA,b)
for(i in 1:b){
  s = sample(shifted_sample,replace=T)
  rand.Dist[i] = mean(s)
}
hist(rand.Dist)

## compute the pvalue
mean(rand.Dist >= xbar)
## the pvalue is 0.0069 or 0.69% which is less than 0.1 so we reject the null hypothesis

#4 test mean calories, H0:sCalories - noCalories = 0, HA: sCalories - noCalories > 0
## compute the test statistic
smokeCal = Calories[Smoke == "Yes"]
noCal = Calories[Smoke == "No"]
dif = mean(smokeCal) - mean(noCal)
dif

## compute the randomisation distribution
Rand.dist = rep(NA,10000)
n1 = length(smokeCal)
n2 = length(noCal)
for(i in 1:10000){
  s1 = sample(Calories,n1,replace=T)
  s2 = sample(Calories,n2,replace=T)
  Rand.dist[i] = mean(s1) - mean(s2)
}
hist(Rand.dist)

## compute the pvalue
mean(Rand.dist >= dif)
## the pvalue is 0.09 or 9% which is more than the significance level of 0.01 so we do not
## reject the null hypothesis