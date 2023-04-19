
import networkit as nk 
import matplotlib.pyplot as plt 
import time 

def read_graph(fin):
    n = int(fin.readline())
    G = nk.Graph(n)
    d = {}
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

    return G, n


def draw_graphs(G, n):
    pos = nk.viztasks.drawGraph(G)
    plt.savefig('graph.png')

def approximate_closeness(G, k) :
    ac = nk.centrality.ApproxCloseness(G, k) 
    ac.run()
    return ac 

def complete_closeness(G, k):
    c = nk.centrality.Closeness(G) 
    c.run()
    return c 

def draw_xy_chart(x_data, y_data, max_x, max_y) :

    # Add axis labels and title
    plt.plot(x_data, y_data)
    plt.legend()
    plt.xlabel('K values')
    plt.ylabel('Time spent')
    plt.title('K and Time relation')

    plt.ylim(0,max_x)
    plt.xlim(0,max_y)
    plt.xticks(x_data, x_data)
    plt.yticks(y_data, y_data)  
    
    plt.show()
    plt.savefig('xy_chart.png')

if __name__ == '__main__':
    fin = open('benchmark1/netscience.txt', 'r') 
    G, n = read_graph(fin) 
    draw_graphs(G, n) 
    
    k_list = []
    time_list = []

    max_time = 0.0

    for i in range(3, n):
        start = time.perf_counter() 
        approximate_closeness(G, i)
        end = time.perf_counter() 
        time_diff = (end - start) * 1000 # milliseconds 
        rounded_ms = round(time_diff, 2)
        k_list.append(i)
        time_list.append((rounded_ms))
        max_time = max(max_time, time_diff)
        print('Approximate Closeness time for k = ', i, ' is ', rounded_ms ,' ms')
    
    draw_xy_chart(k_list, time_list, n, max_time)