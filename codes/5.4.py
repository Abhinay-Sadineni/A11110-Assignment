import numpy as np

N = np.loadtxt('gau.dat', dtype='double')
X = np.loadtxt('equi.dat', dtype='double')
Y = 5*X + N
e0 = np.count_nonzero((Y < 0) & (X > 0))
n0 = np.count_nonzero(X > 0)
e1 = np.count_nonzero((Y > 0) & (X < 0))
n1 = np.count_nonzero(X < 0)
print("X = 1: ", e0)
print("X = -1: ", e1)