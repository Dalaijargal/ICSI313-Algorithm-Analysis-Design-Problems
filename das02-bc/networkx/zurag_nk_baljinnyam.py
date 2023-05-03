import networkit as nk
import file_reader as fr
import matplotlib.pyplot as plt

G,n=fr.readaspath('benchmark1/karate.txt')
print(G)

# draw the graph using nk viz
# nk.viztasks.drawGraph(G)
nk.centrality.Betweenness(G).run()
# plt.show()
