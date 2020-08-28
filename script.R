library(plotly)

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
    adjmatrix,
    adjmatrixvec,
    adjset,
    adjflist,
    adjdeque,
    adjlist
)
class(data)

Tl <- plot_ly(data, x= ~vertices, y= ~edges, z= ~loading, color = ~Class)
Tl <- Tl %>% add_markers()
Tl <- Tl %>% layout(scene = list(xaxis = list(title = 'vertices'),
                     yaxis = list(title = 'edges'),
                     zaxis = list(title = 'loading time (ms)')))

Tl

Tt <- plot_ly(data, x= ~vertices, y= ~edges, z= ~traversing, color = ~Class)
Tt <- Tt %>% add_markers()
Tt <- Tt %>% layout(scene = list(xaxis = list(title = 'vertices'),
                     yaxis = list(title = 'edges'),
                     zaxis = list(title = 'traversal time (ms)')))

Tt

Td <- plot_ly(data, x= ~vertices, y= ~edges, z= ~deleting, color = ~Class)
Td <- Td %>% add_markers()
Td <- Td %>% layout(scene = list(xaxis = list(title = 'vertices'),
                     yaxis = list(title = 'edges'),
                     zaxis = list(title = 'reduction time (ms)')))

Td

minibench <- read.csv("out\\minibench.csv");
mbp <- plot_ly(minibench, x = ~length, y = ~deleting, color = ~Class)
mbp
