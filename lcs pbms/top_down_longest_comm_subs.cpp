#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int longest_comm_subs(string first,string second,int m,int n)
{
    int dp[m+1][n+1];
    for(int i=0;i<=n;i++)
    dp[0][i]=0;
    for(int i=0;i<=m;i++)
    dp[i][0]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
          
          if(first[i-1]==second[j-1])
            dp[i][j]=1+dp[i-1][j-1];

            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
        }
    }
    //for printing subs
    int index=dp[m][n];
    char result[index+1];
    result[index]='\0';

    int i=m;
    int j=n;
    while(i>0&&j>0)
    {
        if(first[i-1]==second[j-1])
        {
            result[index-1]=first[i-1];
            i--;
            j--;
            index--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        i--;
        else
        j--;
    }

    cout<<result;
   
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

    cout<<" of length :"<<longest_comm_subs(first,second,length_first,length_second)<<" is the longest comm subsequence .."<<endl;
}