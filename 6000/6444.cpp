#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static inline bool is_digit(char ch){return '0'<=ch&&ch<='9';}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<char> alph;
    for(char c='A';c<='Z';c++) alph.push_back(c);

    unordered_map<string,int> dic;
    dic.reserve(20000);

    for(int i=0;i<26;i++) dic[string(1,alph[i])] = i+1;
    for(int i=0;i<26;i++) for(int j=0;j<26;j++){
        string s; s.push_back(alph[i]); s.push_back(alph[j]);
        dic[s] = (i+1)*26 + (j+1);
    }
    for(int i=0;i<26;i++) for(int j=0;j<26;j++) for(int k=0;k<26;k++){
        string s; s.push_back(alph[i]); s.push_back(alph[j]); s.push_back(alph[k]);
        dic[s] = (i+1)*26*26 + (j+1)*26 + (k+1);
    }

    auto transRC = [&](const string& inp)->pair<int,int>{
        int col,row;
        if((int)inp.size()>2 && !is_digit(inp[2])){
            col=dic[inp.substr(0,3)];
            row=stoi(inp.substr(3));
        }else if(!is_digit(inp[1])){
            col=dic[inp.substr(0,2)];
            row=stoi(inp.substr(2));
        }else{
            col=dic[inp.substr(0,1)];
            row=stoi(inp.substr(1));
        }
        return {row,col};
    };

    auto parse_formula = [&](const string& s)->vector<pair<int,int>>{
        vector<pair<int,int>> refs;
        int i=1,n=s.size(),st=1;
        while(i<=n){
            if(i==n || s[i]=='+'){
                refs.push_back(transRC(s.substr(st,i-st)));
                st=i+1;
            }
            i++;
        }
        return refs;
    };

    int tc; 
    cin>>tc;
    while(tc--){
        int Cn,Rn;
        cin>>Cn>>Rn;

        vector<vector<string>> T(Rn+1, vector<string>(Cn+1));
        for(int i=1;i<=Rn;i++) for(int j=1;j<=Cn;j++) cin>>T[i][j];

        vector<vector<ll>> val(Rn+1, vector<ll>(Cn+1,0));
        vector<vector<char>> done(Rn+1, vector<char>(Cn+1,0));

        function<void(int,int)> DFS = [&](int r,int c){
            if(done[r][c]) return;
            const string &cell=T[r][c];
            if(!cell.empty() && cell[0] != '='){
                val[r][c]=stoll(cell);
                done[r][c]=1;
                return;
            }
            ll sum=0;
            auto refs=parse_formula(cell);
            for(auto [rr,cc]:refs){
                if(!done[rr][cc]) DFS(rr,cc);
                sum+=val[rr][cc];
            }
            val[r][c]=sum;
            done[r][c]=1;
        };

        for(int i=1;i<=Rn;i++) for(int j=1;j<=Cn;j++) if(!done[i][j]) DFS(i,j);

        for(int i=1;i<=Rn;i++){
            for(int j=1;j<=Cn;j++){
                cout<<val[i][j]<<(j==Cn?'\n':' ');
            }
        }
    }
    return 0;
}
