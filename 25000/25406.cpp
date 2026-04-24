#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
typedef string S;
#define V vector
#define PQ priority_queue
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(ll i=s; i<e; i++)
#define forb(i, s, e) for(ll i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define all(v) v.begin(), v.end()
const ll mod=1e9+7, MOD=998244353;
const ll dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}



int main(){
    //fastio;

    ll n; cin >> n;
    vvi v(n); vi u(n);
    PQ<pii> pq, dpq;
    PQ<pii> pq2, dpq2;

    forf(i, 0, n){
        cin >> u[i]; u[i]--;
        v[u[i]].pb(i);
    }
    forf(i, 0, n){
        reverse(all(v[i]));
        if(v[i].size()) pq.push({-v[i][v[i].size()-1], i});
        pq2.push({v[i].size(), i});
        if(v[i].size()*2>n+1){
            cout << "-1";
            return 0;
        }
    }


    ll prev=-1;
    while(n){
        if(pq2.top()[0]*2-1>=n){
            ll ind=pq2.top()[1]; prev=ind;
            cout << v[ind][v[ind].size()-1]+1 << " ";
            dpq.push({-v[ind][v[ind].size()-1], ind});
            dpq2.push({v[ind].size(), ind});
            v[ind].pop_back();
            if(v[ind].size()) pq.push({-v[ind][v[ind].size()-1], ind});
            pq2.push({v[ind].size(), ind});
        }
        else{
            if(pq.top()[1]!=prev){
                ll ind=pq.top()[1]; prev=ind;
                cout << v[ind][v[ind].size()-1]+1 << " ";
                dpq.push({-v[ind][v[ind].size()-1], ind});
                dpq2.push({v[ind].size(), ind});
                v[ind].pop_back();
                if(v[ind].size()) pq.push({-v[ind][v[ind].size()-1], ind});
                pq2.push({v[ind].size(), ind});
            }
            else{
                pii t=pq.top(); pq.pop();
                while(dpq.size() &&dpq.top()==pq.top()){pq.pop(); dpq.pop();}
                ll ind=pq.top()[1]; prev=ind;
                cout << v[ind][v[ind].size()-1]+1 << " ";
                dpq.push({-v[ind][v[ind].size()-1], ind});
                dpq2.push({v[ind].size(), ind});
                v[ind].pop_back();
                if(v[ind].size()) pq.push({-v[ind][v[ind].size()-1], ind});
                pq2.push({v[ind].size(), ind});
                pq.push(t);
            }
        }

        while(dpq.size() &&dpq.top()==pq.top()){
            pq.pop(); dpq.pop();
        }
        while(dpq2.size() &&dpq2.top()==pq2.top()){
            pq2.pop(); dpq2.pop();
        }
        n--;

    }

    return 0;
}
