#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M;
vector<int> A[202020], B[202020];
unordered_map<int, int> MA, MB;

bool AO[202020], BO[202020];
int ADG[202020], BDG[202020];
int ARC[202020], BRC[202020];
set<array<int, 2>> ALF, BLF;
vector<array<int, 8>> pp;

int MC[202020];

void smsA() {
    int AP, BP, CP;
    for (int i=1; i<=N; i++) if (ADG[i]==M-2) AP=i; CP=AP;
    for (int i=1; i<=N; i++) if (!AO[i]) CP^=i;
    for (int i : A[AP]) if (!AO[i]) CP^=i;
    for (int i : A[CP]) if (!AO[i]) BP=i;

    vector<int> ast;
    for (int i=1; i<=N; i++) if (!AO[i] && i!=AP && i!=BP && i!=CP) ast.push_back(i);

    int BLF_, BN;
    for (int i=1; i<=N; i++) if (!BO[i] && BDG[i]==1) BLF_=i; MC[BLF_]=AP;
    for (int i : B[BLF_]) if (!BO[i]) BN=i; MC[BN]=CP;
    int BPO=0;
    for (int i=1; i<=N; i++) if (!BO[i] && i!=BLF_ && i!=BN) {
        if (!BPO && !MB[i*N+BN]) MC[i]=BP, BPO=1;
        else MC[i]=ast.back(), ast.pop_back();
    }
}

void smsB() {
    int AP, BP, CP;
    for (int i=1; i<=N; i++) if (BDG[i]==M-2) AP=i; CP=AP;
    for (int i=1; i<=N; i++) if (!BO[i]) CP^=i;
    for (int i : B[AP]) if (!BO[i]) CP^=i;
    for (int i : B[CP]) if (!BO[i]) BP=i;

    vector<int> bst;
    for (int i=1; i<=N; i++) if (!BO[i] && i!=AP && i!=BP && i!=CP) bst.push_back(i);

    int ALF_, AN;
    for (int i=1; i<=N; i++) if (!AO[i] && ADG[i]==1) ALF_=i; MC[AP]=ALF_;
    for (int i : A[ALF_]) if (!AO[i]) AN=i; MC[CP]=AN;
    int APO=0;
    for (int i=1; i<=N; i++) if (!AO[i] && i!=ALF_ && i!=AN) {
        if (!APO && !MA[i*N+AN]) MC[BP]=i, APO=1;
        else MC[bst.back()]=i, bst.pop_back();
    }
}

int APR[202020], BPR[202020];
int ADP[202020], BDP[202020];
void AD(int p, int pre) {for (int i : A[p]) if (i!=pre) APR[i]=p, ADP[i]=ADP[p]+1, AD(i, p);}
void BD(int p, int pre) {for (int i : B[p]) if (i!=pre) BPR[i]=p, BDP[i]=BDP[p]+1, BD(i, p);}

bool ADST2(int a, int b) {return APR[a]==APR[b] || APR[APR[a]]==b || a==APR[APR[b]];}
bool BDST2(int a, int b) {return BPR[a]==BPR[b] || BPR[BPR[a]]==b || a==BPR[BPR[b]];}

bool ADST4(int a, int b) {
    if ((ADP[a]+ADP[b])%2 || abs(ADP[a]-ADP[b])>2) return false;
    int LD=4;
    while (ADP[a]>ADP[b]) a=APR[a], LD--;
    while (ADP[a]<ADP[b]) b=APR[b], LD--;
    if (LD==0 && a==b) return true;
    if (LD==2 && a!=b && APR[a]==APR[b]) return true;
    if (LD==4 && APR[a]!=APR[b] && APR[APR[a]]==APR[APR[b]]) return true;
    return false;
}

bool BDST4(int a, int b) {
    if ((BDP[a]+BDP[b])%2 || abs(BDP[a]-BDP[b])>2) return false;
    int LD=4;
    while (BDP[a]>BDP[b]) a=BPR[a], LD--;
    while (BDP[a]<BDP[b]) b=BPR[b], LD--;
    if (LD==0 && a==b) return true;
    if (LD==2 && a!=b && BPR[a]==BPR[b]) return true;
    if (LD==4 && BPR[a]!=BPR[b] && BPR[BPR[a]]==BPR[BPR[b]]) return true;
    return false;
}

int AFP(int p) {for (int i : A[p]) if (!AO[i]) return i;}
int BFP(int p) {for (int i : B[p]) if (!BO[i]) return i;}

