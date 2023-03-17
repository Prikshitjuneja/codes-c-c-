#include<iostream>
using namespace std;
bool is_present(int *arr,int sum,int n)
{
    bool dp[n+1][sum+1];

    //initialisation
    for(int i=0;i<=sum;i++)
    dp[0][i]=false;

    for(int i=0;i<=n;i++)
    dp[i][0]=true;
    
    //filling the dp array
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            //here i indicates size of array and j indicates current sum
            if(arr[i-1]<=j)//curr elemnt <=sum
            {
                //element include ||element not included
                dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
            }
            //curr element>sum.

            if(arr[i-1]>sum)
            {
                dp[i][j]=dp[i-1][j];
            }
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
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int sum;
    cout<<"SUM??"<<endl;
    cin>>sum;

    if(is_present(arr,sum,n))
    cout<<"PRESENT!!"<<endl;
    else
    cout<<"NOT PRESENT!!"<<endl;


}