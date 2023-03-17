#include<iostream>
using namespace std;
#include<algorithm>

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
      string first,second;
    cout<<"FIRST STRING??"<<endl;
    cin>>first;
    cout<<"SECOND STRING??"<<endl;
    cin>>second;
    int length_first=first.length();
    int length_second=second.length();

    int len_long_comm_subs=length_longest_comm_subs(first,second,length_first,length_second);
    // we want to convert string s1 to s2
    //we first convert s1 to longest common subs and longest comm sub to s2
    //no. of deletion=length(s1)-length(longest common subsequence)
    //no . of insertion =length(s2)-length(longest common subsequence)

    cout<<"NO. OF DELETION ARE :"<<length_first-len_long_comm_subs<<endl;
    cout<<"NO. OF INSERTION ARE :"<<length_second-len_long_comm_subs<<endl;
}