#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

bool cmp(array<int, 4> a, array<int, 4> b){
    return a[3]<b[3];
}

int main() {
    fastio;
    vector<array<int, 4>> v;
    int n, q; cin >> n >> q;
    for(int i=0; i<n; i++){
        int s, e, y;
        cin >> s >> e >> y;
        v.push_back({s, e, 0, i});
    }
    sort(v.begin(), v.end());
    int nowcls=0, nmx=0;
    for(int i=0; i<n; i++){
        if(v[i][0]>nmx) nowcls++;
        nmx=max(nmx, v[i][1]);
        v[i][2]=nowcls;
    }
    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<q; i++){
        int a, b;
        cin >> a >> b;
        cout << (v[a-1][2]==v[b-1][2]) << "\n";
    }
}
