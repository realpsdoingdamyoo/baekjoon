#include <bits/stdc++.h>
using namespace std;

struct Ability {
    int idx, stats;
    Ability(int idx, int stats) : idx(idx), stats(stats) {}
    bool operator<(const Ability& other) const {
        return other.stats < stats;
    }
};

int result = 0;
vector<vector<Ability>> abilities(5);
vector<bool> visited;

void search(int sum, int idx, int N);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    abilities.assign(5, vector<Ability>());
    visited.assign(N, false);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            int stat;
            cin >> stat;
            abilities[j].emplace_back(i, stat);
        }
    }
    for (int i = 0; i < 5; i++) {
        sort(abilities[i].begin(), abilities[i].end());
    }
    search(0, 0, N);
    cout << result << endl;

    return 0;
}

void search(int sum, int idx, int N) {
    if (idx == 5) {
        result = max(result, sum);
        return;
    }
    for (int i = 0; i < 5; i++) {
        Ability cur = abilities[idx][i];
        if (!visited[cur.idx]) {
            visited[cur.idx] = true;
            search(sum + cur.stats, idx + 1, N);
            visited[cur.idx] = false;
        }
    }
}
