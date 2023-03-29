import networkit as nk
import matplotlib.pyplot as plt
from time import time

erg = nk.generators.ErdosRenyiGenerator(10000, 0.08)
generated = erg.generate()

values = []
start = time()

for node in generated.iterNodes():
    values.append(generated.degree(node))

plt.grid(color='#EEEEEE10')
_, _, patches = plt.hist(values, 20, rwidth=0.9)
plt.title("Erdos Renyi /n = 1000, p=0.08/")
plt.ylabel("Frequency")
plt.xlabel("Number of degree")
for pp in patches:
    x, y = pp.xy
    plt.text(x, pp.get_height(), pp.get_height(), {'size': 7})

plt.savefig("./image.png")

print(f"{time()-start} milliseconds")
