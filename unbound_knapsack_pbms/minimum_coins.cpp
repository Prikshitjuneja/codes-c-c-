#include<iostream>
#include<climits>
using namespace std;
int minimum_coins(int *coin,int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=1;i<=n;i++)
    dp[i][0]=0;
    for(int i=0;i<=sum;i++)
    dp[0][i]=INT_MAX-1;

    for(int i=1,j=1;j<=sum;j++)
    {
        if(j%coin[0]==0)
        dp[i][j]=j/coin[0];
        else
        dp[i][j]=INT_MAX-1;
    }

    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(coin[i-1]<=j)
            dp[i][j]=min(1+dp[i][j-coin[i-1]],dp[i-1][j]);

            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main()
{
    int sum;
    cout<<"SUM??"<<endl;
    cin>>sum;
    int coin[]={9,6,5,1};
    int n=sizeof(coin)/sizeof(coin[0]);

    cout<<"MIN NO> OF COINS ARE:"<<minimum_coins(coin,n,sum)<<endl;

}