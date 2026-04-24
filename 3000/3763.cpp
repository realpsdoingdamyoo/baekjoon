#include <bits/stdc++.h>
using namespace std;
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

int su[20][20];
vector<int> C[1024];
node head;
node H[1025];
map<int, node> N[4096];

signed main(){
    fastio;

    for(int i=0; i<16; i++){
        string p; cin >> p;
        for(int j=0; j<16; j++){
            if(p[j]=='-') su[i][j]=0;
            else su[i][j]=p[j]-'A'+1;
        }
    }

    for(int i=0; i<16; i++) for(int j=0; j<16; j++) for(int k=0; k<16; k++){
        if(su[i][j] && su[i][j]!=k+1) continue;
        int row=i*256+j*16+k;
        int col1=i*16+j;
        int col2=256+i*16+k;
        int col3=512+j*16+k;
        int col4=768+(i/4*4+j/4)*16+k;

        N[row][col1].R=&N[row][col2]; N[row][col1].L=&N[row][col4]; N[row][col1].col=&H[col1]; N[row][col1].row=row;
        N[row][col2].R=&N[row][col3]; N[row][col2].L=&N[row][col1]; N[row][col2].col=&H[col2]; N[row][col2].row=row;
        N[row][col3].R=&N[row][col4]; N[row][col3].L=&N[row][col2]; N[row][col3].col=&H[col3]; N[row][col3].row=row;
        N[row][col4].R=&N[row][col1]; N[row][col4].L=&N[row][col3]; N[row][col4].col=&H[col4]; N[row][col4].row=row;
        C[col1].push_back(row); H[col1].siz++;
        C[col2].push_back(row); H[col2].siz++;
        C[col3].push_back(row); H[col3].siz++;
        C[col4].push_back(row); H[col4].siz++;
    }

    for(int i=0; i<1024; i++){
        for(int j=0; j<C[i].size()-1; j++){
            N[C[i][j]][i].D=&N[C[i][j+1]][i];
            N[C[i][j+1]][i].U=&N[C[i][j]][i];
        }
        N[C[i][0]][i].U=&H[i]; H[i].D=&N[C[i][0]][i];
        N[C[i].back()][i].D=&H[i]; H[i].U=&N[C[i].back()][i];
    }

    for(int i=0; i<1025; i++){
        H[i].R=&H[(i+1)%1025]; H[(i+1)%1025].L=&H[i];
    }

    vector<int> ret;
    solve(&H[1024], 0, ret);
    sort(ret.begin(), ret.end());
    for(int i : ret){
        int x=i/256, y=i%256/16, z=i%16;
        if(su[x][y]==0) su[x][y]=z+1;
    }

    for(int i=0; i<16; i++){
        for(int j=0; j<16; j++) cout << (char)(su[i][j]+'A'-1);
        cout << "\n";
    }

    return 0;
}
