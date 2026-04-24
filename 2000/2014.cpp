#include <bits/stdc++.h>
using namespace std;

int K, N;
int P[110];

signed main(){
    cin >> K >> N;
    for (int i=1; i<=K; i++) cin >> P[i];
    priority_queue<array<int, 2>> q;
    q.push({-1, 1});

    while (N--) {
        int x=q.top()[0], y=q.top()[1]; q.pop();
        for (int i=y; i<=K; i++) if (-1LL*x*P[i]<(1LL<<31)) q.push({x*P[i], i});
    }
    cout << -q.top()[0];
}
