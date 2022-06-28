# include <stdio.h>
# include <stdlib.h>
# include <time.h>
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
int main(){
    int no_of=1000000;
    
    uni_dis("uni.dat",no_of);

    return 0;
}