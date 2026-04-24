#include "train.h"
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e4+7, MOD=998244353, inf=2e18;

int n;
int A[5050], C[5050];
int goS[5050], inS[5050];
vector<int> lnk[5050], rlnk[5050];

void f(vector<int>& S, bool c){
    for(int i=0; i<S.size(); i++){
        for(int j : rlnk[S[i]]){
            goS[j]++;
            if((c^A[j]) && goS[j] && !inS[j]) S.push_back(j), inS[j]=1;
            if((c^!A[j]) && goS[j]==lnk[j].size() && !inS[j]) S.push_back(j), inS[j]=1;
        }
    }
}

vector<signed> who_wins(vector<signed> a, vector<signed> r, vector<signed> u, vector<signed> v){
	n=a.size();

	for(int i=0; i<n; i++) A[i]=a[i], C[i]=r[i];

	for(int i=0; i<u.size(); i++){
        lnk[u[i]].push_back(v[i]);
        rlnk[v[i]].push_back(u[i]);
	}

	for(int T=0; T<n; T++){
        vector<int> S;
        for(int i=0; i<n; i++) goS[i]=inS[i]=0;
        for(int i=0; i<n; i++) if(C[i]) S.push_back(i), inS[i]=1;
        f(S, 0); S.clear();

        S.clear();
        for(int i=0; i<n; i++) if(!inS[i]) S.push_back(i);
        for(int i=0; i<n; i++) goS[i]=inS[i]=0;
        for(int i : S) inS[i]=1;
        f(S, 1);

        for(int i : S) C[i]=0;
	}

	vector<signed> ret(n);
	for(int i=0; i<n; i++) ret[i]=!inS[i];

	return ret;
}
