#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, q, X=500, Y;
int v[404040];

struct bucket{
    int s; int e;
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> qry;

    int Push(int x){
        qry.push(x);
        pq.push(x);
        int y=pq.top(); pq.pop();
        return y;
    }

    void lazy(){
        for(int i=s; i<=e; i++){
            qry.push(v[i]);
            v[i]=qry.top();
            qry.pop();
        }
        qry=priority_queue<int, vector<int>, greater<int>>();
    }
    int st(int p, int x){
        lazy();
        pq=priority_queue<int>();
        for(int i=p; i<=e; i++) if(v[i]>x) swap(v[i], x);
        for(int i=s; i<=e; i++) pq.push(v[i]);
        return x;
    }
    int en(int p, int x){
        lazy();
        pq=priority_queue<int>();
        for(int i=s; i<=p; i++) if(v[i]>x) swap(v[i], x);
        for(int i=s; i<=e; i++) pq.push(v[i]);
        return x;
    }
    int in(int ps, int pe, int x){
        lazy();
        pq=priority_queue<int>();
        for(int i=ps; i<=pe; i++) if(v[i]>x) swap(v[i], x);
        for(int i=s; i<=e; i++) pq.push(v[i]);
        return x;
    }
} buc[1000];

signed main(){
    fastio;

    cin >> n >> q; Y=(n-1)/X+1;
    for(int i=0; i<n; i++) cin >> v[i];
    for(int i=0; i<Y; i++){
        buc[i].s=i*X;
        buc[i].e=min((i+1)*X-1, n-1);
    }
    for(int i=0; i<n; i++) buc[i/X].pq.push(v[i]);

    while(q--){
        int s, e, x; cin >> s >> e >> x; s--; e--;
        int S=s/X, E=e/X;
        if(S==E && s<=e) cout << buc[S].in(s, e, x) << "\n";
        else{
            x=buc[S].st(s, x);
            for(int i=(S+1)%Y;; i=(i+1)%Y){
                if(i==E) break;
                x=buc[i].Push(x);
            }
            x=buc[E].en(e, x);
            cout << x << "\n";
        }
    }

    return 0;
}
