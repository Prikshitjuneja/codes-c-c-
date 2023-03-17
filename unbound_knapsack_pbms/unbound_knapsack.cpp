#include<iostream>
#include<algorithm>
using namespace std;
int unbound_knapsack(int *wt,int*val,int n,int capacity)
{
    int dp[n+1][capacity+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=capacity;j++)
        {
            if(i==0||j==0)
            dp[i][j]=0;
            else if(wt[i-1]<=capacity)
            dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][capacity];
}
int main()
{
    int n;
    cout<<"SIZE??"<<endl;
    cin>>n;
    int wt[n];
    int val[n];
    cout<<"WT.ARRAY??"<<endl;
    for(int i=0;i<n;i++)
    cin>>wt[i];
    cout<<"VALUE ARRAY??"<<endl;
    for(int i=0;i<n;i++)
    cin>>val[i];
    int capacity;
    cout<<"CAPACITY OF KNAPSACK??"<<endl;
    cin>>capacity;

    cout<<unbound_knapsack(wt,val,n,capacity)<<endl;
    
}