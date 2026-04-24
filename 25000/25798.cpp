#include <bits/stdc++.h>
int A,B,C,D,m,n,k,t,o,e;int main(){scanf("%d",&t);while(t--){scanf("%d%d%d",&m,&n,&k);o=e=A=B=C=D=0;while(k--){int a,b; scanf("%d%d",&a,&b); a--; b--;if((a+b)%2) o++;else e++;if(a+b<2)A+=a*2+b*2-1;if(a-b>m-3)B+=(a-b==m-2)*2-1;if(b-a>n-3)C+=(b-a==n-2)*2-1;if(a+b>m+n-4)D+=(a+b==m+n-3)*2-1;}printf("%d\n",m*n/2-std::max(o+(B==2)+(C==2), e+(A==2)+(D==2)));}}