void naive() {
    vector<int> APS;
    for (int i=1; i<=N; i++) if (!AO[i]) APS.push_back(i);
    vector<int> BPS;
    for (int i=1; i<=N; i++) if (!BO[i]) BPS.push_back(i);

    do {
        int fl=0;
        for (int i=0; i<M; i++) for (int j=i+1; j<M; j++)
            if (MA[APS[i]*N+APS[j]] && MB[BPS[i]*N+BPS[j]]) fl=1;
        if (fl) continue;
        for (int i=0; i<M; i++) MC[BPS[i]]=APS[i]; return;
    }while (next_permutation(BPS.begin(), BPS.end()));
    assert(0);
}

vector<array<int, 2>> aed, bed;

signed main(){
    fastio;

    cin >> N; M=N;
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        A[a].push_back(b); A[b].push_back(a);
        MA[a*N+b]=MA[b*N+a]=1;
        aed.push_back({a, b});
    }
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        B[a].push_back(b); B[b].push_back(a);
        MB[a*N+b]=MB[b*N+a]=1;
        bed.push_back({a, b});
    }

    AD(1, 0); BD(1, 0);

    for (int i=1; i<=N; i++) {
        if (A[i].size()==N-1 || B[i].size()==N-1) {
            cout << -1;
            return 0;
        }
        if (A[i].size()==1) ALF.insert({AFP(i), i}); ADG[i]=A[i].size(); ARC[ADG[i]]++;
        if (B[i].size()==1) BLF.insert({BFP(i), i}); BDG[i]=B[i].size(); BRC[BDG[i]]++;
    }

    while (!ARC[M-2] && !BRC[M-2] && M>5) {
        set<array<int, 2>>::iterator Ait1=ALF.begin();
        set<array<int, 2>>::iterator Ait2=prev(ALF.end());
        if (ADST4((*Ait1)[1], (*Ait2)[1])) {
            Ait1=next(Ait1);
            if ((*Ait1)[0]==(*Ait2)[0]) Ait1=prev(Ait1), Ait2=prev(Ait2);
        }
        int AP1=(*Ait1)[1], AP2=(*Ait2)[1];
        ALF.erase(Ait1); ALF.erase(Ait2);

        set<array<int, 2>>::iterator Bit1=BLF.begin();
        set<array<int, 2>>::iterator Bit2=prev(BLF.end());
        if (BDST4((*Bit1)[1], (*Bit2)[1])) {
            Bit1=next(Bit1);
            if ((*Bit1)[0]==(*Bit2)[0]) Bit1=prev(Bit1), Bit2=prev(Bit2);
        }
        int BP1=(*Bit1)[1], BP2=(*Bit2)[1];
        BLF.erase(Bit1); BLF.erase(Bit2);

        ARC[1]-=2; BRC[1]-=2;
        AO[AP1]=AO[AP2]=1; BO[BP1]=BO[BP2]=1; M-=2;
        int AR1=AFP(AP1); ARC[ADG[AR1]]--; ADG[AR1]--; ARC[ADG[AR1]]++;
        if (ADG[AR1]==1) ALF.insert({AFP(AR1), AR1});
        int AR2=AFP(AP2); ARC[ADG[AR2]]--; ADG[AR2]--; ARC[ADG[AR2]]++;
        if (ADG[AR2]==1) ALF.insert({AFP(AR2), AR2});
        int BR1=BFP(BP1); BRC[BDG[BR1]]--; BDG[BR1]--; BRC[BDG[BR1]]++;
        if (BDG[BR1]==1) BLF.insert({BFP(BR1), BR1});
        int BR2=BFP(BP2); BRC[BDG[BR2]]--; BDG[BR2]--; BRC[BDG[BR2]]++;
        if (BDG[BR2]==1) BLF.insert({BFP(BR2), BR2});
        pp.push_back({AR1, AP1, AR2, AP2, BR1, BP1, BR2, BP2});
    }

    if (ARC[M-2]) smsA();
    else if (BRC[M-2]) smsB();
    else naive();


    while (pp.size()) {
        array<int, 8> pb=pp.back(); pp.pop_back();
        if (MA[MC[pb[4]]*N+pb[1]] || MA[MC[pb[6]]*N+pb[3]]) swap(pb[5], pb[7]);
        MC[pb[5]]=pb[1]; MC[pb[7]]=pb[3];
    }

    for (int i=1; i<=N; i++) cout << MC[i] << " ";

    return 0;
}
