#include<iostream>
using namespace std;
int longest_comm_substring(string first,string second,int m,int n)
{
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
            dp[i][j]=0;

            else if(first[i-1]==second[j-1])
            dp[i][j]=1+dp[i-1][j-1];

            else
            dp[i][j]=0;
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

    cout<<"LENGTH OF LONGEST COMMON SUBSTRING:"<<longest_comm_substring(first,second,length_first,length_second)<<endl;
}