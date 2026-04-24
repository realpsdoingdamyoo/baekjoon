#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, m, p;
vector<array<int, 2>> v;
int cn[303030];
vector<array<int, 2>> ses;

const int X=19;
int seg[1<<X+1];

void update(int p, int x){
    p+=1<<X; seg[p]=x; p>>=1;
    while(p) seg[p]=min(seg[p<<1], seg[p<<1|1]), p>>=1;
}
int Min(int s, int e){
    s+=1<<X; e+=1<<X; int ret=inf;
    while(s<=e){
        if(s&1) ret=min(ret, seg[s]);
        if(~e&1) ret=min(ret, seg[e]);
        ++s>>=1; --e>>=1;
    } return ret;
}

int sp(int l){
    int S=0, E=ses.size()-1;
    while(S<=E){
        int M=S+E>>1;
        if(l<=ses[M][0]) E=M-1; else S=M+1;
    }
    return S;
}

int ep(int r){
    int S=0, E=ses.size()-1;
    while(S<=E){
        int M=S+E>>1;
        if(ses[M][1]<=r) S=M+1; else E=M-1;
    }
    return E;
}

int qry(int l, int r){
    int s=sp(l), e=ep(r);
    if(s<=e) return 0;

    int ret=inf;
    if(0<=s && s<ses.size()) ret=min(ret, ses[s][1]-r);
    if(0<=e && e<ses.size()) ret=min(ret, l-ses[e][0]);

    ret=min(ret, Min(e+1, s-1)-(r-l));
    return ret;
}

signed main(){
	fastio;

	cin >> n >> m >> p;
	for(int i=0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        v.push_back({c, b});
	}
	sort(v.begin(), v.end());

	int s=0, e=-1, sm=0;
	for(s=0; s<m; s++){
        while(sm<n-1){
            if(e==m-1){e++; break;}
            e++;
            sm-=!!cn[v[e][1]];
            cn[v[e][1]]++;
            sm+=!!cn[v[e][1]];
        }
        if(e==m) break;
        ses.push_back({v[s][0], v[e][0]});
        sm-=!!cn[v[s][1]];
        cn[v[s][1]]--;
        sm+=!!cn[v[s][1]];
	}

	for(int i=0; i<ses.size(); i++)
        update(i, ses[i][1]-ses[i][0]);

    int q; cin >> q;
    while(q--){
        int a, b, c; cin >> a >> b >> c;
        if(qry(a, b)<=c) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
