#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

#define pi array<int, 2>
#define vpi vector<array<int, 2>>

const int X=18;
struct node {
    vpi v;
    int mx;
} seg[1<<X+1];

int sq(int v, int c) {
    while (c>1) v++, c>>=1;
    return v;
}

int pp(vpi vec) {
    if (vec.size()==0) return 0;
    while (vec.size()>=2 || vec[0][1]>1) {
        int sz=vec.size();
        if (sz>=2 && vec[sz-1][0]==vec[sz-2][0]) vec[sz-2][1]+=vec[sz-1][1], vec.pop_back();
        else vec[sz-1][0]++, vec[sz-1][1]/=2;
    }
    return vec[0][0];
}

int fin(vpi vec) {
    //print(vec);
    vpi v;
    for (int j=0; j<vec.size(); j++) {
        int sz=v.size();
        if (sz>=3 && v[sz-3][0]==v[sz-2][0]) {
            v[sz-3][1]+=v[sz-2][1]; swap(v[sz-2], v[sz-1]); v.pop_back();
        }
        else if (sz>=2 && v[sz-2][0]==v[sz-1][0]) {
            v[sz-2][1]+=v[sz-1][1]; v.pop_back();
        }
        else if (sz>=3 && v[sz-3][0]>v[sz-2][0] && v[sz-2][0]<v[sz-1][0]) {
            if (v[sz-2][1]%2==0) v[sz-2][0]++, v[sz-2][1]/=2;
            else {
                vpi lef, rig;
                lef=v; lef.back()[1]--;
                for (int i=vec.size()-1; i>j; i--) rig.push_back(vec[i]);
                rig.push_back(lef.back());
                return max(pp(lef), pp(rig));
            }
        }
        else v.push_back(vec[j]);
    }
    if (v[0][0]<v.back()[0]) reverse(v.begin(), v.end());
    return pp(v);
}

node mrg(node a, node b) {
    if (a.v.size()==0) return b;
    if (b.v.size()==0) return a;
    vpi v; int mx=max(a.mx, b.mx);

    reverse(a.v.begin(), a.v.end()); reverse(b.v.begin(), b.v.end());
    for (;;) {
        int sz=v.size();
        if (sz>=3 && v[sz-3][0]==v[sz-2][0]) {
            v[sz-3][1]+=v[sz-2][1]; swap(v[sz-2], v[sz-1]); v.pop_back();
        }
        else if (sz>=2 && v[sz-2][0]==v[sz-1][0]) {
            v[sz-2][1]+=v[sz-1][1]; v.pop_back();
        }
        else if (sz>=3 && v[sz-3][0]>v[sz-2][0] && v[sz-2][0]<v[sz-1][0]) {
            if (v[sz-2][1]%2==0) v[sz-2][0]++, v[sz-2][1]/=2;
            else {
                mx=max(mx, sq(v[sz-2][0], v[sz-2][1]));
                if (v[sz-2][1]==1) {
                    v[sz-2][0]=inf;
                    a.v.push_back(v.back()); v.pop_back();
                }
                else{
                    v[sz-2][1]--;
                    v.push_back({inf, 0}); swap(v[sz-1], v[sz]);
                    v.push_back({v[sz-2][0], v[sz-2][1]}); swap(v[sz], v[sz+1]);
                    a.v.push_back(v.back()); v.pop_back();
                    a.v.push_back(v.back()); v.pop_back();
                }
            }
        }
        else if (a.v.size()) v.push_back(a.v.back()), a.v.pop_back();
        else break;
    }

    for (;;) {
        int sz=v.size();
        if (sz>=3 && v[sz-3][0]==v[sz-2][0]) {
            v[sz-3][1]+=v[sz-2][1]; swap(v[sz-2], v[sz-1]); v.pop_back();
        }
        else if (sz>=2 && v[sz-2][0]==v[sz-1][0]) {
            v[sz-2][1]+=v[sz-1][1]; v.pop_back();
        }
        else if (sz>=3 && v[sz-3][0]>v[sz-2][0] && v[sz-2][0]<v[sz-1][0]) {
            if (v[sz-2][1]%2==0) v[sz-2][0]++, v[sz-2][1]/=2;
            else {
                mx=max(mx, sq(v[sz-2][0], v[sz-2][1]));
                if (v[sz-2][1]==1) {
                    v[sz-2][0]=inf;
                    b.v.push_back(v.back()); v.pop_back();
                }
                else{
                    v[sz-2][1]--;
                    v.push_back({inf, 0}); swap(v[sz-1], v[sz]);
                    v.push_back({v[sz-2][0], v[sz-2][1]}); swap(v[sz], v[sz+1]);
                    b.v.push_back(v.back()); v.pop_back();
                    b.v.push_back(v.back()); v.pop_back();
                }
            }
        }
        else if (b.v.size()) v.push_back(b.v.back()), b.v.pop_back();
        else break;
    }

    vpi ret;

    int ip=0;
    for (; ip<v.size(); ip++) {
        ret.push_back(v[ip]);
        if (v[ip][0]==inf) break;
    }
    if (ip==v.size()) {
        return {v, mx};
    }
    for (int i=ip+1; i<v.size(); i++) {
        if (v[i][0]==inf) {
            mx=max(mx, fin(vector(v.begin()+ip+1, v.begin()+i)));
            ip=i;
        }
    }

    for (int i=ip+1; i<v.size(); i++) ret.push_back(v[i]);
    return {ret, mx};
}

int bit(vpi v) {
    for (int i=0; i<v.size(); i++) if (v[i][0]==inf) {
        vpi lef, rig;
        for (int j=i-1; j>=0; j--) lef.push_back(v[j]);
        for (int j=i+1; j<v.size(); j++) rig.push_back(v[j]);
        return max(pp(lef), pp(rig));
    }
    while (v.size()>=2 && v[v.size()-2][0]>=v[v.size()-1][0]) {
        int sz=v.size();
        if (v[sz-1][0]==v[sz-2][0]) v[sz-2][1]+=v[sz-1][1], v.pop_back();
        else v[sz-1][0]++, v[sz-1][1]/=2;
    }
    reverse(v.begin(), v.end());
    return pp(v);
}

void update_game(int p, int x) {
    p+=1<<X; seg[p]={{{x, 1}}, x};
    p>>=1;
    while (p) seg[p]=mrg(seg[p<<1], seg[p<<1|1]), p>>=1;
}
int play_game(int s, int e) {
    s+=1<<X; e+=1<<X; node ret={{}, 0};
    for (int i=X; i>=0; i--) {
        int l=(s-1>>i)+1, r=(e+1>>i)-1;
        if (l>r) continue;
        if (l&1) ret=mrg(seg[l], ret);
        if (~r&1) ret=mrg(ret, seg[r]);
    }
    return max(ret.mx, bit(ret.v));
}

void prepare_game(vector<int> A) {
    int N=A.size();
    for (int i=0; i<N; i++) update_game(i, A[i]);
}
