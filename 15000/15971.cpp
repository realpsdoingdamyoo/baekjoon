#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

vector<array<int, 2>> lin_k[100001];
vi dfsd, vsd(100003);
int n, s, e;

bool dfs(int f){
    vsd[f]=1;
    if(f==e) return true;
    bool bb=false;
    for(int i=0; i<lin_k[f].size(); i++){
        if(vsd[lin_k[f][i][0]]) continue;
        dfsd.push_back(lin_k[f][i][1]);
        bb=bb || dfs(lin_k[f][i][0]);
        if(bb) break;
        if(!bb) dfsd.pop_back();
    }
    return bb;
}

int main(){
    cin >> n >> s >> e;
    for(int i=0; i<n-1; i++){
        int a, b, c; cin >> a >> b >> c;
        lin_k[a].push_back({b, c});
        lin_k[b].push_back({a, c});
    }
    if(s==e) cout << 0;
    else{
        bool bbb=dfs(s);
        sort(dfsd.begin(), dfsd.end());
        int ans=0;
        for(int i=0; i<dfsd.size()-1; i++) ans+=dfsd[i];
        cout << ans;
    }
    return 0;
}
