# read in

# plot
import numpy as np
from matplotlib import pyplot as plt

file = open("graph.txt", "r")
x, y = [], []
for l in file:
    row = l.split()
    x.append(row[0])
    y.append(row[1])


fig, ax = plt.subplots(1, 1)
# x = 0, 2, 4, 6, 8, 10, 12, 14, 16
# y = 0, 1.9, 2, 2, 2.4, 2.6, 2.25, 1.12, 0
plt.title("Question 4")
plt.xlabel("Time")
plt.ylabel("Velocity")
plt.plot(x, y)
axes = plt.gca()
axes.grid()
plt.show()
