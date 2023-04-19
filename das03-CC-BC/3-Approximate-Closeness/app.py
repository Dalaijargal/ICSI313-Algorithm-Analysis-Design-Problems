from dep import *
import matplotlib.pyplot as plt
import random
import math


def my_read_graph_mapped(fin):
    fin = open(fin,"r")    
    n = int(fin.readline())
    G = nk.Graph(n)
    id = 0
    
    while True:
        try:
            line = fin.readline()
            
        except:
            break

        line = line.split()
        if len(line) == 0:
            break

        x = int(line[0][:-1])
        id += 1

        arr = [int(y) for y in line[1:]]
        for y in arr:
            if (x < y):
                G.addEdge(x, y, addMissing = True)

    return G, id


g,n = my_read_graph_mapped("./football.txt")
cc = nk.centrality.Closeness(g,True,False)



for k in [int(math.log2(n)**i) for i in range(1,4)]:
    ac = nk.centrality.ApproxCloseness(g,k)
    cc.run()
    ac.run()
    x = {j:i[0] for i,j in zip(cc.ranking(),range(n)) } #[i for i in ac.ranking()]
    rnkx = [i for i in range(n)]
    rnky = []
    y = {j:i[0] for i,j in zip(ac.ranking(),range(n)) } #[i for i in cc.ranking()]

    for i in range(n):
        for j in range(n):
            if (y[j] == x[i]):
                rnky.append(j)
                break
    dsum = 0
    for i in range(n):
        dsum += (rnkx[i]-rnky[i])**2
    p= 1 -(6*dsum)/(n**3-n)
    
    plt.title(f"K samples  Spearman's rank correlation coefficient={round(p, 4)}")
    plt.plot(rnkx,rnky)
    
    plt.show()
