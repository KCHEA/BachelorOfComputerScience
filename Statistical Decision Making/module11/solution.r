#1. load StudentSurvey
library(Lock5Data)
data("StudentSurvey")
attach(StudentSurvey)

#2. Remove case for which Award or GPA are missing
nix = which(is.na(StudentSurvey$GPA))
Award = Award[-nix]
GPA = GPA[-nix]

#3. For Award, compute total variaton(SST) of GPA and SSE
k = 3 #there are 3 awards in total
idx.Nobel = which(Award == "Nobel")
n.Nobel = length(idx.Nobel)
idx.Olympic = which(Award == "Olympic")
n.Olympic = length(idx.Olympic)
idx.Academy = which(Award == "Academy")
n.Academy = length(idx.Academy)
N = length(GPA)
sd(GPA)
GPA
SST = (N-1)*sd(GPA)^2
SSE = (n.Nobel-1)*sd(GPA[idx.Nobel])^2 + (n.Olympic-1)*sd(GPA[idx.Olympic])^2 + (n.Academy - 1)*sd(GPA[idx.Academy])^2

#4. Compute the F statistic and the pvalue
SSG = SST - SSE
SSG

F = (SSG/(k-1))/(SSE/(N-K))
pval = 1-pf(F,k-1,N-k)
pval
## the pvalue is near zero which is less than 5% so we reject the null hypothesis
## this mean that the mean GPA of student preferring Award are different

#5. Confirm part 4 by doing randomisation distribution
B = 100000
rand.dist = rep(NA,B)
for(i in 1:B){
  gpa = sample(GPA)
  sse = (length(idx.Noble)-1)*sd(gpa[idx.Nobel])^2 + (length(idx.Olympic)-1)*sd(gpa[idx.Olympic])^2 + (length(idx.Academy-1))*sd(gpa[idx.Academy])^2
  ssg = SST - sse
  rand.dist[i] = (ssg/(k-1))/(sse/(k-1))
}
pval.rand = mean(rand.dist >= F)
pval.rand
## this pvalue is consistent with the one from part 4

#6. use aov and compare result to part 4 and 5
summary(aov(GPA~Award))
##the output is: SSG = 3.82, SSE = 50.76 which mean SST = 54.88
## the F statistic and pvalue is also consistent with part 4 and 5

#7. For each value in Award, compute a 95% confidence interval for the mean GPA
xbar.Nobel = mean(GPA[idx.Nobel])
xbar.Olympic = mean(GPA[idx.Olympic])
xbar.Academy = mean(GPA[idx.Academy])
SE = sqrt(SSE/(N-k))
tstar = qt(0.975,N-k)

xbar.Nobel + c(-1,1)*tstar*SE/sqrt(n.Nobel)
xbar.Olympic + c(-1,1)*tstar*SE/sqrt(n.Olympic)
xbar.Academy + c(-1,1)*tstar*SE/sqrt(n.Academy)

#8. use pairwise.t.test to test difference in mean GPA for each paired of preferred Awards
#   at a significance level of 1%
pairwise.t.test(GPA,Award)
## there is only evidence for different in mean GPAs between those that preferred a Nobel
## and olympic prize and nothing for other pairing
## We can also say we do not have enough evidence for any of these pairs to conclude there is
## a difference