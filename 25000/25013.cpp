#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define sortv(v) sort(v.begin(), v.end())
const ll mod=1e9+7, MOD=998244353;

#include "onetwothree.h"

ll n;
vi v;
vi x1, x2, x3;

bool pu(vpii& v, ll &i, ll &j, ll &t){
    if(i<v[j][0] || v[j][1]<i) return false;
    if(t) answer(v[j][0], i, v[j][1]);
    j++; return true;
}

ll check(ll c, ll d, ll t){
    vpii in2c, in2d;

    if(c+d>min(x1.size(), x3.size())) return false;

    for(ll i=0; i<c; i++) in2c.push_back({x1[i], x3[x3.size()-c+i]});
    for(ll i=0; i<d; i++) in2d.push_back({x3[i], x1[x1.size()-d+i]});
    for(pii i : in2c) if(i[0]>i[1]) return false;
    for(pii i : in2d) if(i[0]>i[1]) return false;

    in2c.push_back({mod, mod});
    in2d.push_back({mod, mod});

    ll j1=0, j2=0;
    for(ll i : x2){
        if(in2c[j1][1]>in2d[j2][1]) swap(in2c, in2d), swap(j1, j2);
        if(!pu(in2c, i, j1, t)) pu(in2d, i, j2, t);
    }
    return (j1==in2c.size()-1 && j2==in2d.size()-1);
}

void maximize(vi a){
    n=a.size(); v=a;
    for(ll i=0; i<n; i++){
        if(v[i]==1) x1.push_back(i);
        if(v[i]==2) x2.push_back(i);
        if(v[i]==3) x3.push_back(i);
    }
    ll p1=0, p2=n/3;
    array<ll, 3> ret={0, 0, 0};
    while(p2>=0 && !check(p1, p2, 0)) p2--;

    while(p2>=0){
        ret=max(ret, {p1+p2, p1, p2});
        p1++;
        while(p2>=0 && !check(p1, p2, 0)) p2--;
    }
    check(ret[1], ret[2], 1);
}
