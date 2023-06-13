#1. load SalaryGender
library(Lock5Data)
data(SalaryGender)
attach(SalaryGender)

#2. use prop.test to get 95% confidence interval for difference between p1 and p2
## f1 = number of male with phd
## f2 = proportion of female with phd
f1 = sum(PhD[Gender == 1])
n1 = length(PhD[Gender == 1])
f2 = sum(PhD[Gender == 0])
n2 = length(PhD[Gender == 0])
c(f1,n1-f1,f2,n2-f2) ## The value are all above 10 so we can use prop.test

prop.test(c(f1,f2),c(n1,n2),conf.level = 0.95)

#3. confirm part2 without using prop.test
## p1 = proportion of male with phd
## p2 = proportion of female with phd
## CI = (p1-p2) +c(-1,1)*zscore*SE
p1 = f1/n2
p2 = f2/n2
zscore = qnorm(0.975)
SE = sqrt(p1*(1-p1)/n1 + p2*(1-p2)/n2)
CI = (p1-p2) + c(-1,1)*zscore*SE
CI ## the result is similar to the one using prop.test

#4. use prop.test, H0: pm = pf, HA: pm > pf with a significance level of 1% or 0.01
prop.test(c(f1,f2),c(n1,n2),alternative="greater")
## the pvalue is 0.05 or 5% which is more than the significance level 
## so therefore we do not reject the null hypothesis

#5. use t.test to compute 90% CI for difference in mean salary between male and female teacher
salary_male = Salary[Gender == 1]
salary_female = Salary[Gender == 0]
t.test(salary_male,salary_female,conf.level = 0.9)

#6. use t.test, H0:mu_male=mu_female, HA: mu_male>mu_female, significance level of 5%
t.test(salary_male,salary_female,alternative="two.sided")
## the pvalue is 0.01 or 1% which is less the the significance level of 5%
## so therefore we reject the null hypothesis

#7. load WetSuits 
data("Wetsuits")
attach(Wetsuits)

#8. use t.test to test if wearing wetsuits result in greater velocity, significance level of 5%
t.test(Wetsuit,NoWetsuit,alternative="greater",paired = T)
## the pvalue is near zero and less then the significance level of 5%
## so therefore we reject the null hypothesis that both result in the same velocity
## so there is strong evidence to suggest that wearing swimsuit increases swimming velocity

#9. repeat part 8 without pairing
t.test(Wetsuit,NoWetsuit,alternative="greater")

## the pvalue without pairing is magnitude larger than with pairing at 0.09 or 9% which is more
## than the significance level of 5% so there is not enough evidence that wearing a swimsuit
## increases your swimming velocity