#include<iostream>
using namespace std;

int rod_cutting(int *length,int*price,int length_rod,int size)
{
   int dp[size+1][length_rod+1];
   for(int i=0;i<=size;i++)
   {
    for(int j=0;j<=length_rod;j++)
    {
        if(i==0||j==0)
        dp[i][j]=0;

        else if(length[i-1]<=j)
        dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);

        else
        dp[i][j]=dp[i-1][j];
    }
   }
   return dp[size][length_rod];
}
int main()
{
    
    int length_rod=8;
    int length[]={1,2,3,4,5,6,7,8};
    int price[]={3,5,8,9,10,17,17,20};
    int size=sizeof(length)/sizeof(length[0]);

    cout<<"MAX PROFIT:"<<rod_cutting(length,price,length_rod,size)<<endl;


}