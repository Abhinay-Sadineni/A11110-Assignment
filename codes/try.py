import mpmath as mp
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-5,5,40)

def f(x):
    return (1+mp.erf(x/mp.sqrt(2)))/2
cdf = np.vectorize(f)

plt.plot(x.T,cdf(x))
plt.show()