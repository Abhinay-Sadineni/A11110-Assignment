#include <stdio.h>
# include <stdlib.h>
# include <time.h>
#include <math.h>
void vni_dis(char*p ,int N){
int i;
FILE *fp;
srand(time(NULL));
fp = fopen(p,"w");
//Generate numbers
for (i = 0; i < N; i++)
{
fprintf(fp,"%lf\n",-2*log(1-(double)rand()/RAND_MAX));
}
fclose(fp);
}

void gau_dis(char*p ,int N){
int i;
FILE *fp;
srand(time(NULL));
fp = fopen(p,"w");
for (i = 0; i < N; i++)
{
    double temp=0;
    for(int j=0;j<12;j++){
        temp+=(double)rand()/RAND_MAX;
    }
    temp=temp-6;
fprintf(fp,"%lf\n",temp);
temp=0;
}
fclose(fp);
}

void uni_dis(char*p ,int N){
int i;
FILE *fp;
srand(time(NULL));
fp = fopen(p,"w");
//Generate numbers
for (i = 0; i < N; i++)
{
fprintf(fp,"%lf\n",(double)rand()/RAND_MAX);
}
fclose(fp);
}
double mean(char*fi){
    FILE *fp;
    int N=0;
    double sum=0,p;
    fp=fopen(fi,"r");
    while(fscanf(fp,"%lf",&p)!=-1){
        sum=sum+p;
        N=N+1;
    }
    fclose(fp);
    return sum/N;

}

void tri_dis(char*p ,int N){
	int i;
FILE *fp;
srand(time(NULL));
fp = fopen(p,"w");
for (i = 0; i < N; i++)
{
    double temp=0;
    for(int j=0;j<2;j++){
        temp+=(double)rand()/RAND_MAX;
    }
fprintf(fp,"%lf\n",temp);
temp=0;
}
fclose(fp);
		

}
double variance(char *fi, double m){
FILE *fp;
    int N=0;
    double p,sq=0;
     fp=fopen(fi,"r");
    while(fscanf(fp,"%lf",&p)!=-1){
        sq=sq+(p-m)*(p-m);
        N=N+1;
    }
    fclose(fp);
    return (sq)/N;
}
