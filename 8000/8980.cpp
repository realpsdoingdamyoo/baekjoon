#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<int, 3> tii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int njh[2001];

bool cmp(tii a, tii b){
    if(a[1]<b[1]) return true;
    else if(a[1]==b[1] && a[0]<b[0]) return true;
    return false;
}

int main() {
    vector<tii> v;
    int n, mx, sz, mv=0;
    cin >> sz >> mx >> n;
    for(int i=0; i<n; i++){
        int a, b, c; cin >> a >> b >> c;
        v.push_back({a, b, c});
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<n; i++){
        int s=v[i][0], e=v[i][1], m=v[i][2];
        int minel=mx-*max_element(njh+s, njh+e);
        int pl=min(m, minel);
        for(int j=s; j<e; j++) njh[j]+=pl;
        mv+=pl;
        /*cout << s << " " << e << " " << pl << endl;
        for(int j=1; j<sz; j++)cout << njh[j] << " ";
        cout << "\n\n"*/
        }
    cout << mv;
    return 0;
}
