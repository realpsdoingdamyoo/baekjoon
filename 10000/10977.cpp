#include <iostream>
#include <cstring>
using namespace std;

int food[1000000];
int pi[1000000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        memset(food, 0, sizeof(food));
        memset(pi, 0, sizeof(pi));
        int M, N; cin >> M >> N;

        while (N--) {
            int x; cin >> x;
            food[x - 1] = 1;
        }

        for (int i = 0; i < M; i++) {
            int idx = i;
            while (idx > 0) {
                if (food[pi[idx - 1]] == food[i]) break;
                idx = pi[idx - 1];
            }
            if (idx <= 0) pi[i] = 0;
            else pi[i] = pi[idx - 1] + 1;
        }
        int temp = M - pi[M - 1];
        if (M % temp == 0) cout << temp << '\n';
        else cout << M << '\n';
    }
}
