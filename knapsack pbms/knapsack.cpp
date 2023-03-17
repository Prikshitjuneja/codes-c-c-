#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[102][102];

int knapsack(int wt[],int val[],int capacity,int n)
{
    if(n==0||capacity==0)
    return 0;

    if(dp[n][capacity]!=-1)
    return dp[n][capacity];

    if(wt[n-1]>capacity)
    return dp[n][capacity]=knapsack(wt,val,capacity,n-1);

    else 
    {
        return dp[n][capacity] = max(val[n-1]+knapsack(wt,val,capacity-wt[n-1],n-1),knapsack(wt,val,capacity,n-1));
    }
    


}

int main()
{
   int n=3;
   int wt[3]={10,20,30};
   int val[3]={60,100,120};
   int capacity=50;

   memset(dp,-1,102*102);


   cout<<knapsack(wt,val,capacity,n)<<endl;

   return 0;


}