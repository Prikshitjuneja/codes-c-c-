#include<iostream>
using namespace std;
bool is_present(int *arr,int n,int sum)
{
     bool dp[n+1][sum+1];

     for(int i=0;i<=sum;i++)
     dp[0][i]=false;

     for(int i=0;i<=n;i++)
     dp[i][0]=true;

     for(int i=1;i<=n;i++)
     {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]<=j)
     dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];

     if(arr[i-1]>sum)
     dp[i][j]=dp[i-1][j];
        }
     }
     return dp[n][sum];

}
int main()
{
     int n;
    cout<<"SIZE??"<<endl;
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }

    if(sum%2!=0)
    cout<<"NOT PRESENT!!"<<endl;

    else{
          if(is_present(arr,n,sum/2))
          cout<<"PRESENT!!"<<endl;
          else
          cout<<"NOT PRESENT!!"<<endl;
    }


}