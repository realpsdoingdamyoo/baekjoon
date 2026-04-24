#include <stdio.h>
#include <math.h>
int cnt[10]={0};

int logten(int n){
    if(n==1) return 0;
    else return logten(n/10)+1;
}

int top(int n){
    if(n<10) return n;
    else return top(n/10);
}

void plusing(int n, int x, int left){
    for(int i=0; i<10; i++){
        cnt[i]+=(n/10+(n%10>i))*x;
    }
    cnt[n%10]+=left+1;
    cnt[0]-=x;
    if(n<10) return;
    plusing(n/10, x*10, (n%10)*(x/top(x))+left);
}



int main() {
    int n;
    scanf("%d", &n);
    plusing(n, 1, 0);
    for(int i=0; i<10; i++) printf("%d ", cnt[i]);
}
