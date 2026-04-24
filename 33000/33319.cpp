#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int inv(int a){
    int ret=1, x=mod-2;
    while(x){
        if(x&1) ret=ret*a%mod;
        a=a*a%mod; x>>=1;
    }
    return ret;
}

array<int, 4> v[4242424];
array<int, 2> nj[2121212];

array<signed, 2> roadwork(string s){
    s+=(s.back()=='B'?"AB":"BA");
    int n=s.length();
    v[0]={0, 1, 1, 1};
    for(int i=1, j; i<s.length(); i++){
        v[i]={0, 1, 1, 1};

        if(s[i]==s[i-1]) continue;

        int pmx=0, sum=0, c=0, d=0;
        j=i-1;
        while(j>=0 && s[j]!=s[i]){
            v[i][2]+=v[j][0];
            v[i][3]=v[i][3]*v[j][1]%mod;

            v[i][0]+=v[j][0];
            v[i][1]=v[i][1]*v[j][1]%mod;

            pmx=max(pmx, v[j][2]-v[j][0]);
            nj[c]={v[j][1], v[j][1]};
            c++;
            j--;
        }
        for(int k=1; k<c; k++)
            nj[k][0]=nj[k][0]*nj[k-1][0]%mod;
        for(int k=c-2; k>=0; k--)
            nj[k][1]=nj[k][1]*nj[k+1][1]%mod;


        int p=v[i][1];
        if(pmx>0) v[i][1]=0;
        j=i-1;
        while(j>=0 && s[j]!=s[i]){
            if(v[j][2]-v[j][0]==pmx){
                int L=(d==0)?1:nj[d-1][0];
                int R=(d==c-1)?1:nj[d+1][1];

                v[i][1]+=L*R%mod*v[j][3]%mod;
            }
            j--; d++;
        }
        v[i][0]+=pmx; v[i][1]%=mod;
    }

    return {v[n-1][0], v[n-1][1]};
}
