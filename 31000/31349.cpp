#include<stdio.h>
long long K[1<<18],n,c,j,A=1,i=1,I,k,M=1e9+7;main(){scanf("%d%d",&n,&c);for(;i<n;i++)scanf("%d",K+i);for(;I<n;I++){k=0;j=I;if(!K[I]){while(j)j=K[j-1],k+=!K[j];A=A*(c-k)%M;}}printf("%d",A);}
