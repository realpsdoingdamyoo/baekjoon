#include <bits/stdc++.h>
#define f double
#define q int
#define r return
#define D for(q i=0;i<3;i++)
f S(f a){r a*a;}q C(f a,f b){r fabs(a-b)<0.0001;}f G(f a,f b){if(C(a,0)||C(b,0))r a+b;r C(a,b)?a:G(a-b*q(a/b),b-a*q(b/a));}main(){while(1){char e[20];f x[6],y[6],d[6],c[3],A[3];scanf("%s",e);if(e[0]=='E')r 0;else sscanf(e,"%lf",&x[0]);scanf("%lf%lf%lf%lf%lf",&y[0],&x[1],&y[1],&x[2],&y[2]);D{x[i+3]=x[i];y[i+3]=y[i];}D d[i+3]=d[i]=sqrt(S(x[i]-x[i+1])+S(y[i]-y[i+1]));D c[i]=(S(d[i+1])+S(d[i+2])-S(d[i]))/(d[i+1]*d[i+2]*2);D A[i]=acos(c[i]);printf("%.0lf\n",acos(-1)/G(G(A[0],A[1]),A[2]));}}
