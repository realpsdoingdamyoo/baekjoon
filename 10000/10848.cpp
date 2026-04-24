#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18, bnd=1e10;

int k, m, n, ans;
vector<array<int, 2>> v;

bool cmp(array<int, 2>& a, array<int, 2>& b){return a[0]+a[1]<b[0]+b[1];}

struct slope{
    multiset<int> L, R;
    int Ls=0, Rs=0;

    void Sort(){
        while(L.size()!=R.size()){
            if(L.size()<R.size()){int Rt=*R.begin(); L.insert(Rt); Ls+=Rt; Rs-=Rt; R.erase(R.find(Rt));}
            else{int Lt=*prev(L.end()); R.insert(Lt); Rs+=Lt; Ls-=Lt; L.erase(L.find(Lt));}
        }

        if(L.size()==0 || R.size()==0) return;
        while(*prev(L.end())>*R.begin()){
            int Lt=*prev(L.end()); Ls-=Lt; L.erase(L.find(Lt));
            int Rt=*R.begin(); Rs-=Rt; R.erase(R.find(Rt));
            L.insert(Rt); R.insert(Lt); Ls+=Rt; Rs+=Lt;
        }
    }

    void Push(int a, int b){
        L.insert(a); R.insert(b); Ls+=a; Rs+=b;
        Sort();
    }

    void Erase(int a, int b){
        if(L.find(a)!=L.end()){L.erase(L.find(a)); Ls-=a;}
        else{R.erase(R.find(a)); Rs-=a;}
        if(L.find(b)!=L.end()){L.erase(L.find(b)); Ls-=b;}
        else{R.erase(R.find(b)); Rs-=b;}
        Sort();
    }

    int Diff(){
        return Rs-Ls;
    }
};

signed main(){
    fastio;

    cin >> k >> m;
    for(int i=0; i<m; i++){
        string A, B; int a, b;
        cin >> A >> a >> B >> b;
        if(A==B) ans+=abs(a-b);
        else ans++, v.push_back({min(a, b), max(a, b)}), n++;
    }

    if(k==1){
        vector<int> u;
        for(array<int, 2> i : v) u.push_back(i[0]), u.push_back(i[1]);
        sort(u.begin(), u.end());
        for(int i=0; i<n*2; i++) ans+=abs(u[n]-u[i]);
        cout << ans; return 0;
    }

    sort(v.begin(), v.end(), cmp);

    slope X, Y;
    for(array<int, 2> i : v) Y.Push(i[0], i[1]);

    int ret=X.Diff()+Y.Diff();
    for(array<int, 2> i : v){
        X.Push(i[0], i[1]);
        Y.Erase(i[0], i[1]);
        ret=min(ret, X.Diff()+Y.Diff());
    }

    cout << ans+ret;

    return 0;
}
