#include "floppy.h"
#include <bits/stdc++.h>
using namespace std;

void read_array(int subtask_id, const vector<int>& v) {
    int N=v.size(); string res; vector<int> st;
    for (int i : v) {
        while (st.size() && st.back()<i) st.pop_back(), res+="0";
        st.push_back(i); res+="1";
    }
    save_to_floppy(res);
}

int L[50505], R[50505], C[50505], X=16;
array<int, 2> S[1<<17];
vector<int> solve_queries(int subtask_id, int N, const string& bits, const vector<int>& a, const vector<int>& b) {
    vector<int> st, ans; int x=1;
    fill(L+1, L+N+1, 0); fill(R+1, R+N+1, N+1); fill(C+1, C+N+1, 0); C[0]=C[N+1]=1e9;
    for (int i=1; i<(1<<X+1); i++) S[i]={0, 0};
    for (char i : bits) {
        if (i=='0') R[st.back()]=x, st.pop_back();
        else {
            if (st.size()) L[x]=st.back();
            st.push_back(x++);
        }
    }
    st.clear();
    for (int i=1; i<=N; i++) C[L[i]]++, C[R[i]]++;
    for (int i=1; i<=N; i++) if (!C[i]) st.push_back(i);
    int c=0;
    while (st.size()) {
        int p=st.back(); st.pop_back();
        if (!--C[L[p]]) st.push_back(L[p]);
        if (!--C[R[p]]) st.push_back(R[p]);
        x=p+(1<<X)-1;
        while (x) S[x]={c, p-1}, x>>=1; c++;
    }
    for (int i=0; i<a.size(); i++) {
        int l=a[i]+(1<<X), r=b[i]+(1<<X);
        array<int, 2> z={0, 0};
        while (l<=r) {
            z=max({z, S[l], S[r]});
            ++l>>=1; --r>>=1;
        }
        ans.push_back(z[1]);
    }
    return ans;
}
