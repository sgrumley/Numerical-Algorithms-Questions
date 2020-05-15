


    # plot
import numpy as np
from matplotlib import pyplot as plt
import math

m1 = [ 8.953, 16.405, 22.607, 27.769, 32.065, 35.641, 38.617, 41.095, 43.156, 44.872, 46.301, 47.490, 48.479, 49.303, 49.988 ]
m2 = [ 11.240, 18.570, 23.729, 27.556, 30.509, 32.855, 34.766, 36.351, 37.687, 38.829, 39.816, 40.678, 41.437, 42.110, 42.712 ]
y  = [ 10.00, 16.30, 23.00, 27.50, 31.00, 35.60, 39.00, 41.50, 42.90, 45.00, 46.00, 45.50, 46.00, 49.00, 50.00 ]
x  = [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 ]

lm1, lm2, ly, lx = [],[],[],[]
for i in range(len(x)):
    lx.append(math.log(x[i]))
    ly.append(math.log(y[i]))
    lm1.append(math.log(m1[i]))
    lm2.append(math.log(m2[i]))


plt.title("Question 8 ln")
plt.xlabel("Time")
plt.ylabel("Measured")
for i in range(len(x)):
    plt.plot(lx[i], ly[i], "r", marker="^")

plt.plot(lx, lm1, "b",  label= "Model 1")
plt.plot(lx, lm2, "g",  label= "Model 2")


plt.legend()
axes = plt.gca()
axes.grid()
plt.show()