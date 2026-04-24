#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=4e18;
mt19937 rd(6974);

int N;
array<int, 3> V[100];
vector<array<int, 2>> ln;

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> V[i][0] >> V[i][1] >> V[i][2];

    for (int i=1; i<=N; i++) for (int j=i+1; j<=N; j++) for (int k=1; k<=N; k++) if (k!=i && k!=j) {
        array<int, 4> pl;
        array<int, 3> l1, l2;
        l1={V[j][0]-V[i][0], V[j][1]-V[i][1], V[j][2]-V[i][2]};
        l2={V[k][0]-V[i][0], V[k][1]-V[i][1], V[k][2]-V[i][2]};
        pl={l1[1]*l2[2]-l2[1]*l1[2], l1[2]*l2[0]-l2[2]*l1[0], l1[0]*l2[1]-l2[0]*l1[1], 0};
        pl[3]=pl[0]*V[i][0]+pl[1]*V[i][1]+pl[2]*V[i][2];

        int cnt=0;
        for(int p=1; p<=N; p++){
            if(p==i || p==j || p==k) continue;
            cnt+=(pl[0]*V[p][0]+pl[1]*V[p][1]+pl[2]*V[p][2]<pl[3]);
        }
        if(cnt==0 || cnt==N-3) {ln.push_back({i, j}); break;}
    }

    int fcs=ln.size()-N+2, ans=0;

    for (int t=0; t<300; t++) {
        for (int i=1; i<=N; i++) for (int j=i+1; j<=N; j++) {
            int k=N+1;
            V[N+1][0]=rd()%10000-5000; V[N+1][1]=rd()%10000-5000; V[N+1][2]=rd()%10000-5000;

            array<int, 4> pl;
            array<int, 3> l1, l2;
            l1={V[j][0]-V[i][0], V[j][1]-V[i][1], V[j][2]-V[i][2]};
            l2={V[k][0]-V[i][0], V[k][1]-V[i][1], V[k][2]-V[i][2]};
            pl={l1[1]*l2[2]-l2[1]*l1[2], l1[2]*l2[0]-l2[2]*l1[0], l1[0]*l2[1]-l2[0]*l1[1], 0};
            pl[3]=pl[0]*V[i][0]+pl[1]*V[i][1]+pl[2]*V[i][2];
            pl[0]*=100000; pl[1]*=100000; pl[2]*=100000; pl[3]*=100000; pl[3]+=1;

            int cnt=0;
            for (array<int, 2> x : ln) {
                int A=(pl[0]*V[x[0]][0]+pl[1]*V[x[0]][1]+pl[2]*V[x[0]][2]<pl[3]);
                int B=(pl[0]*V[x[1]][0]+pl[1]*V[x[1]][1]+pl[2]*V[x[1]][2]<pl[3]);
                cnt+=A^B;
            }

            ans=max(ans, fcs+2+cnt);
        }
    }

    cout << ans << "\n";



    return 0;
}
