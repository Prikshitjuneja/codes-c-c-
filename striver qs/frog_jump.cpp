#include<bits/stdc++.h>
using namespace std;
int dp[50];
int min_cost(int index,int *arr )
{
    if(index==0)
    return 0;

    if(dp[index]!=-1)
    return dp[index];

    int left=min_cost(index-1,arr)+abs(arr[index]-arr[index-1]);
    int right=INT_MAX;
    if(index>1)
    right=min_cost(index-2,arr)+abs(arr[index]-arr[index-2]);

    return  dp[index]=min(left,right);
}
int main()
{
    int n;
    cin>>n;
    int height_array[n];
    for(int i=0;i<n;i++)
    cin>>height_array[i];
    
    memset(dp,-1,50);

    cout<<min_cost(n-1,height_array)<<endl;

}