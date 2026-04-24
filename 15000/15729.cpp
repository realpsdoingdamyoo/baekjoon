#include<stdio.h>
int n,p,c,k;main(){scanf("%d",&n);while(n--){scanf("%d",&k);p|=4*k;if(p&1){c++;p^=7;}p/=2;}c+=(p==1)+!!p;printf("%d",c);}
