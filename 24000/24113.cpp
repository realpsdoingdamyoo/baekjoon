#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M;
vector<array<int, 2>> S1, S2;
vector<array<int, 2>> S, R, RR;

signed main(){
    fastio;

    cin >> N; S1.resize(N);
    for (array<int, 2>& i : S1) cin >> i[0] >> i[1];
    cin >> M; S2.resize(M);
    for (array<int, 2>& i : S2) cin >> i[0] >> i[1];

    while (S1.size() || S2.size()) {
        if (S1.size() && S1.back()[1]==0) {S1.pop_back(); continue;}
        if (S2.size() && S2.back()[1]==0) {S2.pop_back(); continue;}
        if (S1.size()==0) S1.push_back({0, S2.back()[1]});
        if (S2.size()==0) S2.push_back({0, S1.back()[1]});

        int L=min(S1.back()[1], S2.back()[1]);
        S.push_back({S1.back()[0]+S2.back()[0], L});
        S1.back()[1]-=L; S2.back()[1]-=L;
    }

    int O=0;
    for (array<int, 2> i : S) {
        if (i[0]<=9) {
            if (O==0) R.push_back(i);
            else if (i[0]<9) {
                R.push_back({i[0]+1, 1});
                R.push_back({i[0], i[1]-1});
                O=0;
            }
            else {
                R.push_back({0, i[1]});
                O=1;
            }
        }
        else {
            if (O==0) {
                R.push_back({i[0]%10, 1});
                R.push_back({i[0]/10+i[0]%10, i[1]-1});
                O=1;
            }
            else {
                R.push_back({i[0]/10+i[0]%10, i[1]});
                O=1;
            }
        }
    }
    if (O==1) R.push_back({1, 1});

    for (array<int, 2> i : R) {
        if (i[1]==0) continue;
        if (RR.size() && RR.back()[0]==i[0]) RR.back()[1]+=i[1];
        else RR.push_back(i);
    }

    cout << RR.size() << "\n";
    reverse(RR.begin(), RR.end());
    for (array<int, 2> i : RR) cout << i[0] << " " << i[1] << "\n";

    return 0;
}
