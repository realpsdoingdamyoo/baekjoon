#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

vector<vector<int>> V;
int C[202020], X=400;

void update(int p) {
    if (V[p].size()>2*X) {
        vector<int> tmp;
        for (int i=X; i<V[p].size(); i++) tmp.push_back(V[p][i]);
        V[p].resize(X);
        V.insert(V.begin()+p+1, tmp);
    }
}

signed main() {
    fastio;

    int Q; cin >> Q;
    while (Q--) {
        int t, x; cin >> t >> x;
        if (x>X) {
            if (t==1) {
                if (V.size()==0) V={{x}};
                else if (x<V[0][0]) {
                    V[0].insert(V[0].begin(), x); update(0);
                }
                else {
                    for (int i=V.size()-1; i>=0; i--) if (V[i][0]<=x) {
                        if (V[i].back()<x) {V[i].push_back(x); update(i); break;}
                        for (int j=0; j<V[i].size(); j++) if (V[i][j]>=x) {
                            V[i].insert(V[i].begin()+j, x); update(i); i=-1; break;
                        }
                    }
                }
            }
            else {
                for (int i=V.size()-1; i>=0; i--) if (V[i][0]<=x) {
                    for (int j=0; j<V[i].size(); j++) if (V[i][j]==x) {
                        V[i].erase(V[i].begin()+j);
                        if (V[i].size()==0) V.erase(V.begin()+i);
                        i=-1; break;
                    }
                }
            }
        }
        else C[x]+=(t==1)-(t==2);


        int R=0, lf=0;

        for (int i=1; i<=X; i++) if (C[i]) {
            if (C[i]<=lf) {lf-=C[i]; continue;}
            int c=C[i]-lf;
            R+=c/i; c%=i;
            if (c) R++, lf=i-c; else lf=0;
        }

        int p=0, ps=0;
        while (p<V.size()) {
            if (ps+V[p].size()<=lf) {ps+=V[p].size(); p++; continue;}
            int n=V[p][lf-ps];
            lf+=n; R++;
        }

        cout << R << "\n";
    }

    return 0;
}
