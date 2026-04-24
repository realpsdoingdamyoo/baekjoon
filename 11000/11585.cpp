#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int gcd(int a, int b){return b?gcd(a, b%a):a;}

vi getpi(string p){
    int m=p.length(), j=0;
    vi pi(m);
    for(int i=1; i<m; i++){
        while(j>0 && p[i]!=p[j]) j=pi[j-1];
        if(p[i]==p[j]) pi[i]=++j;
    }
    return pi;
}

int main() {
    string p;
    getline(cin, p); getline(cin, p); p+=' ';
    int n=p.length();
    vi pi=getpi(p);
    int bunja=n%(n-pi[n-1])?1:n/(n-pi[n-1]);
    cout << bunja/gcd(bunja, n/2) << "/" << n/2/gcd(bunja, n/2);
    getline(cin, p);
    return 0;
}
