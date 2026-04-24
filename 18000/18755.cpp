#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647202020;

struct node{
    priority_queue<int, vector<int>, greater<int>> up;
    list<int> mid;
    priority_queue<int> dn;
    int uu=0, du=0;
} fret;

int n, k;
vector<node> v;
vector<vector<array<int, 2>>> lnk;

void Merge(node& a, node& b){
    int as=a.up.size()+a.dn.size()+a.mid.size();
    int bs=b.up.size()+b.dn.size()+b.mid.size();
    if(as<bs) swap(a, b);

    while(a.mid.size()){
        a.up.push(a.mid.back()-a.uu);
        a.mid.pop_back();
    }
    while(b.up.size()){
        a.up.push(b.up.top()+b.uu-a.uu);
        b.up.pop();
    }
    while(b.mid.size()){
        a.up.push(b.mid.back()-a.uu);
        b.mid.pop_back();
    }
    while(b.dn.size()){
        a.up.push(b.dn.top()+b.du-a.uu);
        b.dn.pop();
    }

    while(a.up.size()>k/2) a.dn.push(a.up.top()+a.uu-a.du), a.up.pop();
    while(a.dn.size() && a.up.top()+a.uu<a.dn.top()+a.du){
        int utd=a.up.top()+a.uu;
        int dtu=a.dn.top()+a.du;
        a.up.push(dtu-a.uu);
        a.dn.push(utd-a.du);
    }

    if(a.up.size()==k/2 && a.dn.size() && k%2){
        a.mid.push_back({a.dn.top()+a.du});
        a.dn.pop();
    }
}


void dfs(int p, int pre){
    node ret=fret;
    Merge(v[p], ret);
    for(array<int, 2> i : lnk[p]) if(i[0]!=pre){
        dfs(i[0], p);
        v[i[0]].uu+=2*i[1];
        v[i[0]].du-=2*i[1];

        Merge(v[p], v[i[0]]);
    }

}

void solve(){
    cin >> n >> k;
    v.clear(); v.resize(n);
    lnk.clear(); lnk.resize(n);

    for(int i=0; i<n-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        lnk[a-1].push_back({b-1, c});
        lnk[b-1].push_back({a-1, c});
    }

    dfs(0, -1);

    priority_queue<int> pq;
    while(v[0].up.size()) pq.push(v[0].up.top()+v[0].uu), v[0].up.pop();
    while(v[0].mid.size()) pq.push(v[0].mid.back()), v[0].mid.pop_back();
    while(v[0].dn.size()) pq.push(v[0].dn.top()+v[0].du), v[0].dn.pop();

    int ret=0;
    while(k--) ret+=pq.top(), pq.pop();
    cout << ret <<"\n";
}

signed main() {
    fastio;

    fret.up.push(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
