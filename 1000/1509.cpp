#include <stdio.h>
#include <string.h>
#define ll long long int

int ispal[2500][2500], maxpal[2500];
char str[2501];

int main() {
	scanf("%s", str);
	int n=strlen(str);
	for(int i=0; i<n; i++)  ispal[i][i]=1;
	for(int i=0; i<n-1; i++) if(str[i]==str[i+1]) ispal[i][i+1]=1;
	for(int l=2; l<n; l++){
		for(int i=0; i<n-2; i++){
			if(str[i]==str[i+l]) ispal[i][i+l]=ispal[i+1][i+l-1];
		}
	}
	maxpal[0]=1;
	for(int i=0; i<n; i++){
		if(ispal[0][i]==1) {maxpal[i]=1; continue;}
		maxpal[i]=maxpal[i-1]+1;
		for(int j=i-1; j>0; j--){
			if(ispal[j][i]){
				if(maxpal[j-1]+1<maxpal[i]) maxpal[i]=maxpal[j-1]+1;
			}
		}
	}
	printf("%d", maxpal[n-1]);
	return 0;
}
