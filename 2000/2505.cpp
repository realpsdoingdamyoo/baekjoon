#include <iostream>
#include <iostream>
using namespace std;
void reverse(int array[], int left, int right)
{
    if(left < right)
    {
        swap(array[left],array[right]);
        reverse(array,left+1,right-1);
    }
}
int main()
{
    int n;
    int array[10001] = {0};
    int temp[10001] = {0};
    int left = -1,right = -1;
    int ResultLeft[2];
    int ResultRight[2];
    int count = 0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>array[i];
        temp[i] = array[i];
    }

    for(int i=1; i<=n; i++)
    {
        //위치와 다른숫자의 시작 경우
        if(array[i] != i && left == -1)
        {
            left = i;
            ResultLeft[count] = i;
            continue;
        }
        else if(array[i] == left)
        {
            right = i;
            ResultRight[count] = i;
            count++;
            reverse(array,left,right);

            left = -1;
            right = -1;
            i = 1;
        }
    }

    if(count > 2)
    {
        count = 0;
        for(int i=n; i>0; i--)
        {
            //위치와 다른숫자의 시작 경우
            if(temp[i] != i && right == -1)
            {
                right = i;
                ResultRight[count] = i;
                continue;
            }
            else if(temp[i] == right)
            {
                left = i;
                ResultLeft[count] = i;
                count++;
                reverse(temp,left,right);

                right = -1;
                i = n;
            }
        }
    }
    if(count == 2)
    {
        cout<<ResultLeft[0]<<" "<<ResultRight[0]<<"\n";
        cout<<ResultLeft[1]<<" "<<ResultRight[1]<<"\n";
    }
    else if(count == 1)
    {
        cout<<ResultLeft[0]<<" "<<ResultRight[0]<<"\n";
        cout<<1<<" "<<1<<"\n";
    }

    else if(count == 0)
    {
        cout<<1<<" "<<1<<"\n";
        cout<<1<<" "<<1<<"\n";
    }

    return 0;
}
