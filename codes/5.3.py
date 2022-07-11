import numpy as np
import mpmath as mp
import scipy 
import matplotlib.pyplot as plt

N=1000000
randvar = np.loadtxt('mix.dat',dtype='double')
x = range(N)
plt.plot(x,randvar,"o")
plt.grid() 
plt.xlabel('Scatter plot')
plt.ylabel('Y')
plt.savefig('../figs/scatter_plot.pdf')
plt.savefig('../figs/scatter_plot.eps')
plt.show()
