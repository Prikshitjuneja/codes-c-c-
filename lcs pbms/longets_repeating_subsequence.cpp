#include<bits/stdc++.h>
using namespace std;
int length_long_repeat_subs(string s1,string s2,int m,int n)
{
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
            dp[i][j]=0;
            else if(s1[i-1]==s2[j-1]&&i!=j)
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int main()
{
    
    string s1;
    cout<<" STRING??"<<endl;
    cin>>s1;
    int m=s1.length();
    /*
    s1=aacbb
    s2=aacbb
    firstly single character from string removes and after that add those characters which are same but at diff
    index.like 'c' do not come and a at 0 index in s1 match with index !=0 in s2 and a is included.
    
    */
    cout<<length_long_repeat_subs(s1,s1,m,m)<<endl;

}