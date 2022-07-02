;
#randvar = np.random.normal(0,1,simlen)
#randvar = np.loadtxt('uni.dat',dtype='double')
randvar = np.loadtxt('tri.dat',dtype='double')

for i in range(0,maxrange):
	err_ind = np.nonzero(randvar < x[i]) #checking probability condition
	err_n = np.size(err_ind) #computing the probability
	err.append(err_n/simlen) #storing the probability values in a list

	
for i in range(0,maxrange-1):
	test = (err[i+1]-err[i])/(x[i+1]-x[i])
	pdf.append(test) #storing the pdf values in a list

def tri_pdf(x):
    if(0<x<1):
        return x
    elif(1<x<2):
        return 2-x
    else:
      return 0
	
vec_tri_pdf = np.vectorize(tri_pdf,otypes=["double"])

plt.plot(x[0:(maxrange-1)].T,pdf,'o')
plt.plot(x,vec_tri_pdf(x))#plotting the CDF
plt.grid() #creating the grid
plt.xlabel('$x_i$')
plt.ylabel('$p_X(x_i)$')
plt.legend(["Numerical","Theory"])

#if using termux
#plt.savefig('../figs/uni_pdf.pdf')
#plt.savefig('../figs/uni_pdf.eps')
#subprocess.run(shlex.split("termux-open ../figs/uni_pdf.pdf"))
#if using termux
plt.savefig('../figs/gauss_pdf_verify.pdf')
plt.savefig('../figs/gauss_pdf_verify.eps')
plt.show()
#else
#plt.show() #opening the plot window

