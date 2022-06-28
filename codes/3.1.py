from more_itertools import sample
import numpy as np
import matplotlib.pyplot as plt

simlen = 1000000
sample = np.loadtxt('./vni.dat',dtype='double')


x = np.linspace(-5,5,40)
CF=[]
for i in range(0,40):
	CF_ind = np.nonzero(sample < x[i]) 
	CF_n = np.size(CF_ind)
	CF.append(CF_n/simlen) 

plt.plot(x.T,CF)
plt.grid()
plt.xlabel('$x$')
plt.ylabel('$F_X(x)$')
plt.savefig("../figs/vni_cdf.pdf")
plt.show()