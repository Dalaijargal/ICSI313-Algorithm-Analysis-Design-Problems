import networkx as nx
from scipy.stats import spearmanr
import matplotlib.pyplot as plt

G = nx.karate_club_graph()

closeness = nx.closeness_centrality(G)
betweenness = nx.betweenness_centrality(G)

closeness_rank = {k: v for k, v in sorted(closeness.items(), key=lambda item: item[1], reverse=True)}
betweenness_rank = {k: v for k, v in sorted(betweenness.items(), key=lambda item: item[1], reverse=True)}

correlation, pvalue = spearmanr(list(closeness_rank.values()), list(betweenness_rank.values()))

plt.scatter(list(closeness_rank.values()), list(betweenness_rank.values()))
plt.xlabel('Closeness Centrality Rank')
plt.ylabel('Betweenness Centrality Rank')
plt.title(f"Spearman's rank correlation coefficient: {correlation:.2f}")
plt.show()

nx.draw(G, with_labels=True)
plt.show()