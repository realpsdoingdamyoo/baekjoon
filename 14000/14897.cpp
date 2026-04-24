#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18, bnd=1e10;

const int X=20;
struct PST{
    vector<array<int, 2>> seg[1<<X+1];
    void init(){
        for(int i=1; i<1<<X+1; i++) seg[i].push_back({-1, 0});
    }

    int val(int p, int t){
        return (*prev(upper_bound(seg[p].begin(), seg[p].end(), array<int, 2>{t, inf})))[1];
    }

    void update(int p, int x, int t){
        p+=1<<X;
        while(p){
            seg[p].push_back({t, seg[p].back()[1]+x});
            p>>=1;
        }
    }

    int query(int s, int e, int t){
        int ret=0;
        s+=1<<X; e+=1<<X;
        while(s<=e){
            if(s&1) ret+=val(s, t);
            if(~e&1) ret+=val(e, t);
            ++s>>=1; --e>>=1;
        }
        return ret;
    }
} pst;

int prv[1010101];

signed main(){
    fastio;

    pst.init();

    int n; cin >> n;
    map<int, int> mp;
    for(int i=1; i<=n; i++){
        int a; cin >> a;
        prv[i]=mp[a]; mp[a]=i;
    }

    for(int i=1; i<=n; i++){
        pst.update(i, 1, i*2);
        pst.update(prv[i], -1, i*2+1);
    }

    int q; cin >> q;
    for(int i=0; i<q; i++){
        int a, b; cin >> a >> b;
        cout << pst.query(a, b, b*2+1) << "\n";
    }

    return 0;
}
