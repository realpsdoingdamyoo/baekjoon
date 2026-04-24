#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v[50001];
int n, mo[50001]={}, mlen[50001]={}, vsd[50001];

int mlenfind(int b){
	if(b==1){mlen[b]=0; return 0;}
	if(mlen[b]!=0) return mlen[b];
	return mlenfind(mo[b])+1;
}

void dfs(int np){
	for(int i=0; i<v[np].size(); i++){
		if(!vsd[v[np][i]]){
			vsd[v[np][i]]=1;
			mo[v[np][i]]=np;
			dfs(v[np][i]);
		}
	}
}

int main() {
	int n; cin >> n;
    for(int i=1; i<n; i++){
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
    dfs(1);
    for(int i=1; i<=n; i++) mlen[i]=mlenfind(i);
    int a, b, t; cin >> t;
    while(t--){
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
