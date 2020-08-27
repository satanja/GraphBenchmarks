library(ggplot2)

# # create a data frame
# variety=rep(LETTERS[1:7], each=40)
# treatment=rep(c("high","low"),each=20)
# note=seq(1:280)+sample(1:150, 280, replace=T)
# data=data.frame(variety, treatment ,  note)
 
# # Classed boxplot
# ggplot(data, aes(x=variety, y=note, fill=treatment)) + 
#     geom_boxplot()

adjhash <- read.csv("out\\graph1.csv")
adjvec <- read.csv("out\\graph2.csv")
adjmatrix <- read.csv("out\\graph3.csv")
adjmatrixvec <- read.csv("out\\graph4.csv")
adjset <- read.csv("out\\graph5.csv")
adjflist <- read.csv("out\\graph6.csv")
adjdeque <- read.csv("out\\graph7.csv")
adjlist <- read.csv("out\\graph8.csv")

adjhash$Class <- "AdjHash"
adjvec$Class <- "AdjVec"
adjmatrix$Class <- "AdjMatrix"
adjmatrixvec$Class <- "AdjMatrixVec"
adjset$Class <- "AdjSet"
adjflist$Class <- "AdjForwardList"
adjdeque$Class <- "AdjDeque"
adjlist$Class <- "AdjList"

data <- rbind(
    adjhash,
    adjvec,
    adjset,
    adjflist,
    adjdeque,
    adjlist
)
class(data)

Tl = ggplot(data, aes(x=Class, y=loading, fill=Class)) 
Tt = ggplot(data, aes(x=Class, y=traversing, fill=Class)) 
Td = ggplot(data, aes(x=Class, y=deleting, fill=Class)) 

Tl <- Tl + geom_boxplot(outlier.shape = NA)
# ylim1 = boxplot.stats(data$y)$stats[c(1, 5)]
Tl <- Tl + coord_cartesian(ylim = quantile(data$ing, c(0.01, 0.99)))
Tt <- Tt + geom_boxplot(outlier.shape = NA)
Tt <- Tt + coord_cartesian(ylim = quantile(data$traversing, c(0.01, 0.99)))
Td <- Td + geom_boxplot(outlier.shape = NA)
Td <- Td + coord_cartesian(ylim = quantile(data$deleting, c(0.075, 0.925)))

Tl
Tt
Td

colMeans(adjhash[sapply(adjhash, is.numeric)])
colMeans(adjvec[sapply(adjvec, is.numeric)])
colMeans(adjmatrix[sapply(adjmatrix, is.numeric)])
colMeans(adjmatrixvec[sapply(adjmatrixvec, is.numeric)])
colMeans(adjset[sapply(adjset, is.numeric)])
colMeans(adjflist[sapply(adjflist, is.numeric)])
colMeans(adjdeque[sapply(adjdeque, is.numeric)])
colMeans(adjlist[sapply(adjlist, is.numeric)])
