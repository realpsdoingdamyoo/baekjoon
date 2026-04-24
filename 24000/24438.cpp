#include <bits/stdc++.h>
using namespace std;

int query(string q);

int inc(int N, char c) {
    int s=1, e=N;
    while (s<=e) {
        int m=s+e>>1;
        if (query(string(m, c))==m) s=m+1;
        else e=m-1;
    }
    return e;
}

int push(string& ans, int N, int p, char c) {
    int ret=0;
    while (ans.length()<N) {
        ans.insert(ans.begin()+p, c); ret++;
        if (query(ans)<ans.length()) {ans.erase(ans.begin()+p); ret--; break;}
    }
    return ret;
}

string guess(int N, int S) {
    vector<array<int, 2>> v(S);
    for (int i=0; i<S; i++) v[i]={inc(N, 'a'+i), i};
    sort(v.begin(), v.end());

    string ans(v[0][0], 'a'+v[0][1]);
    for (int p=1; p<S; p++) {
        char c='a'+v[p][1];
        int i=0;
        for (i=0; i<ans.length(); i+=2) {
            swap(ans[i], c);
            if (query(ans)<ans.length()) {swap(ans[i], c); continue;}
            swap(ans[i], c);
            i+=push(ans, N, i, c);
            i+=push(ans, N, i+1, c);
        }
        if (i==ans.length()) push(ans, N, i, c);
    }
    return ans;
}
