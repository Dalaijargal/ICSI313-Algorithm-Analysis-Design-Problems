def remove_critical_nodes(G):
    critical_nodes = nx.articulation_points(G)
    modified_graph = G.copy()

    for node in critical_nodes:
        modified_graph.remove_node(node)

    return modified_graph

modified_graph = remove_critical_nodes(G);
print(modified_graph);

counter = 0
connected_components = nx.connected_components(modified_graph)

for component in connected_components:
    counter += 1
    # print(component)
print("Connected Components count: ", counter)