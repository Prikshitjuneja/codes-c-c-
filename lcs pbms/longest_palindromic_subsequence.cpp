#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int length_longest_comm_subs(string s1,string s2,int m,int n)
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
    string s1;
    cout<<"STRING ??"<<endl;
    cin>>s1;
    string s2="";
    for(int i=s1.length()-1;i>=0;i--)
    s2+=s1[i];
    //length of longest palindromic subsequence will be length of longest common sbsequence of string and its palindrome
    cout<<"length of longets palindromic subsequence will be :"<<length_longest_comm_subs(s1,s2,s1.length(),s2.length())<<endl;


}
