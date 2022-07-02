#include "functions.h"
int main(){
double a=mean("uni.dat");
double b=variance("uni.dat",a);
    printf("mean= %lf\n",a);
    printf("variance= %lf\n",b);
}