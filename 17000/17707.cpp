#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int n, m, cn;
int v[202020], u[202020], x[202020];
int up[202020], ans[202020];

void query(vector<array<int, 3>> qry, int t){
    sort(u+1, u+n+1);
    vector<array<int, 2>> ups;

    for(array<int, 3> i : qry){
        if(i[0]==1){
            int ret=n-(lower_bound(u+1, u+n+1, i[1])-u)+1;
            for(array<int, 2> j : ups){
                ret+=-(j[0]>=i[1])+(j[1]>=i[1]);
            }
            ans[i[2]]+=t?ret:-ret;
        }
        else{
            ups.push_back({v[i[1]], i[2]});
            v[i[1]]=i[2];
        }
    }
    for(int i=1; i<=n; i++) u[i]=v[i];
}

signed main(){
    fastio;

    cin >> n >> m;
    for(int i=1; i<=n; i++){cin >> v[i]; u[i]=x[i]=v[i];}

    vector<array<int, 3>> Q={{0,0,0}}, qry;
    for(int i=1; i<=m; i++){
        int a; cin >> a;
        if(a==1){int b; cin >> b; Q.push_back({a, b, ++cn});}
        else{int b, c; cin >> b >> c; Q.push_back({a, b, c});}
    }

    for(int i=1; i<=m; i++){
        qry.push_back(Q[i]);
        if(i%1200==0 || i==m){query(qry, 1); qry.clear();}
    }

    for(int i=1; i<=n; i++) v[i]=u[i]=min(x[i], x[i-1]);
    for(int i=1; i<=m; i++){
        if(Q[i][0]==2){
            int p=Q[i][1]; x[p]=Q[i][2];
            qry.push_back({2, p, min(x[p], x[p-1])});
            qry.push_back({2, p+1, min(x[p+1], x[p])});
        }
        else qry.push_back(Q[i]);
        if(i%1200==0 || i==m){query(qry, 0); qry.clear();}
    }

    for(int i=1; i<=cn; i++) cout << ans[i] << "\n";

	return 0;
}
