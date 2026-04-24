#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define pb push_back
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll inf=2147483647, linf=9223372036854775807;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

ll n, m;
vi a, b;

ll mx(){
    ll ln[2]={}, s=0, sz[2]={n, m};
    priority_queue<pii> pq;
    forf(i, 0, n) pq.push({-a[i], 1});
    forf(i, 0, m) pq.push({-b[i], 0});

    while(pq.size()){
        ln[pq.top()[1]]++;
        s+=pq.top()[0]*(sz[pq.top()[1]]-ln[pq.top()[1]^1]);
        pq.pop();
    }
    return -s;

}

ll mn(){
    ll s=0;
    priority_queue<ll> pq1, pq2;
    forf(i, 0, n) pq1.push(a[i]);
    forf(i, 0, m) pq2.push(b[i]);
    while(pq1.size() || pq2.size()){
        if(pq1.empty()){
            s+=pq2.top(); pq2.pop();
        }
        else if(pq2.empty()){
            s+=pq1.top(); pq1.pop();
        }
        else{
            if(pq1.top()>pq2.top()){
                s+=pq1.top(); pq1.pop();
            }
            else if(pq1.top()<pq2.top()){
                s+=pq2.top(); pq2.pop();
            }
            else{
                s+=pq1.top(); pq1.pop(); pq2.pop();
            }
        }
    }
    return s;
}

int main() {
    fastio;
    ll mxa=0, mxb=0;
    cin >> n >> m;
    a.resize(n); b.resize(m);
    forf(i, 0, n) {cin >> a[i]; mxa=max(mxa, a[i]);}
    forf(i, 0, m) {cin >> b[i]; mxb=max(mxb, b[i]);}
    if(mxa!=mxb){
        cout << "-1\n";
        return 0;
    }
    cout << mn() << " " << mx() << "\n";


    return 0;
}
