# read in
def func(x):
    l = 2800000 / (2800000 - 13300 * x)

    return 2510 * math.log(l) - 9.81 * x - 335


# plot
import numpy as np
from matplotlib import pyplot as plt
import math

file = open("graph.txt", "r")
x, y = [], []
for l in file:
    row = l.split()
    x.append(row[0])
    y.append(row[1])


xval = np.arange(50.0, 80.0)
yval = []
for i in xval:
    yval.append(func(i))

plt.title("Question 4")
plt.xlabel("Time")
plt.ylabel("Velocity")
plt.plot(xval, yval, label="f(x)")


for i in range(len(x) - 1):
    ypair = func(float(x[i]))
    plt.plot(float(x[i]), ypair, marker="^")

plt.legend()
axes = plt.gca()
axes.grid()
plt.show()
