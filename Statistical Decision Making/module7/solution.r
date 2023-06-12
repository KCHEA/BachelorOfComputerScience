#1. load SalaryGender
library(Lock5Data)
data("SalaryGender")
attach(SalaryGender)

#2. create a bootstrap distribution for mean salary
boot.dist = rep(NA,10000)
for(i in 1:10000){
  s = sample(Salary,replace=T)
  boot.dist[i] = mean(s)
}

#3. find standard error of the mean salary from the bootstrap distribution
sd(boot.dist)

#4 Use central limit theorem to estimate SE and compare it to the bootstrap mean
n = length(Salary)
SE = sd(Salary)/sqrt(n)
SE

#5. simulate n = 1000, proportion p = 0.15, and probability is 0.13 or less
## compute test statistic 
phat = 0.13

## compute binomial distribution
p = 0.15
n = 1000
boot.dist = rbinom(100000,n,p)/n
p_simul = mean(boot.dist <= phat)
p_simul
## the probability that a random proportion is 0.13 or less is 0.04 or 4%

#6.use central limit theorem to compute problem 5 and compare it to that result
p = 0.15
SE = sqrt(p*(1-p)/n)
pnorm(0.13,p,SE)
## the probability that a random proportion is 0.13 or less is 0.038 or 3.8% which is close to 
## 4% from question 5
