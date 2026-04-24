#include <stdio.h>
int n, k, arr[250087]={}, sortarr[5088]={};

int bsort(int find, int hi){
    int lo=0;
    while(lo<=hi){
        int mi=(lo+hi)/2;
        if(sortarr[mi]<find) lo=mi+1;
        else hi=mi-1;
    }
    return lo;
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<k; i++) sortarr[i]=arr[i];
    for(int i=0; i<k; i++){
        for(int j=0; j<i; j++){
            if(sortarr[i]<sortarr[j]){
                int t=sortarr[i];
                sortarr[i]=sortarr[j];
                sortarr[j]=t;
            }
        }
    }
    long long int sum=sortarr[(k-1)/2];
    for(int i=k; i<n; i++){
        for(int j=bsort(arr[i-k], k-1); j<k; j++) sortarr[j]=sortarr[j+1]; sortarr[k-1]=65536;
        
        int x=bsort(arr[i], k-1);
        for(int j=k; j>=x; j--) sortarr[j+1]=sortarr[j];
        sortarr[x]=arr[i];
        //for(int j=0; j<k; j++) printf("%d ", sortarr[j]);
        //printf("\n");
        sum+=sortarr[(k-1)/2];
    }
    printf("%lld", sum);
    return 0;
}
