#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> complaint(int N, vector<int> L, vector<int> R) {
    vector<array<int, 2>> u, v;
    for (int i=0; i<L.size(); i++) u.push_back({L[i], R[i]});

    sort(u.begin(), u.end(), [&](array<int, 2> a, array<int, 2> b){return a[0]==b[0]?a[1]<b[1]:a[0]>b[0];});
    int en=N, g;
    for (array<int, 2> i : u) if (i[1]<en) en=i[1], v.push_back(i);

    vector<int> c={-1}, d={N};
    for (array<int, 2> i : v) if (d.back()>i[1]) d.push_back(i[0]);
    reverse(v.begin(), v.end());
    for (array<int, 2> i : v) if (c.back()<i[0]) c.push_back(i[1]);
    g=c.size()-1;

    vector<int> l(N, g), r(N, g), s;
    for (int i=0; i<g; i++) {for (int j=c[i]+1; j<=c[i+1]; j++) l[j]=i; for (int j=d[i]-1; j>=d[i+1]; j--) r[j]=i;}
    for (int i=0; i<N; i++) if (l[i]+r[i]!=g) s.push_back(i);
    return {g, s};
}
