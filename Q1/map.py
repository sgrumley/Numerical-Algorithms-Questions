import numpy as np
from matplotlib import pyplot as plt
import math

file = open("graph.txt", "r")
h, err, rerr, terr, ferr = [], [], [], [], []
for l in file:
    row = l.split()
    h.append(float(row[0]))
    err.append(float(row[1]))
    rerr.append(float(row[2]))
    terr.append(float(row[3]))
    ferr.append(float(row[4]))


plt.title("Question 1")
plt.xlabel("Time")
plt.ylabel("Height")
plt.plot(h, err, "r", label="Function Error")
plt.plot(h, rerr, "b", label="Round Off Error")
plt.plot(h, terr, "g", label="Truncation Error")
plt.plot(h, ferr, "y", label="Float Error")


plt.legend()
axes = plt.gca()
axes.grid()
plt.show()
