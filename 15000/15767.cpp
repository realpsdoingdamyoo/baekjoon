#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N;
int X[303030], Y[303030], C[303030], A[303030];
int R;

unordered_map<long long, vector<int>> T;

long long con(int p) {
    long long a=(X[p]+mod)/R, b=(Y[p]+mod)/R;
    return (a<<30)|b;
}

bool inter(int a, int b) {
    long long dis=1LL*(X[a]-X[b])*(X[a]-X[b])+1LL*(Y[a]-Y[b])*(Y[a]-Y[b]);
    return dis<=1LL*(C[a]+C[b])*(C[a]+C[b]);
}

signed main() {
    fastio;

    cin >> N;

    for (int i=1; i<=N; i++) cin >> X[i] >> Y[i] >> C[i];
    R=*max_element(C+1, C+N+1);

    set<array<int, 2>> st;
    for (int i=1; i<=N; i++) st.insert({C[i], -i});
    for (int i=1; i<=N; i++) T[con(i)].push_back(i);

    while (st.size()) {
        int p=-(*prev(st.end()))[1];
        if (C[p]*2<R) {
            R=C[p]; T.clear();
            for (array<int, 2> i : st) T[con(-i[1])].push_back(-i[1]);
        }

        long long a=(X[p]+mod)/R, b=(Y[p]+mod)/R;

        for (long long na=a-2; na<=a+2; na++) for (long long nb=b-2; nb<=b+2; nb++){
            if (T.find((na<<30)|nb)==T.end()) continue;
            vector<int>& vec=T[(na<<30)|nb];
            for (int i=0; i<vec.size();) {
                if (inter(p, vec[i])) {
                    A[vec[i]]=p;
                    st.erase(st.find({C[vec[i]], -vec[i]}));
                    swap(vec[i], vec.back());
                    vec.pop_back();
                }
                else i++;
            }
        }
    }

    for (int i=1; i<=N; i++) cout << A[i] << " ";

    return 0;
}
