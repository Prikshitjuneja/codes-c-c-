#include<bits/stdc++.h>
using namespace std;
int main()
{
     int n;
    cin>>n;
    int height_array[n];
    for(int i=0;i<n;i++)
    cin>>height_array[i];

    //top down dp

    // int dp[n];
    // dp[0]=0;

    // for(int i=1;i<n;i++)
    // {
    //     int left=dp[i-1]+abs(height_array[i]-height_array[i-1]);
    //     int right=INT_MAX;
    //     if(i>1)
    //     right=dp[i-2]+abs(height_array[i]-height_array[i-2]);

    //     dp[i]=min(left,right);
    // }
    // cout<<dp[n-1]<<endl;

    //space optimization
    //here prev1=>dp[i-1]&prev2=>dp[i-2] and final ans is contained in prev
    int prev,prev2,curr;
    prev=prev2=0;

    for(int i=1;i<n;i++)
    {
        int left=prev+abs(height_array[i]-height_array[i-1]);
        int right=INT_MAX;
        if(i>1)
        right=prev2+abs(height_array[i]-height_array[i-2]);

        curr=min(left,right);
        prev2=prev;
        prev=curr;

    }
    cout<<prev<<endl;
}