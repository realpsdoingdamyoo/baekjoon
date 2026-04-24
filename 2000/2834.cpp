/**********************
** coded by rladbeka **
**********************/

#include <stdio.h>
#include <string.h>
#define ll long long int
int main() {
	ll n, box[1001], boxx[1001], ns[1001]={}, nscnt=0;
	ll fcn[1000]={}, fcncnt=0, f=0;
	scanf("%lld", &n);
	for(ll i=1; i<=n; i++) scanf("%lld", &boxx[i]);
	
	
	ll x=0;
	for(ll i=1; i<=n; i++) if(boxx[i]!=i) x++;
	if(x==0){
		printf("0");
		return 0;
	}
	
	for(ll i=1; i<=n; i++) box[i]=boxx[i];
	for(ll i=1; i<=n; i++){
		if(i!=box[i]){
			ll ii=i;
			while(1){
				f++;
				ll t=box[ii];
				box[ii]=ii;
				ii=t;
				if(ii==i) break;
			}
			break;
		}
	}
	x=0;
	for(ll i=1; i<=n; i++) if(box[i]!=i) x++;
	if(x==0){
		printf("1\n%lld: ", f);
		for(ll i=1; i<=n; i++) box[i]=boxx[i];
		for(ll i=1; i<=n; i++){
			if(i!=box[i]){
				ll ii=i;
				while(1){
					printf("%lld ", ii);
					ll t=box[ii];
					box[ii]=ii;
					ii=t;
					if(ii==i) break;
				}
				break;
			}
		}
		return 0;
	}
	
	printf("2\n");
	for(ll i=1; i<=n; i++) box[i]=boxx[i];
	for(ll i=1; i<=n; i++){
		if(i!=box[i]){
			ll ii=i;
			while(1){
				ll t=box[ii];
				box[ii]=ii;
				ii=t;
				if(ii==i) break;
			}
			fcn[fcncnt++]=i;
		}
	}
	
	
	for(ll i=1; i<=n; i++) box[i]=boxx[i];
	ll k=box[fcn[fcncnt-1]];
	printf("%lld: ", fcncnt);
	for(ll i=0; i<fcncnt; i++) {
		printf("%lld ", fcn[i]);
	}
	for(ll i=fcncnt-2; i>=0; i--) {
		box[fcn[i+1]]=box[fcn[i]];
	}
	box[fcn[0]]=k;
	
	x=0;
	ll fi=0;
	for(ll i=1; i<=n; i++) if(box[i]!=i) x++;
	for(ll i=1; i<=n; i++) if(box[i]!=i) {fi=i; break;}
	printf("\n%lld: ", x);
	ll ii=fi;
	while(n){
		printf("%lld ", box[ii]);
		ll t=box[ii];
		box[ii]=ii;
		ii=t;
		if(ii==fi) break;
	}
	
	return 0;
}
