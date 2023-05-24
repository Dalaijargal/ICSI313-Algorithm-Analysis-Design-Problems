import networkx as nx
import networkit as nk
import matplotlib.pyplot as plt
import numpy as np
import random
from func import *
import pandas as pd
import networkx as nx


def zor(G):
    components = nx.connected_components(G)
    component_counts = [len(component) for component in components]
    paths = [count * (count - 1) / 2 for count in component_counts]
    return sum(paths)

n = 80
iteration = 1500

graph = read_graph("oc.graph")
N = graph.number_of_nodes()
node_list = list(graph.nodes())

k=190
genes = np.array([random.sample(node_list, k) for i in range(n)])

population = []
for i in [random.sample(node_list, k) for i in range(n)]:
    population.append(Gene(i,zor(graph.subgraph([element for element in node_list if element not in i]))))

used = []
i=0
while i < n :
    population[i].seq.sort()
    used.append(population[i].seq)
    i+=1
ccs = []

print("k = %d n = %d"%(k,n))

population.sort(key=lambda x: x.cc)
i=0
critical_nodes = list(nx.articulation_points(graph))

while i<iteration:
    i+=1
    j=0
    while j<n//1.8:
        j+=1
        gene = random.randint(0, n-1)
        mutation_point1 = random.randint(0, k-1)
        new_seq = population[gene].seq.copy()
        cod1 = random.choice(critical_nodes)
        while cod1 in new_seq:
            cod1 = random.choice(node_list)
        new_seq[mutation_point1] = cod1
        new_seq.sort()
        check=0
        for s in population:
            if new_seq == s.seq:
                check+=1
        if new_seq in used :
            check+=1
        else :
            used.append(new_seq)
        if check > 0 :
            j -=1
        else:
            new_gene = Gene(new_seq, zor(graph.subgraph([element for element in node_list if element not in new_seq])))
            population.append(new_gene)
        
    population.sort(key=lambda x: x.cc)
    population = population[:n]
    
    j=0
    while j< n//10:
        j+=1
        gene1 = random.randint(0, n- 1)
        gene2 = random.randint(0, n - 1)
        crossover_point = random.randint(0, k-1)
        new_seq = population[gene1].seq.copy()
        new_seq[crossover_point:] = population[gene2].seq[crossover_point:].copy()
        new_seq.sort()
        check=0
        for s in population:
            if new_seq == s.seq:
                check+=1
        if new_seq in used :
            check+=1
        else :
            used.append(new_seq)
        dup = {x for x in new_seq if new_seq.count(x) > 1}
        if len(dup) > 0 :
            check+=1
        if check>0 :
            j -=1
        else :
            new_gene = Gene(new_seq, zor(graph.subgraph([element for element in node_list if element not in new_seq])))
            population[gene2] = new_gene

    population.sort(key=lambda x: x.cc)
    print("->%d : %d" %(i, population[0].cc))
    ccs.append(population[0].cc)
print(population[0].seq)