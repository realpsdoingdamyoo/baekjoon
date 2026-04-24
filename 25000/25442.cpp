#include "insects.h"

#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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

V<bool> isin, isin_s, isin_e;
int inm;

void in(int i){move_inside(i); isin[i]=true; inm++;}
void out(int i){move_outside(i); isin[i]=false; inm--;}
int pr(){return press_button();}


int __Q;
bool chk(int x, int n, int d){
    forf(i, 0, n){
        if(isin_s[i] || !isin_e[i]) continue;
        in(i);
        if(pr()>x) out(i);
    }
    if(inm==d*x) isin_s=isin;
    if(inm!=d*x) isin_e=isin;

    forf(i, 0, n){
        if(isin_s[i] || !isin_e[i]) continue;
        if(isin[i]) out(i);
    }

    if(inm==d*x) return true;
    return false;
}

int min_cardinality(int n){
    ll d=0; isin.resize(n);
    forf(i, 0, n){
        in(i); d++;
        if(pr()>1) {out(i); d--;}
    }
    isin_s=isin; isin_e.resize(n);
    forf(i, 0, n) isin_e[i]=true;

    ll s=1, e=n/d;
    while(s<=e){
        ll m=(s+e+1+(e-s>7))/2;
        if(chk(m, n, d)) s=m+1;
        else e=m-1;
    }
    return e;
}
