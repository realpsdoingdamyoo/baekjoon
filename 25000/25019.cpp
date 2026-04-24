#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf=2e10;
#define si signed

int fly(vector<si> D, vector<si> H, vector<si> W, si L, si R) {
    int N=D.size();
    for (int i=N-2; i>=0; i--) {
        H[i]=min(H[i], H[i+1]+(D[i+1]-D[i]));
        if (H[i]-(D[i+1]-D[i])<0) return -1;
    }
    L=min(L, H[0]);
    vector<array<int, 2>> v, u;
    for (int i=0; i<N; i++) v.push_back({i?D[i]:L, W[i]-inf}), v.push_back({D[i]+H[i], W[i]});
    sort(v.begin(), v.end());

    multiset<int> st={inf};
    for (array<int, 2> i : v) {
        if (i[1]<0) st.insert(i[1]+inf);
        else st.erase(st.find(i[1]));
        u.push_back({i[0], *st.begin()});
    }

    int ans=0;
    for (int i=0; i<u.size()-1; i++) {
        int l=max(u[i][0], 0LL+L), r=min(u[i+1][0], 0LL+R+D[N-1]);
        if (l<r) ans+=(r-l)*u[i][1];
    }
    return ans;
}
