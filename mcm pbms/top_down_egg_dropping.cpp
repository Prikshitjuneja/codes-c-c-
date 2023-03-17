#include<bits/stdc++.h>
using namespace std;
int count_min_trials(int n,int k)
{
   int dp[n+1][k+1];
   for(int i=1;i<=n;i++)
   {
    // if k==0 and k==1
    dp[i][0]=0;
    dp[i][1]=1;
   }

   for(int j=1;j<=k;j++)
   dp[1][j]=j;//if egg=1

   for(int i=2;i<=n;i++)
   {
    for(int j=2;j<=k;j++)
    {
       dp[i][j]=INT_MAX;
       for(int a=1;a<=j;a++)
       {
        int temp=1+max(dp[i-1][a-1],dp[i][j-a]);
        dp[i][j]=min(dp[i][j],temp);
       }

    }
   }
   return dp[n][k];
}
int main()
{
    int k,n;
    cin>>n>>k;

    cout<<"MIN NO OF TRIALS : "<<count_min_trials(n,k)<<endl;
}