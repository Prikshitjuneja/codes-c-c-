#include<bits/stdc++.h>
using namespace std;
int static dp[1001][1001];
long int min_no_multiplication(int *arr,int i,int j)
{
      if(i>=j)
      return 0;

      if(dp[i][j]!=-1)
      return dp[i][j];

long int ans=INT_MAX;
      for(int k=i;k<=j-1;k++)
      {
        long int tempans=min_no_multiplication(arr,i,k)+min_no_multiplication(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        ans=min(ans,tempans);
      }
      return dp[i][j]=ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    memset(dp,-1,1001*1001);

    cout<<min_no_multiplication(arr,1,n-1);




}