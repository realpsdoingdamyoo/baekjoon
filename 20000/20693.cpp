#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int a, c, t;
vector<int> A[50505], C[50505], T[50505];

int n;
vector<int> lnk[202020];
map<array<int, 2>, vector<int>> ac, ct, ta;

int vis[202020];

vector<int> pnt;
vector<array<int, 2>> edge;

int bf(){
    int ret=0;
    map<int, int> mp;
    for(int i=0; i<pnt.size(); i++) mp[pnt[i]]=i;
    for(int i=1; i<(1<<pnt.size()); i++){
        int c=0;
        for(array<int, 2> l : edge){
            if((i&(1<<mp[l[0]])) && (i&(1<<mp[l[1]]))) c=1;
        }
        if(c) continue;
        int r=0;
        for(int j=0; j<pnt.size(); j++) r+=!!(i&(1<<j));
        ret=max(ret, r);
    }
    return ret;
}

array<int, 2> dfs(int p){
    pnt.push_back(p);
    vis[p]=1;
    array<int, 2> ret={1, 0};
    for(int i : lnk[p]){
        if(!vis[i]){
            array<int, 2> pl=dfs(i);
            ret[1]+=pl[0]; ret[0]+=pl[1];
        }
        if(p<i) edge.push_back({p, i});
    }
    return ret;
}

signed main(){
    fastio;

    cin >> a >> c >> t;
    for(int i=1; i<=a; i++){
        int s; cin >> s;
        while(s--){int b; cin >> b; A[i].push_back(b);}
    }
    for(int i=1; i<=a; i++){
        int s; cin >> s;
        while(s--){int b; cin >> b; T[b].push_back(i);}
    }
    for(int i=1; i<=c; i++){
        int s; cin >> s;
        while(s--){int b; cin >> b; C[i].push_back(b);}
    }

    for(int i=1; i<=a; i++){
        for(int j : A[i]) for(int k : C[j]) for(int l : T[k]){
            if(l!=i) continue;
            n++;
            ac[{i, j}].push_back({n});
            ct[{j, k}].push_back({n});
            ta[{k, i}].push_back({n});
        }
    }

    for(pair<array<int, 2>, vector<int>> p : ac)
        for(int i : p.second) for(int j : p.second) if(i<j)
            lnk[i].push_back(j), lnk[j].push_back(i);

    for(pair<array<int, 2>, vector<int>> p : ct)
        for(int i : p.second) for(int j : p.second) if(i<j)
            lnk[i].push_back(j), lnk[j].push_back(i);

    for(pair<array<int, 2>, vector<int>> p : ta)
        for(int i : p.second) for(int j : p.second) if(i<j)
            lnk[i].push_back(j), lnk[j].push_back(i);

    int ans=0;
    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        pnt.clear(); edge.clear();
        array<int, 2> ret=dfs(i);

        if(ret[0]+ret[1]<=8) ans+=bf();
        else if(pnt.size()>edge.size()) ans+=max(ret[0], ret[1]);
        else ans+=pnt.size()/2;

    }

    cout << ans;

	return 0;
}
