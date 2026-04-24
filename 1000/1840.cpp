#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

struct node{
    int row, siz;
    node *col, *U, *D, *L, *R;
};

void cover(node *c){
    c->R->L=c->L;
    c->L->R=c->R;
    for(node* it=c->D; it!=c; it=it->D){
        for(node *jt=it->R; jt!=it; jt=jt->R){
            jt->D->U=jt->U;
            jt->U->D=jt->D;
            jt->col->siz--;
        }

    }
}

void uncover(node *c){
    for(node *it=c->U; it!=c; it=it->U){
        for(node *jt=it->L; jt!=it; jt=jt->L){
            jt->D->U=jt;
            jt->U->D=jt;
            jt->col->siz++;
        }
    }
    c->R->L=c;
    c->L->R=c;
}

bool solve(node* head, int k, vector<int>& solution){
    if(head->R==head) return true;
    node *p=nullptr;
    int low=inf;

    for(node *it=head->R; it!=head; it=it->R){
        if(it->siz<low){
            if(it->siz==0) return 0;
            low=it->siz; p=it;
        }
    }

    cover(p);

    for(node *it=p->D; it!=p; it=it->D){
        solution.push_back(it->row);
        for(node *jt=it->R; jt!=it; jt=jt->R){
            cover(jt->col);
        }
        if(solve(head, k+1, solution)) return true;
        else{
            solution.pop_back();
            for(node *jt=it->L; jt!=it; jt=jt->L){
                uncover(jt->col);
            }
        }
    }

    uncover(p);
    return false;
}

vector<int> C[324];
node head;
node H[325];
node N[729][324];

void Clear(){
    for(int i=0; i<324; i++) C[i].clear();
    for(int i=0; i<325; i++) H[i].siz=0;
}

bool solve_sudoku(vector<vector<int>> su){
    for(int i=0; i<9; i++) for(int j=0; j<9; j++) for(int k=0; k<9; k++){
        if(su[i][j] && su[i][j]!=k+1) continue;
        int row=i*81+j*9+k;
        int col1=i*9+j;
        int col2=81+i*9+k;
        int col3=162+j*9+k;
        int col4=243+(i/3*3+j/3)*9+k;

        N[row][col1].R=&N[row][col2]; N[row][col1].L=&N[row][col4]; N[row][col1].col=&H[col1]; N[row][col1].row=row;
        N[row][col2].R=&N[row][col3]; N[row][col2].L=&N[row][col1]; N[row][col2].col=&H[col2]; N[row][col2].row=row;
        N[row][col3].R=&N[row][col4]; N[row][col3].L=&N[row][col2]; N[row][col3].col=&H[col3]; N[row][col3].row=row;
        N[row][col4].R=&N[row][col1]; N[row][col4].L=&N[row][col3]; N[row][col4].col=&H[col4]; N[row][col4].row=row;
        C[col1].push_back(row); H[col1].siz++;
        C[col2].push_back(row); H[col2].siz++;
        C[col3].push_back(row); H[col3].siz++;
        C[col4].push_back(row); H[col4].siz++;
    }

    for(int i=0; i<324; i++){
        if(C[i].size()==0){Clear(); return false;}
        for(int j=0; j<(int)C[i].size()-1; j++){
            N[C[i][j]][i].D=&N[C[i][j+1]][i];
            N[C[i][j+1]][i].U=&N[C[i][j]][i];
        }
        N[C[i][0]][i].U=&H[i]; H[i].D=&N[C[i][0]][i];
        N[C[i].back()][i].D=&H[i]; H[i].U=&N[C[i].back()][i];
    }

    for(int i=0; i<325; i++){
        H[i].R=&H[(i+1)%325]; H[(i+1)%325].L=&H[i];
    }

    vector<int> Ret;
    bool ret=solve(&H[324], 0, Ret);

    Clear();
    return ret;
}

signed main(){
    fastio;

    vector<vector<int>> su(9, vector<int>(9, 0));
    for(int i=0; i<81; i++){
        int a, b, c; cin >> a >> b >> c;
        if(su[a-1][b-1]){
            cout << i+1 << "\n"; return 0;
        }
        su[a-1][b-1]=c;
        if(!solve_sudoku(su)){
            cout << i+1 << "\n"; return 0;
        }
    }
    cout << "-1\n";

    return 0;
}
