#1 Load ExerciseHours
library(Lock5Data)
data("ExerciseHours")
attach(ExerciseHours)

#2 Plot relationship between Sex/Hand, Sex/Pulse, Exercise/Pulse
# Sex/Hand, they are both categorical variable so we will use barplot
barplot(table(Sex, Hand), legend=TRUE) #it seem that men are more likely to be left-handed

# Sex/pulse, Sex is categorical and Pulse is quantitative so we use boxplot
boxplot(Pulse ~ Sex) #it seem that female have higher range of pulses

#Exercise/Pulse Both are quantitative so we use plot
plot(Exercise,Pulse) #the plot doesn't show any strong association between the two
cor(Exercise,Pulse) #the correlation is small indicating a weak linear association

