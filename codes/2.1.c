#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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


int main(){
    int no_of=1000000;
    
    gau_dis("gau.dat",no_of);

    return 0;
}