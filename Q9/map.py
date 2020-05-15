# plot
import numpy as np
from matplotlib import pyplot as plt
import math

file = open("graph.txt", "r")
x, y, x1, y1 = [], [], [], []
for l in file:
    row = l.split()
    x.append(float(row[0]))
    y.append(float(row[1]))
    x1.append(float(row[0]))
    y1.append(float(row[2]))


fig = plt.figure()
ax1 = fig.add_subplot(111)

# create line plot of y1(x)
(line1,) = ax1.plot(x, y, "g", label="Unordered")
ax1.set_xlabel("x")
ax1.set_ylabel("y", color="g")

# create shared axis for y2(x)
ax2 = ax1.twinx()

# create line plot of y2(x)
(line2,) = ax2.plot(x, y1, "r", label="Ordered")
ax2.set_ylabel("y", color="r")

# set title, plot limits, etc
plt.title("Question 9")
# plt.xlim(-2, 18)
# plt.ylim(0, 25)

# add a legend, and position it on the upper right
plt.legend((line1, line2), ("Function y1", "Function y2"))

plt.show()


# plt.xlabel("x")
# plt.ylabel("y")
# plt.plot(x, y, label="Unordered")
# plt.plot(x1, y1, label="Ordered")


# plt.legend()
# axes = plt.gca()
# axes.grid()
# plt.show()
