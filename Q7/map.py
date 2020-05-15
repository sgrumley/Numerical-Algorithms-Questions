# plot
import numpy as np
from matplotlib import pyplot as plt
import math

file = open("graph.txt", "r")
x, y = [], []
for l in file:
    row = l.split()
    x.append(float(row[0]))
    y.append(float(row[1]))


plt.title("Question 4")
plt.xlabel("Time")
plt.ylabel("Height")
plt.plot(x, y)
plt.plot(182.808, 110.501, marker="^")


plt.legend()
axes = plt.gca()
axes.grid()
plt.show()
