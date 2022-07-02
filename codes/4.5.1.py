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
	
	
def f(x):
    if(0<=x<=1):
      return x*x/2
    elif(1<x<=2):
        return 1-(x-2)**2/2
    elif(x>2):
        return 1
    else:
        return 0
    
cdf = np.vectorize(f,otypes=["double"])


plt.plot(x.T,cdf(x))
plt.plot(x[0:40].T,CF,"o")
plt.grid()
plt.xlabel('$x$')
plt.ylabel('$F_X(x)$')
plt.legend(["Theory","Numerical"])
plt.savefig("../figs/tri_cdf_verify.pdf")
plt.savefig("../figs/tri_cdf_verify.eps")
plt.show()
