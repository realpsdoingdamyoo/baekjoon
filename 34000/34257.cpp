#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int q, ans, C;

struct Node{
    int cnt=0;
    int dsm=0;
    Node *L=nullptr, *R=nullptr;
};
Node *tree=new Node;

map<int, int> mp;

void update(int p, int d){
    int X=0;
    while((1LL<<X+1)<=p) X++; X--;

    int cnt=((1LL<<d+1)-1)%mod;
    int dsm=((d-1)*(1LL<<d+1)+2)%mod;
    dsm=(dsm+cnt*(X+1))%mod;
    C+=cnt; int CC=0;

    int td=(1LL<<d+1)%mod;
    int tp=(td*td%mod*(d-2)+(d+4)*td)%mod;
    ans=(ans+tp)%mod;

    Node* x=tree;
    for(int i=X; i>=0; i--){
        x->cnt=(x->cnt+cnt)%mod;
        x->dsm=(x->dsm+dsm)%mod;

        if(!x->L) x->L=new Node;
        if(!x->R) x->R=new Node;

        if(p&(1LL<<i)){
            tp=0;
            CC+=x->L->cnt;
            tp+=x->L->dsm*cnt%mod;
            tp+=x->L->cnt*dsm%mod;
            tp+=x->L->cnt*cnt%mod;
            ans=(ans+tp)%mod;
        }
        else{
            tp=0;
            CC+=x->R->cnt;
            tp+=x->R->dsm*cnt%mod;
            tp+=x->R->cnt*dsm%mod;
            tp+=x->R->cnt*cnt%mod;
            ans=(ans+tp)%mod;
        }

        if(mp.find(p>>i+1)!=mp.end()){
            int D=mp[p>>i+1];
            int Cnt=((1LL<<D+1)-1)%mod;
            int Dsm=((D-3)*(1LL<<D+1)+2*D+6)%mod;

            tp=0;
            CC+=Cnt;
            tp+=(Dsm*cnt)%mod;
            tp+=(Cnt*dsm)%mod;
            ans=(ans+tp)%mod;
        }

        x=(p&1LL<<i)?x->R:x->L;
        dsm=(dsm-cnt+mod)%mod;
    }

    int Cnt=((1LL<<d+1)-1)%mod;
    int Dsm=((d-3)*(1LL<<d+1)+2*d+6)%mod;

    tp=0;
    CC+=x->cnt+Cnt;
    tp+=(x->cnt*Dsm)%mod;
    tp+=(x->dsm*Cnt)%mod;
    ans=(ans+tp)%mod;

    x->cnt=(x->cnt+cnt)%mod;
    x->dsm=(x->dsm+dsm)%mod;
}

signed main(){
	fastio;

	cin >> q;
	while(q--){
        int p, d; cin >> p >> d;
        mp[p]=d;
        update(p, d);
        cout << ans << "\n";
	}

    return 0;
}
