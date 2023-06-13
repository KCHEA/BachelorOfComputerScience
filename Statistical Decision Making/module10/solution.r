#1. load StudentSurvey
library(Lock5Data)
data("StudentSurvey")
attach(StudentSurvey)

#2. use chisq.test to test proportion for award are 0.2 for academy, 0.3 for nobel and 
#   0.5 for olympic at significance level of 5%
## this is a goodness of fit test
academy = sum(Award == "Academy")
nobel = sum(Award == "Nobel")
olympic = sum(Award == "Olympic")
f = c(academy,nobel,olympic) #this is our observed frequency
e = c(0.2,0.3,0.5)*length(Award) #this is our expected frequency
chisq.test(table(Award),p=c(0.2,0.3,0.5))
##the pvalue is near zero which is less than 5% so we can reject the null hypothesis

#3. perform part2 using randomisation distribution and compare result
b = 100000
rand.dist = rep(NA,b)
for(i in 1:b){
  r = rmultinom(1,length(Award),c(0.2,0.3,0.5))
  rand.dist[i] = sum((r - e)^2/e)
}
v = sum((f-e)^2/e)
mean(rand.dist >= v)
## the pvalue is also near zero which is identical to part 2

#4. use chisq.test to test association between sex and preferred award at significance level of 5%
## this is a test of independence
## the null hypothesis is that sex and award are independence
## the alternative hypothesis is that they are not independence
f = table(Award,Sex)
n = length(Award)
E = rowSums(f) %o% colSums(f)/n
E ## all expected count are at least 5 so we can use chisq.test
chisq.test(f)
## the pvalue is 0.016 or 1.6% which is less than 5% so we can reject the null hypothesis
## so there is strong evidence that sex and preferred award are associated

#5. Use randomisation distribution to test association between smoking and preferred award
f = table(Smoke,Award)
E = rowSums(f) %o% colSums(f)/n
E #one of the expected frequency is less than 5 so we cannot use chisq.test
b = 100000
rand.Dist = rep(NA,b)
for(i in 1:b){
  F = table(sample(Smoke), Award)
  rand.Dist[i] = sum((F-E)^2/E)
}
hist(rand.Dist, breaks=30)
v = sum((f-E)^2/E)
v
mean(rand.Dist >=v)
## the pvalue is 0.52 or 52% which is very large that we have obtain from the randomisation
## distribution so therefore we do not reject the null hypothesis
## so there is no strong evidence for an association between smoking and preferred award
