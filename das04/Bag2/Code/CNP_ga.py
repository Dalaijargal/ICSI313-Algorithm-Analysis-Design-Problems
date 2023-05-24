import numpy 
import random
import networkx as nx

def tournament_selection(population, pop_fitness, tournament_size):
    # Select random individuals for the tournament
    randnum = list(range(0, len(population)))
    random.shuffle(randnum)
    tournament_idx = randnum[:tournament_size]

    # Evaluate the fitness of the tournament participants
    tournament_fitness = [pop_fitness[idx] for idx in tournament_idx]
    # print(tournament_fitness)

    # Find the individual with the highest fitness in the tournament
    winner_index = tournament_fitness.index(min(tournament_fitness))
    winner = tournament_idx[winner_index]
    # print(pop_fitness[winner])
    return winner

def calc_fitness(gr, individual):
    reduced_graph = gr.copy()
    reduced_graph.remove_nodes_from(individual)

    components = list(nx.connected_components(reduced_graph))
    fitness = 0 
    for component in components :
        fitness += len(component) * (len(component) - 1) / 2
    return fitness

graph_file = './OClinks.txt'

graph = nx.Graph()

with open(graph_file, 'r') as file:
    for line in file:
        if line.strip():  # Ignore empty lines
            parts = line.split(':')
            node = int(parts[0])
            if len(parts) == 1:
                graph.add_node(node)
                continue
            neighbors = list(map(int, parts[1].split()))
            graph.add_edges_from((node, neighbor) for neighbor in neighbors)

# pop_size тэгш, mut_prob-д хуваагддаг
pop_size = 100
gene_cnt = 380
generation_cnt = 100

numbers = list(range(0, 1898))
# Creating initial population randomly 
population = []
for i in range(pop_size):
    random.shuffle(numbers)
    res = numbers[:gene_cnt]
    population.append(res)


for generation in range(generation_cnt):
    # array to save each fitness of population
    pop_fitness = {}
    # fitness value бага байвал сайн шийд
    fitness_min = float('inf') 
    for i in range(pop_size) :
        pop_fitness[i] = calc_fitness(graph, population[i])

        if pop_fitness[i] < fitness_min :
            fitness_min = pop_fitness[i]  

    print("Generation : ", generation)
    print("Best result : ", fitness_min)

    offsprings = population.copy()
    for i in range(int(pop_size / 2)):
        # Parents selection
        parent1_key = tournament_selection(population, pop_fitness, 2)
        parent2_key = tournament_selection(population, pop_fitness, 2)
        parents = [population[parent1_key], population[parent2_key]]

        # Crossover
        crossover_point = int(gene_cnt / 2)

        off = [[0] * gene_cnt for _ in range(2)]

        for k in range(int(gene_cnt/2)):
            off[0][k] = parents[0][k]
            off[1][k] = parents[1][k]

        j = 0
        for k in range(int(gene_cnt/2), gene_cnt):
            while j < gene_cnt:
                if parents[1][j] not in off[0]:
                    off[0][k] = parents[1][j]
                    j += 1
                    break
                else:
                    j += 1
        
        j = 0
        for k in range(int(gene_cnt/2), gene_cnt):
            while j < gene_cnt:
                if parents[0][j] not in off[1]:
                    off[1][k] = parents[0][j]
                    j += 1
                    break
                else:
                    j += 1

        offsprings[i] = off[0]
        offsprings[pop_size - 1 - i] = off[1]

    mut_prob = 0.1
    mutrandom = list(range(0, pop_size))
    random.shuffle(mutrandom)
    res = mutrandom[:int(pop_size * mut_prob)]
    for i in range(int(pop_size * mut_prob)) :
        mutation_point = numpy.random.randint(0, gene_cnt)
        new_gene = numpy.random.randint(0, 1899)
        offsprings[res[i]][mutation_point] = new_gene

    off_fitness = {} 
    for i in range(len(offsprings)) :
        off_fitness[i] = calc_fitness(graph, offsprings[i])

    # eliminate worst individuals
    merged_fitness = {}
    for i, (key, value) in enumerate(pop_fitness.items()):
        merged_fitness[i] = value
    for i, (key, value) in enumerate(off_fitness.items(), start=len(pop_fitness)):
        merged_fitness[i] = value
    sorted_merged_fitness = dict(sorted(merged_fitness.items(), key=lambda x: x[1], reverse=False))

    merged_population = {}
    merged_population = {i: value for i, value in enumerate(population)}
    merged_population.update({i: value for i, value in enumerate(offsprings, start=len(population))})

    first_keys = list(sorted_merged_fitness.keys())[:(pop_size)]
    population = [merged_population[key] for key in first_keys]
    
