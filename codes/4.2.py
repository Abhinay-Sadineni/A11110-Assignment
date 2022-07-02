import numpy as np
import matplotlib.pyplot as plt
import mpmath as mp
simlen = 1000000
randvar = np.loadtxt('./tri.dat',dtype='double')


x = np.linspace(-5,5,40)
CF=[]
for i in range(0,40):
	CF_ind = np.nonzero(randvar < x[i]) 
	CF_n = np.size(CF_ind)
	CF.append(CF_n/simlen) 
	
	
plt.plot(x[0:40].T,CF,"o")
plt.grid()
plt.xlabel('$x$')
plt.ylabel('$F_X(x)$')
plt.savefig("../figs/tri_cdf.pdf")
plt.savefig("../figs/tri_cdf.eps")
plt.show()
