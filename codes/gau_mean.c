#include "functions.h"

int main(){
double a=mean("gau.dat");
double b=variance("gau.dat",a);
    printf("mean= %lf\n",a);
    printf("variance= %lf\n",b);
}