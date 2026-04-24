#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int iiii=0;
ll n, m, k;

ll q(ll x){
	if(iiii) return n+1-x;
	return x;
}

int main()
{
    scanf("%lld %lld %lld", &n, &m, &k);
    if(n<m+k-1 || n>m*k) {printf("-1"); return 0;}
    for(iiii=0; iiii<2; iiii++){
		ll c=1, mm=0, p=1;
	    if(n!=m*k){
	    	mm=(n-m)/(k-1);
	    	for(int i=mm+1; i<m; i++) printf("%d ", q(i-mm+0*(c++)+0*(p++)));
	    	for(int i=n-m+mm+1; i>(n-m)/(k-1)*k; i--) printf("%d ", q(i-(n-m)/(k-1)*k+c-1+0*(p++)));
	        for(int i=0; i<(n-m)/(k-1); i++){
	            for(int j=0; j<k; j++){
	                printf("%d ", q(i*k+k-j+p-1));
	                c++;
	            }
	        }
	    }
	    else{
	        for(int j=0; j<m; j++){
	            for(int i=k; i>=1; i--) printf("%d ", q(j*k+i));
	        }
	    }
	    cout << '\n';
	    ll t=m; m=k; k=t;
	}
    return 0;
}
