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


int bio(){
    int n=rand()%2 ;
    if(n==1){
        return 1;
    }
    else{
        return -1;
    }
}
void equi_dis(char*p ,int N){
int i;
FILE *fp;
srand(time(NULL));
fp = fopen(p,"w");
//Generate numbers
int n;
for (i = 0; i < N; i++)
{
    n=bio();
fprintf(fp,"%d\n",n);
}
fclose(fp);

}


void mix_dis(char*p, int N){
    int i;
FILE *fp;
srand(time(NULL));
fp = fopen(p,"w");
for (i = 0; i < N; i++)
{
    int n=bio();
    double temp=0;
    for(int j=0;j<12;j++){
        temp+=(double)rand()/RAND_MAX;
    }
    temp=temp-6;
fprintf(fp,"%lf\n",temp+5*n);
temp=0;
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

void gau_to_other(char*p ,int N){
    int i;
FILE *fp;
srand(time(NULL));
fp = fopen(p,"w");
for (i = 0; i < N; i++)
{
    double X1=0;
    for(int j=0;j<12;j++){
        X1+=(double)rand()/RAND_MAX;
    }
    X1=X1-6;
double X2=0;
    for(int j=0;j<12;j++){
        X2+=(double)rand()/RAND_MAX;
    }
    X2=X2-6;
fprintf(fp,"%lf\n",X1*X1+X2*X2);
X1=0;
X2=0;
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
    double U1,U2;
FILE *fp,*fp1,*fp2;
srand(time(NULL));
fp = fopen(p,"w");
uni_dis("uni1.dat",N);
uni_dis("uni2.dat",N);
fp1=fopen("uni1.dat","r");
fp2=fopen("uni2.dat","r");

while(fscanf(fp1,"%lf",&U1)!=-1){
    fscanf(fp2,"%lf",&U2);
    fprintf(fp,"%lf\n",U1+U2);
}
fclose(fp);
fclose(fp1);
fclose(fp2);		
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
