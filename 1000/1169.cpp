#include <stdio.h>
#define ll long long int


ll minbi(ll b1, ll s1, ll s2){
	return b1+2*(s1>s2?s2:s1);
}

int main()
{
	ll n, sq[100]={}, bi[100]={}, cansee[100]={};
	scanf("%lld", &n);
	for(ll i=0; i<n; i++) scanf("%lld", &sq[i]);
	bi[0]=sq[0];
	for(ll i=1; i<n; i++){
		ll max=0;
		for(ll j=0; j<i; j++){
			ll min=minbi(bi[j], sq[j], sq[i]);
			if(max<min) max=min;
		}
		bi[i]=max;
	}
	for(ll i=0; i<n; i++){
		ll leftcover=0, rightcover=10000000;
		for(ll j=0; j<i; j++){
			if(sq[i]<sq[j]){
				ll lc=bi[j]+sq[j];
				leftcover=leftcover>lc?leftcover:lc;
			}
		}
		for(ll j=i+1; j<n; j++){
			if(sq[i]<sq[j]){
				ll rc=bi[j]-sq[j];
				rightcover=rightcover<rc?rightcover:rc;
			}
		}
		if(leftcover<rightcover && leftcover<bi[i]+sq[i] && rightcover>bi[i]-sq[i]) {
			printf("%lld ", i+1);
		}
	}
    return 0;
}
