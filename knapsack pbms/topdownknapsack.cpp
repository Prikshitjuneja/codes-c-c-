#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int knapsack(int *wt,int *val,int W,int n)
{
    int dp[n+1][W+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0||j==0)    //initialisation part
            dp[i][j]=0;

            else if(wt[i-1]<=W)
            dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);  //if curr elemnt < knapasack

            else
            dp[i][j]=dp[i-1][j];  //if curr element > knapsack
        }
    }
    return dp[n][W];
}
int main()
{
    int n=3;
   int wt[3]={10,20,30};
   int val[3]={60,100,120};
   int capacity=50;

   cout<<knapsack(wt,val,capacity,n)<<endl;



}