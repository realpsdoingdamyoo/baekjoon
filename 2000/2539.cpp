#include <stdio.h>

int x, y, paper, wrong, gxi, gyi, xi[1000001], maxyi=0;
int tocover[1000001]={0}, paperi=1;

int isok(int size){
	//printf("\n\n%d\n", size);

	for(int i=0; i<1000001; i++) tocover[i]=xi[i];
    paperi=1;
	for(int i=0; i<paper; i++){
		for(int j=paperi; j<=x; j++){
			if(j<=x && tocover[j]==1){
				paperi=j;
				goto next;
			}
		}
		return 1;

		next:
		for(int j=paperi; j<paperi+size; j++){
			if(j<=x) tocover[j]=0;
		}
		//for(int j=1; j<=x; j++) printf("%d ", tocover[j]);
		//printf("\n");
	}
	int finalsum=0;
	for(int i=1; i<=x; i++) finalsum+=tocover[i];
	if(finalsum==0) return 1;
	else return 0;
}

int isanswer(int size){
	if(isok(size)==1 && isok(size-1)==0) return 1;
	return 0;
}

int binarysearch(){
    int low=maxyi, high=(x>y)?x:y;
    while(low<=high){
        int mid=(low+high)/2;
        if(isok(mid)) high=mid-1;
        else low=mid+1;
    }
    return low;
}

int main() {
	int ap;
	scanf("%d %d %d %d", &y, &x, &paper, &wrong);
	for(int i=0; i<wrong; i++){
		scanf("%d %d", &gyi, &gxi);
		if(maxyi<gyi) maxyi=gyi;
		xi[gxi]=1;
	}



	printf("%d", binarysearch());

	return 0;
}
