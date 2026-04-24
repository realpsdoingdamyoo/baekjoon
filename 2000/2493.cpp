#include <bits/stdc++.h>    
using namespace std;    
typedef long long ll;

ll n, s[500001], v[500001], ans[500001], sz=0, p=0, a;

int main() {
	cin >> n;
	for(int i=n-1; i>=0; i--) cin >> s[i];
	for(int i=0; i<n; i++){
		v[sz]=i;
		while(sz>0 && s[v[sz]]>s[v[sz-1]]){
			ans[v[sz-1]]=v[sz];
			v[sz-1]=v[sz]; 
			v[sz--]=0;
		}
		sz++;
	}
	for(int i=n-1; i>=0; i--) cout << (ans[i]?n-ans[i]:0) << " ";
    return 0;
}
