#include<iostream>
#include<math.h>
using namespace std;

int count_zeros_till_index(int*arr,int i)
{
    int count=0;
    for(int j=0;j<=i;j++)
    {
        if(arr[j]==0)
        count++;
    }
    return count;
}

int count_subset_target(int *arr,int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=sum;i++)
    dp[0][i]=0;
    for(int i=0;i<=n;i++)
    dp[i][0]=pow(2,count_zeros_till_index(arr,i));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]<=j)
            dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    //pbm is same as s1-s2=diff
    int n;
    cout<<"SIZE??"<<endl;
    cin>>n;
    int sum=0;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    int target;
    cout<<"TARGET??"<<endl;
    cin>>target;

    int s1=(sum+target)/2;
    cout<<count_subset_target(arr,n,s1)<<endl;
}