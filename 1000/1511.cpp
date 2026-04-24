#include <stdio.h>
#define ll long long int
int main(){
    ll nums[10]={}, allsum=0;
    for(int i=0; i<10; i++){
        scanf("%d", &nums[i]);
        allsum+=nums[i];
    }
    for(int i=0; i<10; i++){
        if(allsum<nums[i]*2){
            nums[i]=allsum-nums[i]+(i!=0); allsum=0;
            for(int j=0; j<10; j++) allsum+=nums[j];
            break;
        }
    }
    //for(int i=0; i<10; i++) printf("%d_", nums[i]);
    //printf("\n");
    ll frontnum=408;
    for(int i=allsum; i>0; i--){
        ll maxx=0, maxwitch;
        for(int j=0; j<10; j++){
            if(maxx<nums[j]){maxx=nums[j]; maxwitch=j;}
            //printf("%d ", nums[j]);
        }
        if(maxx*2-1>=allsum){
            printf("%d", maxwitch);
            nums[maxwitch]--;
            frontnum=maxwitch;
        }
        else{
            for(int j=9; j>=0; j--){
                if(nums[j] && frontnum!=j){
                    printf("%d", j);
                    frontnum=j;
                    nums[j]--;
                    break;
                }
            }
        }
        //printf("{%d %d}\n", maxx, allsum);
        allsum--;
    }
    if(frontnum==408) printf("0");

    return 0;
}
