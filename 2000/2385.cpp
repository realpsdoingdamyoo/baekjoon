#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s[100], t;
bool cmp1(string i, string j) { return i + j<j + i; }
bool cmp2(string i, string j) { return i + t + j<j + t + i; }
int n, i;
int main() {
    cin >> n;
    for (i = 0; i<n; i++) cin >> s[i];
    sort(s, s + n, cmp1);
    for (i = 0; i<n && s[i][0] == '0'; i++) t += s[i];
    if (i == n) {cout << "INVALID"; return 0;}
    int p = min_element(s + i, s + n, cmp2) - s;
    cout << s[p];
    for (int i = 0; i<n; i++) if (i^p) cout << s[i];
}
