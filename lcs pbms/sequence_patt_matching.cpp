#include<bits/stdc++.h>
using namespace std;
int len_longest_comm_subs(string s1,string s2,int m,int n)
{
  int dp[m+1][n+1];
  for(int i=0;i<=m;i++)
  {
    for(int j=0;j<=n;j++)
    {
        if(i==0||j==0)
        dp[i][j]=0;

        else if(s1[i-1]==s2[j-1])
        dp[i][j]=1+dp[i-1][j-1];

        else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  return dp[m][n];
}
int main()
{
    //is s1 is present as subsequence in s2
    //if length of lcs = length(s1) then ans=true else false
    string s1;
    cout<<"string1??"<<endl;
    cin>>s1;
    string s2;
    cout<<"string2??"<<endl;
    cin>>s2;
    int lcs_len=len_longest_comm_subs(s1,s2,s1.length(),s2.length());
    if(lcs_len==s1.length())
    cout<<"true";
    else 
    cout<< "false";
}