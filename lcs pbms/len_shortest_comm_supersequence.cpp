#include<iostream>
#include<cstring>
#include <bits/stdc++.h>
using namespace std;
//supersequence is string which contains both string s1 and s2

string long_supersequence(string s1,string s2,int m,int n)
{
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)
            dp[i][j]=j;  //as superseq contains both string 
            else if(j==0)
            dp[i][j]=i;   //as superseq contains both string 
            else if(s1[i-1]==s2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);  //as we will also include different chaarcters
        }
    }
    
    
    string ans;

    int i=m;
    int j=n;
    while(i>0&&j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
             ans.push_back(s1[i-1]);
             i--;
             j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            ans.push_back(s2[j-1]);
            j--;
        }
        else
        {
            ans.push_back(s1[i-1]);
            i--;
        }
    }
    while(i>0)  //for remaining characters of s1
    {
        ans.push_back(s1[i-1]);
        i--;
    }
    while(j>0)      //for remaining characters of s2
    {
        ans.push_back(s2[j-1]);
        j--;
    }
    
    reverse(ans.begin(),ans.end()) ;
    return ans;
}
int main()
{
      string first,second;
    cout<<"FIRST STRING??"<<endl;
    cin>>first;
    cout<<"SECOND STRING??"<<endl;
    cin>>second;
    int length_first=first.length();
    int length_second=second.length();
    //length of shortest supersequence = length(s1)+length(s2)-length of longest common subsequence

    cout<<long_supersequence(first,second,length_first,length_second)<<" IS SMALLEST SUPERSEQUENCE OF LENGTH :"<<long_supersequence(first,second,length_first,length_second).length()<<endl;
}