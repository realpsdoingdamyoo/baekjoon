#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, Q;
int L[202020], HH[202020];
vector<int> hull;

int M;
array<int, 2> H[202020];

bool bol(int a, int b, int c) {
    int dL1 = L[b] - L[a], dH1 = HH[b] - HH[a];
    int dL2 = L[c] - L[b], dH2 = HH[c] - HH[b];
    return dH1 * dL2 >= dH2 * dL1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> L[i] >> HH[i];

    for (int i = 1; i <= N; i++) {
        while (hull.size() >= 2 && bol(hull[hull.size() - 2], hull[hull.size() - 1], i))
            hull.pop_back();
        hull.push_back(i);
    }

    M = hull.size();
    for (int i = 1; i <= M; i++)
        H[i] = {L[hull[i - 1]], HH[hull[i - 1]]};

    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int x;
        cin >> x;
        array<int, 2> F, B;
        F = *prev(lower_bound(H + 1, H + M + 1, (array<int, 2>){x, 0}));
        B = *lower_bound(H + 1, H + M + 1, (array<int, 2>){x, 0});
        int y = F[1] * (B[0] - x) + B[1] * (x - F[0]), z = B[0] - F[0];
        int d = __gcd(y, z);
        y /= d;
        z /= d;
        cout << y << " " << z << "\n";
    }

    return 0;
}
