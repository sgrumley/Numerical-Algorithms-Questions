# plot
import numpy as np
from matplotlib import pyplot as plt

file = open("graph.txt", "r")
t, eul, rk = [], [], []
for l in file:
    row = l.split()
    t.append(float(row[0]))
    eul.append(float(row[1]))
    rk.append(float(row[2]))


plt.title("Question 5")
plt.xlabel("Time")
plt.ylabel("Velocity")
plt.plot(t, eul, "r", label="Eulers Method")
plt.plot(t, rk, "b", label="RK 4th Order")


plt.legend()
axes = plt.gca()
axes.grid()
plt.show()
