#include <stdio.h>
int main(){
    int N, M;
    scanf("%d", &N);
    int price[N], min = 50, idx;
    for (int i = 0; i < N; i++){
        scanf("%d", &price[i]);
        if (min >= price[i]){
            min = price[i];
            idx = i;
        }
    }
    scanf("%d", &M);
	
    int size = M/min;
    char num[51] = {0,};
    for (int i = 0; i < size; i++)
        num[i] = idx + '0';
    M %= min, idx = 0;
	
    for (int i = 0; i < size; i++){
        for (int j = N-1; j >= 0; j--)
            if (price[j] - min <= M){
                num[i] = j + '0';
                M -= (price[j]-min);
                break;
            }
			
        if (num[idx] == '0'){
            M += min;
            idx++;
        }
    }
    puts(idx == size ? "0" : num + idx);
}
