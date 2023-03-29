import networkit as nk
import matplotlib.pyplot as plt
from time import time

erg = nk.generators.ErdosRenyiGenerator(1000, 0.08)
generated = erg.generate()

values = []
start = time()

for node in generated.iterNodes():
    values.append(generated.degree(node))

plt.hist(values)
plt.title("Erdos Renyi")
plt.ylabel("Number of degree")
plt.xlabel("Nodes")
plt.savefig("./image.png")

print(f"{time()-start} milliseconds")
