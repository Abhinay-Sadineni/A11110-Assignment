#include <stdio.h>
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
    return sq/N;
}

int main(){
double a=mean("gau.dat");
double b=variance("gau.dat",a);
    printf("mean= %lf\n",a);
    printf("variance= %lf\n",b);
}