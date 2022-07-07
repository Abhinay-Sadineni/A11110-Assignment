from lib2to3.pytree import convert
import numpy as np
import mpmath as mp
import scipy 
import matplotlib.pyplot as plt




maxrange=50
maxlim=6.0
x = np.linspace(-maxlim,maxlim,maxrange)#points on the x axis
simlen = int(1e6) #number of samples
err = [] #declaring probability list
pdf = [] #declaring pdf list
conv=[]
h = 2*maxlim/(maxrange-1)
#randvar = np.random.normal(0,1,simlen)
#randvar = np.loadtxt('uni.dat',dtype='double')
randvar = np.loadtxt('tri.dat',dtype='double')
U1=np.loadtxt('uni1.dat',dtype='double',max_rows=100)
U2=np.loadtxt('uni2.dat',dtype='double',max_rows=100)

verify=np.convolve(U1,U2,mode='full')
for i in range(0,maxrange):
	conv_ind = np.nonzero(verify < x[i]) #checking probability condition
	conv_n = np.size(conv_ind) #computing the probability
	conv.append(conv_n/simlen) #storing the probability values in a list

	
for i in range(0,maxrange-1):
	conv_test = (conv[i+1]-conv[i])/(x[i+1]-x[i])
	pdf.append(conv_test) #storing the pdf values in a list

# randvar = np.loadtxt('tri.dat',dtype='double')
U1=np.loadtxt('uni1.dat',dtype='double',max_rows=100)
U2=np.loadtxt('uni2.dat',dtype='double',max_rows=100)
# for i in range(0,maxrange):
# 	err_ind = np.nonzero(randvar < x[i]) #checking probability condition
# 	err_n = np.size(err_ind) #computing the probability
# 	err.append(err_n/simlen) #storing the probability values in a list

	
# for i in range(0,maxrange-1):
# 	test = (err[i+1]-err[i])/(x[i+1]-x[i])
# 	pdf.append(test) #storing the pdf values in a list

# def other_pdf(x):
# 	return 
	
# vec_gauss_pdf = scipy.vectorize(gauss_pdf)

plt.plot(x[0:(maxrange-1)].T,conv_pdf)
#plt.plot(x,vec_gauss_pdf(x))#plotting the CDF
plt.grid() #creating the grid
plt.xlabel('$x_i$')
plt.ylabel('$p_X(x_i)$')
#plt.legend(["Numerical","Theory"])

#if using termux
#plt.savefig('../figs/uni_pdf.pdf')
#plt.savefig('../figs/uni_pdf.eps')
#subprocess.run(shlex.split("termux-open ../figs/uni_pdf.pdf"))
#if using termux
# plt.savefig('../figs/other_pdf.pdf')
# plt.savefig('../figs/other_pdf.eps')
plt.show()
#else
#plt.show() #opening the plot window

