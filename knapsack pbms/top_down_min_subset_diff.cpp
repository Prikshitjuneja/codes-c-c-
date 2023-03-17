#include<iostream>
#include<vector>
using namespace std;
int subsetfirst(int*arr,int sum,int n)
{
    bool dp[n+1][sum+1];
    for(int i=0;i<=sum;i++)
    dp[0][i]=false;
    for(int i=0;i<=n;i++)
    dp[i][0]=true;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(arr[i-1]<=j)
            dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    vector<int>result;
    for(int j=0;j<=sum/2;j++)
    {
        if(dp[n][j]==true)
        result.push_back(j);
    }
    int size=result.size();
    int s1=result.at(size-1);
    return s1;
}
int main()
{
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

    int s1=subsetfirst(arr,sum,n);
    cout<< sum-2*s1<<endl;
}