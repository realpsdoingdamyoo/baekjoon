#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

const int X=404040;
int n;
vector<int> u;
vector<array<int, 2>> v;
int sp[X][18];
set<array<int, 2>> con;

int sparse(int s, int e){
    int x=s, ret=0;
    for(int i=17; i>=0; i--){
        if(sp[x][i]>e) continue;
        x=sp[x][i]+1;
        ret+=1<<i;
    }
    return ret;
}

signed main() {
    fastio;

    cin >> n;
    v.resize(n);
    for(array<int, 2>& i : v){
        cin >> i[0] >> i[1];
        u.push_back(i[0]);
        u.push_back(i[1]);
    }

    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    for(array<int, 2>& i : v) for(int& j : i)
        j=lower_bound(u.begin(), u.end(), j)-u.begin();

    for(int i=0; i<404040; i++) for(int j=0; j<18; j++) sp[i][j]=inf;

    for(array<int, 2> i : v) sp[i[0]][0]=min(sp[i[0]][0], i[1]);
    for(int i=X-2; i>=0; i--) sp[i][0]=min(sp[i][0], sp[i+1][0]);

    for(int j=1; j<18; j++) for(int i=0; i<X; i++){
        if(sp[i][j-1]==inf) continue;
        sp[i][j]=sp[sp[i][j-1]+1][j-1];
    }

    con.insert({0, X-1});
    vector<int> ans;

    for(int j=0; j<n; j++){
        array<int, 2> i=v[j];
        array<int, 2> a=*prev(con.upper_bound({i[0], inf}));
        if(i[0]<a[0] || a[1]<i[1]) continue;

        int L=sparse(a[0], i[0]-1);
        int R=sparse(i[1]+1, a[1]);
        int A=sparse(a[0], a[1]);
        if(L+R+1==A){
            ans.push_back(j);
            con.insert({a[0], i[0]-1});
            con.insert({i[1]+1, a[1]});
            con.erase(con.find({a[0], a[1]}));
        }
    }

    cout << ans.size() << "\n";
    for(int i : ans) cout << i+1 << " ";
    cout << "\n";

    return 0;
}
