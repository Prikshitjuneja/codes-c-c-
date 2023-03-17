#include<iostream>
using namespace std;
#include<algorithm>
#include<cstring>
int dp[1001][1001];
int longest_comm_subs(string first,string second,int length_first,int length_second)
{
    //base case
    if(length_first==0||length_second==0)
    return 0;

    if(dp[length_first][length_second]!=-1)
    return dp[length_first][length_second];

    //if last character matches
    if(first[length_first-1]==second[length_second-1])
    return dp[length_first][length_second]= 1+longest_comm_subs(first,second,length_first-1,length_second-1);
    // if last character do not match
    else
    return dp[length_first][length_second]=max(longest_comm_subs(first,second,length_first-1,length_second),longest_comm_subs(first,second,length_first,length_second-1));
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
    memset(dp,-1,1001*1001);

    cout<<"LENGTH OF LONGEST COMMON SUBSEQUENCE : "<<longest_comm_subs(first,second,length_first,length_second)<<endl;

}