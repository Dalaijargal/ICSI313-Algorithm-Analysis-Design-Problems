#Erdos -Reney 
# #generate a random graph
import networkx as nx
import matplotlib.pyplot as plt
import heapq
#Erdoes-Renyi graph generate and write to file function
def erdos_renyi_graph(N, p, filename):
    graph = nx.erdos_renyi_graph(N, p)
    #conneced components
    #print(nx.number_connected_components(graph))
    nx.write_edgelist(graph, filename, data=False)
#erdos_renyi_graph(1000, 0.01, "graph.txt")
#read graph from file
def read_graph(filename):
    graph = nx.read_edgelist(filename, nodetype=int)
    return graph
class Gene:
    def __init__(self,ls:list=[], cc=0):
        self.cc = cc
        self.seq = ls
    def __lt__(self, other):
        return self.cc < other.cc
    def __gt__(self, other):
        return self.cc > other.cc
    def __eq__(self, other):
        return self.cc == other.cc
    def __le__(self, other):
        return self.cc <= other.cc
    def __ge__(self, other):
        return self.cc >= other.cc
    def __ne__(self, other):
        return self.cc != other.cc
    def __str__(self) -> str:
        return str(self.seq)

#min heap class
class MinHeap:
    def __init__(self):
        self.heap = []
    def push(self, item):
        heapq.heappush(self.heap, item)
    def pop(self):
        return heapq.heappop(self.heap)
    def top(self):
        return self.heap[0]
    def size(self):
        return len(self.heap)
    def empty(self):
        return len(self.heap) == 0
    def print(self):
        print(self.heap)
def all_paths(G):
    # Count the paths
    path_count = 0
    for source in G.nodes():
        for target in G.nodes():
            if source != target:
                # Find all simple paths between the source and target nodes
                all_paths = nx.all_simple_paths(G, source=source, target=target)
                # Count the paths
                path_count += sum(1 for _ in all_paths)
    return path_count

def zor(G):
    components = nx.connected_components(G)
    component_counts = [len(component) for component in components]
    paths = [count * (count - 1) / 2 for count in component_counts]
    return sum(paths)
