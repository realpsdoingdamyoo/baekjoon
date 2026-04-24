#include <stdio.h>
#include <string.h>

int num[50][50];

int main() {
	long long int maxx=0;
	int n, m, sum1, sum2, sum3;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &num[i][j]);
        }
	}
	for(int i=1; i<n-1; i++){
        sum1=0;
        for(int j=0; j<i; j++){
            for(int k=0; k<m; k++) sum1+=num[j][k];
        }
        for(int j=i+1; j<n; j++){
            sum2=0; sum3=0;
            for(int k=i; k<j; k++){
                for(int l=0; l<m; l++) sum2+=num[k][l];
            }
            for(int k=j; k<n; k++){
                for(int l=0; l<m; l++) sum3+=num[k][l];
            }
            long long int s=sum1;
            s*=sum2;
            s*=sum3;
            if(s>maxx) maxx=s;
        }
	}
	for(int i=1; i<m-1; i++){
        sum1=0;
        for(int j=0; j<i; j++){
            for(int k=0; k<n; k++) sum1+=num[k][j];
        }
        for(int j=i+1; j<m; j++){
            sum2=0; sum3=0;
            for(int k=i; k<j; k++){
                for(int l=0; l<n; l++) sum2+=num[l][k];
            }
            for(int k=j; k<m; k++){
                for(int l=0; l<n; l++) sum3+=num[l][k];
            }
            long long int s=sum1;
            s*=sum2;
            s*=sum3;
            if(s>maxx) maxx=s;
        }
	}
	for(int i=1; i<n; i++){
        sum1=0;
        for(int j=0; j<i; j++){
            for(int k=0; k<m; k++) sum1+=num[j][k];
        }
        for(int j=1; j<m; j++){
            sum2=0; sum3=0;
            for(int k=0; k<j; k++){
                for(int l=i; l<n; l++) sum2+=num[l][k];
            }

            for(int k=j; k<m; k++){
                for(int l=i; l<n; l++) sum3+=num[l][k];
            }
            long long int s=sum1;
            s*=sum2;
            s*=sum3;
            if(s>maxx) maxx=s;
        }
	}
	for(int i=1; i<n; i++){
        sum1=0;
        for(int j=i; j<n; j++){
            for(int k=0; k<m; k++) sum1+=num[j][k];
        }
        for(int j=1; j<m; j++){
            sum2=0; sum3=0;
            for(int k=0; k<j; k++){
                for(int l=0; l<i; l++) sum2+=num[l][k];
            }

            for(int k=j; k<m; k++){
                for(int l=0; l<i; l++) sum3+=num[l][k];
            }
            long long int s=sum1;
            s*=sum2;
            s*=sum3;
            if(s>maxx) maxx=s;
        }
	}
	for(int i=1; i<m; i++){
        sum1=0;
        for(int j=0; j<i; j++){
            for(int k=0; k<n; k++) sum1+=num[k][j];
        }
        for(int j=1; j<n; j++){
            sum2=0; sum3=0;
            for(int k=0; k<j; k++){
                for(int l=i; l<m; l++) sum2+=num[k][l];
            }

            for(int k=j; k<n; k++){
                for(int l=i; l<m; l++) sum3+=num[k][l];
            }
            long long int s=sum1;
            s*=sum2;
            s*=sum3;
            if(s>maxx) maxx=s;
        }
	}
	for(int i=1; i<m; i++){
        sum1=0;
        for(int j=i; j<m; j++){
            for(int k=0; k<n; k++) sum1+=num[k][j];
        }
        for(int j=1; j<n; j++){
            sum2=0; sum3=0;
            for(int k=0; k<j; k++){
                for(int l=0; l<i; l++) sum2+=num[k][l];
            }

            for(int k=j; k<n; k++){
                for(int l=0; l<i; l++) sum3+=num[k][l];
            }
            long long int s=sum1;
            s*=sum2;
            s*=sum3;

            if(s>maxx) maxx=s;
        }
	}
	printf("%lld", maxx);
	return 0;
}
