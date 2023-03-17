#include<iostream>
using namespace std;
int number_ways_coin_change(int *coin,int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=sum;i++)
    dp[0][i]=0;
    for(int i=0;i<=n;i++)
    dp[i][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(coin[i-1]<=j)
            dp[i][j]=dp[i][j-coin[i-1]]+dp[i-1][j];
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
    int coin[]={2,5,3,6};
    int n=sizeof(coin)/sizeof(coin[0]);

    cout<<"NO> OF WAYS ARE : "<<number_ways_coin_change(coin,n,sum)<<endl;
}