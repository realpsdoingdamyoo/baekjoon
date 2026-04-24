#include <stdio.h>
#define pn printf("\n");

int n, mo[10001]={}, mlen[10001]={};

int mlenfind(int b){
	if(mo[b]==0){mlen[b]=0; return 0;}
	if(mlen[b]!=0) return mlen[b];
	return mlenfind(mo[b])+1;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		for(int i=0; i<10001; i++){mo[i]=0; mlen[i]=0;}
		int a, b;
		scanf("%d", &n);
		for(int i=1; i<n; i++){
			scanf("%d %d", &a, &b);
			mo[b]=a;
		}
		for(int i=1; i<=n; i++) mlen[i]=mlenfind(i);
		scanf("%d %d", &a, &b);
		int x=mlen[a]-mlen[b];
		if(x<0) for(int i=0; i<-x; i++) b=mo[b];
		else for(int i=0; i<x; i++) a=mo[a];
		while(a!=b){
			a=mo[a]; b=mo[b];
		}
		printf("%d\n", a);
	}
    return 0;
}
