#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
bool is_palindrome(string s,int i,int j)
{
    while(i<j)
    {
         if(s[i]!=s[j])
        {
            return false;
        }
        i++;
        j--;
    }
  return true;
}
int min_partitions(string s,int i,int j)
{
    if(i>=j)
    return 0;

    if(is_palindrome(s,i,j)==true)
    return 0;

if(dp[i][j]!=-1)
return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int left,right;
        if(dp[i][k]!=-1)
        left=dp[i][k];
        else
        {
            left=min_partitions(s,i,k);
            dp[i][k]=left;
        }
        if(dp[k+1][j]!=-1)
        right=dp[k+1][j];
        else
        {
            right=min_partitions(s,k+1,j);
            dp[k+1][j]=right;
        }

        int temp=left+right+1;
        ans=min(ans,temp);
    }
    return dp[i][j] =ans;
}
int main()
{
    string s;
    cin>>s;
    memset(dp,-1,1001*1001);
    cout<<min_partitions(s,0,s.length()-1);
}