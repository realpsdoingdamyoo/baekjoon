#include <bits/stdc++.h>
#define int long long
using namespace std;
#define cf \
    ;      \
    cout.flush();

int N;
int S[1010][1010];

void solve() {
    int N, M = 0;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cout << "? ";
        for (int j = 1; j <= N; j++) {
            cout << (N - i + j - 1) % N + 1 << " ";
        }
        cout << "\n";
        cf;
        for (int j = 1; j <= N; j++)
            cin >> S[(N - i + j - 1) % N + 1][N - j];
        M = 0;
        for (int j = 1; j <= N; j++)
            M += S[(N - i + j - 1) % N + 1][N - j];
    }

    cout << "! " << M << "\n";
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            for (int k = 1; k <= S[i][j - i] - S[i][j - i - 1]; k++)
                cout << i << " " << j << "\n";
        }
    }
    cout.flush();
    return;
}

signed main() {
    int T;
    cin >> T;
    while (T--)
        solve();
}
