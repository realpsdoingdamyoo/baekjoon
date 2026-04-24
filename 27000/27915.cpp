#include <stdio.h>

int n, mother[100000]={}, mlen[100000]={0, 0,}, hj[2]={1, 0};

int main() {
	scanf("%d", &n);
	for(int i=2; i<=n; i++){
		scanf("%d", &mother[i]);
		if(i) mlen[i]=mlen[mother[i]]+1;
		hj[mlen[i]%2]++;
	}
	printf("%d", hj[0]>hj[1]?hj[0]:hj[1]);
    return 0;
}
