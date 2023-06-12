#1. load SalaryGender
library(Lock5Data)
data("SalaryGender")
attach(SalaryGender)

#2. use prop.test to find 95% confidence interval for teacher that have phd
havePhD = sum(PhD)
n = length(PhD)
prop.test(havePhD,n,conf.level = 0.9)

#3. Confirm part 2 without using prop.test
p = havePhD/n
SE = sqrt(p*(1-p)/n)
zstar = qnorm(0.975)
CI = p +c(-1,1)*zstar*SE
CI
## They have approximately the same confidence interval

#4. use prop.test to find, H0:p=0.5, HA:p<0.5 at significance level of 5%
prop.test(havePhD,n,p=0.5,alternative="less")
##the pvalue is 0.018 which is 1.8% and less then the significance level of 5% therefore
##we reject the null hypothesis

#5. confirm part 4 without using prop.test
## compute test statistic 
phat = havePhD/n
phat

## compute the z score
p = 0.5
SE = sqrt(p*(1-p)/n)
z = (phat - p)/SE
pvalue = pnorm(z)
pvalue
## THe pvalue is 0.014 or 1.4% which is close to 1.8% in part 4

#6. use t.test to find 90% confidence level for mean salary
t.test(Salary,conf.level = 0.9)

#7. confirm part 6 without using t.test
xbar = mean(Salary)
n = length(Salary)
SE = sd(Salary)/sqrt(n)
CI = xbar + c(-1,1)*SE*qt(0.95,df=n-1)
CI ## it is (45.51, 59.53)

#8. use t.test to test, H0: mu=50, HA: mu>50 at a significance level of 5% on mean salary
t.test(Salary,mu=50,alternative="greater")
## the pvalue is 0.275 or 27.5 which is more than the significance level of 5% 
## so therefore we do not reject the null hypothesis

#9. confirm part 8 without using t.test
## compute test statistic
xbar = mean(Salary)

## compute t score
mu = 50
n = length(Salary)
SE = sd(Salary)/sqrt(n)
t = (xbar - mu)/SE

pvalue = pt(t,df=n-1,lower.tail = F)
pvalue

## the pvaue is 0.275 or 27.5% which is the same as part 8