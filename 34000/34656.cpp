#include <bits/stdc++.h>
using namespace std;

int N;
queue<int> q[3];
vector<array<int, 2>> ans;

void move(int a, int b) {
    assert(q[b].size() <= N);
    int x = q[a].front();
    q[a].pop();
    q[b].push(x);
    ans.push_back({a, b});
}

void bmv(int a, int b, int x) {
    while (q[a].front() != x)
        move(a, a);
    while (q[b].front() != x)
        move(b, b);
    move(a, b);
    while (q[a].front() != x - 1)
        move(a, a);
    move(a, a);
    move(b, a);
}

int C[111][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= 2; i++) {
        int M;
        cin >> M;
        while (M--) {
            int a;
            cin >> a;
            q[i].push(a);
        }
    }

    if (q[1].size() > q[2].size())
        move(1, 2);
    if (q[1].size() < q[2].size())
        move(2, 1);

    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= N; j++) {
            C[q[i].front()][i]++;
            q[i].push(q[i].front());
            q[i].pop();
        }
    }

    int DC = 0;
    for (int i = 1; i <= N; i++)
        DC += max(C[i][1] - 1, 0);

    for (int t = 1; t <= DC; t++) {
        for (int i = 1; i <= 2; i++) {
            while (C[q[i].front()][i] != 2)
                move(i, i);
        }
        int x = q[1].front(), y = q[2].front();
        C[x][1]--;
        C[x][2]++;
        C[y][2]--;
        C[y][1]++;
        move(1, 2);

        move(2, 1);
    }

    for (int i = 2; i <= N - 1; i++) {
        bmv(1, 2, i);
        bmv(2, 1, i);
    }

    while (q[1].front() != 1)
        move(1, 1);
    while (q[2].front() != 1)
        move(2, 2);

    cout << ans.size() << "\n";
    for (array<int, 2> i : ans)
        cout << i[0] << " " << i[1] << "\n";
}
