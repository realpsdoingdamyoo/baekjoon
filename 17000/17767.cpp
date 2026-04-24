#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int N, M, C, p, L;
int V[1000001][3];
vector<array<int, 3>> P[1000001];
int U[1000001];
vector<int> cmp;

vector<array<int, 3>> stp[2000002];
set<array<int, 3>> pq, ak[1000001];
set<int> st;
set<int> B;

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> V[i][0] >> V[i][1] >> V[i][2], U[i]=V[i][2];
    sort(U+1, U+N+1);
    for (int i=1; i<=N; i++) {
        V[i][2]=lower_bound(U+1, U+N+1, V[i][2])-U;
        P[V[i][2]].push_back({V[i][0], V[i][1], i});
    }

    cmp.reserve(2*N);
    for (int i=1; i<=N; i++) {
        if (P[i].size()==0) continue;
        sort(P[i].begin(), P[i].end(), [&](array<int, 3> a, array<int, 3> b){return a[1]>b[1];});
        st.clear();
        for (array<int, 3>& j : P[i]) st.insert(j[1]);

        P[i].push_back({-1, -1, -1});
        p=P[i][0][1]+1; L=0;
        for (array<int, 3>& j : P[i]) {
            while (p>j[1] && L) st.insert(p), p--, L--;
            p=j[1]; L++;
        }
        P[i].pop_back();

        sort(P[i].begin(), P[i].end());
        reverse(P[i].begin(), P[i].end());
        for (array<int, 3>& j : P[i]) {
            j[1]=*prev(st.upper_bound(j[1]));
            st.erase(st.find(j[1]));

            if (j[1]<j[0]) {
                cout << "NIE";
                return 0;
            }

            cmp.push_back(j[0]);
            cmp.push_back(j[1]);
        }
    }

    sort(cmp.begin(), cmp.end());
    for (int i=1; i<=N; i++) for (array<int, 3>& j : P[i]) {
        for (int k : {0, 1}) j[k]=lower_bound(cmp.begin(), cmp.end(), j[k])-cmp.begin()+1;
        stp[j[0]].push_back({j[1], j[2], i});
    }

    for (int i=1; i<=2*N; i++) {
        for (array<int, 3>& j : stp[i]) pq.insert(j), ak[j[2]].insert(j), B.insert(j[2]);
        if (!pq.size() || (*pq.begin())[0]!=i) continue;

        vector<int> df; C++;
        for (int j : B) {
            U[(*ak[j].begin())[1]]=cmp[i-1];
            pq.erase(pq.find(*ak[j].begin()));
            ak[j].erase(ak[j].begin());
            if (ak[j].size()==0) df.push_back(j);
        }
        for (int j : df) B.erase(B.find(j));
    }

    cout << C << "\n";
    for (int i=1; i<=N; i++) cout << U[i] << "\n";

    return 0;
}
