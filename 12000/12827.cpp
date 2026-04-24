#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M;
array<int, 4> V[101010];
array<int, 4> Q[101010];
int ans[101010];
vector<int> Xcp, Ycp;

int W, H;
int W1[424040], W2[404040];

vector<array<int, 3>> upd[404040];
vector<array<int, 4>> qry[404040];

const int X=700, Y=575;

int C[404040]; // 각 원소당 덮여진 횟수
int OV[404040]; // 각 원소당 누적값

struct bucket {
    int LZ; // C의 레이지값
    int LOV; // 버킷 전체의 누적값

    int FS; // 버킷 전체의 가로 넓이
    int HMF; // FS가 더해진 횟수

    int PS; // 버킷 중 포스터가 덮여진 부분의 가로 넓이(LZ=0일 때)
    int HMP; // PS 수정 이후로 PS가 더해진 횟수

    int S, E; // 담당 구간의 시작점, 끝점

    void update1(int s, int e, int x) {
        if (HMP) {
            for (int i=S; i<=E; i++) OV[i]+=W1[i]*HMP*!!C[i];
            HMP=0;
        }

        for (int i=max(s, S); i<=min(e, E); i++) {
            PS-=W1[i]*!!C[i]; C[i]+=x; PS+=W1[i]*!!C[i];
        }
    }

    void update2(int x) {
        LZ+=x;
    }

    void uay(int y) {
        if (LZ) LOV+=FS*y, HMF+=y;
        else LOV+=PS*y, HMP+=y;
    }

    int query1(int s, int e) {
        int ret=0;
        for (int i=max(s, S); i<=min(e, E); i++) {
            ret+=OV[i]+W1[i]*(HMF+HMP*!!C[i]);
        }
        return ret;
    }

    int query2() {
        return LOV;
    }
} bck[Y];

void update(int s, int e, int x) {
    for (int i=0; i<Y; i++) {
        int S=i*X, E=i*X+X-1;
        if (e<S || E<s) continue;
        if (s<=S && E<=e) bck[i].update2(x);
        else bck[i].update1(s, e, x);
    }
}

int query(int s, int e) {
    int ret=0;
    for (int i=0; i<Y; i++) {
        int S=i*X, E=i*X+X-1;
        if (e<S || E<s) continue;
        if (s<=S && E<=e) ret+=bck[i].query2();
        else ret+=bck[i].query1(s, e);
    }
    return ret;
}

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> V[i][0] >> V[i][1] >> V[i][2] >> V[i][3];
        Xcp.push_back(V[i][0]); Xcp.push_back(V[i][2]);
        Ycp.push_back(V[i][1]); Ycp.push_back(V[i][3]);
    }
    cin >> M;
    for (int i=1; i<=M; i++) {
        cin >> Q[i][0] >> Q[i][1] >> Q[i][2] >> Q[i][3];
        Xcp.push_back(Q[i][0]); Xcp.push_back(Q[i][2]);
        Ycp.push_back(Q[i][1]); Ycp.push_back(Q[i][3]);
    }

    sort(Xcp.begin(), Xcp.end()); Xcp.erase(unique(Xcp.begin(), Xcp.end()), Xcp.end());
    sort(Ycp.begin(), Ycp.end()); Ycp.erase(unique(Ycp.begin(), Ycp.end()), Ycp.end());
    W=Xcp.size(); H=Ycp.size();
    W=H=max(W, H);

    for (int i=1; i<=N; i++) {
        V[i][0]=lower_bound(Xcp.begin(), Xcp.end(), V[i][0])-Xcp.begin()+1;
        V[i][1]=lower_bound(Ycp.begin(), Ycp.end(), V[i][1])-Ycp.begin()+1;
        V[i][2]=lower_bound(Xcp.begin(), Xcp.end(), V[i][2])-Xcp.begin();
        V[i][3]=lower_bound(Ycp.begin(), Ycp.end(), V[i][3])-Ycp.begin();

        upd[V[i][0]].push_back({V[i][1], V[i][3], 1});
        upd[V[i][2]+1].push_back({V[i][1], V[i][3], -1});
        //cout << "V " << V[i][0] << " " << V[i][1] << " " << V[i][2] << " " << V[i][3] << "\n";
    }
    for (int i=1; i<=M; i++) {
        Q[i][0]=lower_bound(Xcp.begin(), Xcp.end(), Q[i][0])-Xcp.begin()+1;
        Q[i][1]=lower_bound(Ycp.begin(), Ycp.end(), Q[i][1])-Ycp.begin()+1;
        Q[i][2]=lower_bound(Xcp.begin(), Xcp.end(), Q[i][2])-Xcp.begin();
        Q[i][3]=lower_bound(Ycp.begin(), Ycp.end(), Q[i][3])-Ycp.begin();

        qry[Q[i][0]-1].push_back({Q[i][1], Q[i][3], -1, i});
        qry[Q[i][2]].push_back({Q[i][1], Q[i][3], 1, i});
        //cout << "Q " << Q[i][0] << " " << Q[i][1] << " " << Q[i][2] << " " << Q[i][3] << "\n";
    }

    for (int i=1; i<Xcp.size(); i++) W2[i]=Xcp[i]-Xcp[i-1];
    for (int i=1; i<Ycp.size(); i++) W1[i]=Ycp[i]-Ycp[i-1];

    for (int i=0; i<W; i++) bck[i/X].FS+=W1[i];
    for (int i=0; i<Y; i++) bck[i].S=i*X, bck[i].E=i*X+X-1;

    for (int i=1; i<=H+1; i++) {
        for (array<int, 3> j : upd[i]) update(j[0], j[1], j[2]);
        for (int j=0; j<Y; j++) bck[j].uay(W2[i]);
        for (array<int, 4> j : qry[i]) {
            ans[j[3]]+=query(j[0], j[1])*j[2];
        }
    }

    for (int i=1; i<=M; i++) cout << ans[i] << "\n";


    return 0;
}
