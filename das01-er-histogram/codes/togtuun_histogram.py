import networkit as nk
import matplotlib.pyplot as plt

erg = nk.generators.ErdosRenyiGenerator(100000, 0.08)
generated = erg.generate()

values = []

for node in generated.iterNodes():
    values.append(generated.degree(node))

plt.hist(values)
plt.title("Erdos Renyi")
plt.ylabel("Number of degree")
plt.xlabel("Nodes")
plt.savefig("./image.png")
