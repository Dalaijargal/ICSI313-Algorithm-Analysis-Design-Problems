# ajilluulah jishee: python3 file_reader.py benchmark1/karate.txt

import networkit as nk
from sys import stdin, stdout
import argparse

def my_read_graph_mapped(fin):
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

    return G, id

    
def print_graphs(G,n):
    # for u in G.iterNodes():
    #     print(u,':')
    for x in range(0, n):
        print(x,':',end=' ')
        for v in G.iterNeighbors(x):
            print(v, end=' ')
        print()


def arg_setup():
    parser = argparse.ArgumentParser(description='Example')
    parser.add_argument('-n', '--nrun', dest='nrun', type = int, help='The number of runs', default = 1)
    parser.add_argument('file', help = 'The file that contains graph information')
    return parser

def main(): 

    # Let's run in t threads
    num_t = 1
    nk.setNumberOfThreads(num_t)

    parser = arg_setup()
    args = parser.parse_args()

    with open(args.file, 'r') as fin:
        G, n = my_read_graph_mapped(fin)
    

    # BG = nk.Graph(G)

    print_graphs(G, n)

if __name__ == '__main__':
    # sys.setrecursionlimit(int(1e9))
    main()

def readaspath(path):
    with open(path, 'r') as fin:
        G, n = my_read_graph_mapped(fin)
    return [G, n]