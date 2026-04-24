#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

vi segtree(5000000);
int sz=1, szsz=0;

int rtn(int a, int b){
    return min(a, b); //
}

void q1(int node, int val){
    segtree[node]=val; node/=2;
    while(node){
        segtree[node]=rtn(segtree[2*node], segtree[2*node+1]);
        node/=2;
    }
}

int q2(int s, int e, int t){ //at first t=sz
    if(s==e) return segtree[s];
    int result; //
    while(t>=1){
        if((s&t)==(e&t)) t/=2;
        else{
            if(e-s==t*2-1) return segtree[s/t/2];
            else return rtn(q2(s, e/t*t-1, t), q2(e/t*t, e, t));
        }
    }
    return segtree[s];
}

int main() {
    fastio;
    int n; cin >> n;
    int ssz; while(sz<n) {sz*=2; szsz++;} ssz=sz/2;
    for(int i=sz; i<sz+n; i++) cin >> segtree[i];
    for(int i=sz+n; i<2*sz; i++) segtree[i]=1000000001; //
    while(ssz){
        for(int i=ssz; i<2*ssz; i++){
            segtree[i]=rtn(segtree[2*i], segtree[2*i+1]);
        }
        ssz/=2;
    }
    int q; cin >> q;
    for(int i=0; i<q; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a==1) q1(sz+b-1, c);
        if(a==2) cout << q2(sz+b-1, sz+c-1, sz) << "\n";
    }
    return 0;
}
