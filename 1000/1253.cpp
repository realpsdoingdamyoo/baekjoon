#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    int nums[n];
    int count=0, one=0, two=n-1;
    
    for (int i=0 ; i<n ; i++) {
        scanf("%d", &nums[i]);
    }
    
    for (int i=0 ; i<n ; i++) {
        for (int j=i+1 ; j<n ; j++) {
            if (nums[i]>nums[j]) {
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
        }
    }
    
    for (int i=0 ; i<n ; i++) {
        one=0;
        two=n-1;
        while (one<two) {
            if(one==i) { one++; continue; } 
            if(two==i) { two--; continue; }
            
            if (nums[one]+nums[two] < nums[i]) one++;
            else if (nums[one]+nums[two] > nums[i]) two--;
            else { count++; break; }
        }
    }
	printf("%d", count);
}
