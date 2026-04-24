#include "workshop.h"
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

vi len[21];

void init(){
    forf(i, 0, 1<<20){
        int r=0;
        forf(j, 0, 20) r+=!!(i&(1<<j));
        if(r==10) len[20].pb(i);
    }
    forf(i, 0, 1<<6){
        int r=0;
        forf(j, 0, 6) r+=!!(i&(1<<j));
        if(r==3) len[6].pb(i);
    }
    forf(i, 0, 1<<4){
        int r=0;
        forf(j, 0, 4) r+=!!(i&(1<<j));
        if(r==2) len[4].pb(i);
    }
}

int ret(int m, int r, int x){
    int _m=len[x][m];
    int _r=len[x][r];

    forf(i, 0, x) if((_m&(1<<i)) > (_r&(1<<i))) return i;
}

int morning(int m, int r){
    return ret(m, r, 20);
}

int afternoon(int l, int m, int r){
    return ret(ret(l, m, 6), ret(m, r, 6), 4);
}

int evening(int l, int m, int r){
    if(m==3 && l!=r) return 3-l-r;
    else if(m==3) return (l+1)%3;
    return m;
}
