#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, d, t;
int v[2020202];
vector<array<int, 2>> tr;
vector<int> lnk[2020202];
priority_queue<int> pq[2020202];

void dfs(int p){
    for(int i : lnk[p]){
        dfs(i);
        if(pq[i].size()>pq[p].size()) swap(pq[i], pq[p]);
        while(pq[i].size()){
            pq[p].push(pq[i].top());
            pq[i].pop();
        }
    }
    if(lnk[p].size()==0) pq[p].push(0);
    if(p){int x=pq[p].top()+1; pq[p].pop(); pq[p].push(x);}
}

bool cmp(array<int, 2> a, array<int, 2> b){
    return array<int, 2>{a[0], -a[1]}<array<int, 2>{b[0], -b[1]};
}

signed main(){
    fastio;

    cin >> n >> d >> t;
    for(int i=1; i<=n; i++) cin >> v[i];
    vector<int> st;
    for(int i=1; i<=n; i++){
        if(v[i]>t){
            while(st.size() && v[st.back()]-st.back()>=t+1-i) st.pop_back();
            if(st.size()) tr.push_back({st.back()+1, i});
            else tr.push_back({1, n});
        }
        else{
            while(st.size() && v[st.back()]-st.back()>=v[i]-i) st.pop_back();
            st.push_back(i);
        }
    }
    tr.push_back({1, n});
    sort(tr.begin(), tr.end(), cmp);

    vector<array<int, 3>> s={{1, n, 0}};
    for(int i=1; i<tr.size(); i++){
        array<int, 3> p={tr[i][0], tr[i][1], i};
        while(s.back()[1]<p[0]) s.pop_back();
        lnk[s.back()[2]].push_back(i);
        s.push_back(p);
    }

    dfs(0);

    int ans=0;
    while(pq[0].size() && d){
        ans+=pq[0].top(); pq[0].pop(); d--;
    }
    cout << n-ans;


    return 0;
}
