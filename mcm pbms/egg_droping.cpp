#include<bits/stdc++.h>
using namespace std;
int dp[37][10];
//in this question we have to return answer of worst case
int min_trials(int n_floor,int n_egg)
{
    //base case
    //if no.of floor=0 then no trials and if =1 then only we have to take one trial
    if(n_floor==0||n_floor==1)
    return n_floor;

//if n_egg=1 then in worst case it would take n_floor ways as we have to start from bottom
    if(n_egg==1)
    return n_floor;
//floor is treted as vertical array
if(dp[n_floor][n_egg]!=-1)
return dp[n_floor][n_egg];

int ans=INT_MAX;
    for(int i=1;i<=n_floor;i++)
    {
        /*
        here we take max of 2 cases as we have to go for worst case
        1st case: if from ith floor egg breaks then we have to go for remaining down floors which is i-1 and egg reduces by 1
        2nd case: if from ith floor egg do not break we have to go for upfloors which is n_floor-i and n_egg remains same
        */
       int egg_broken,egg_not_broken;

       if(dp[i-1][n_egg-1]!=-1)
       egg_broken=dp[i-1][n_egg-1];
       else
       egg_broken=min_trials(i-1,n_egg-1);

       if(dp[n_floor-i][n_egg]!=-1)
       egg_not_broken=dp[n_floor-i][n_egg];
       else
       egg_not_broken=min_trials(n_floor-i,n_egg);

        int temp=max(egg_broken,egg_not_broken);
        //ans stores minimum from all i's.
        ans=min(ans,temp);
    }
    return dp[n_floor][n_egg]=1+ans;// here 1 is added as before recursion 1 trial has benn taken


}
int main()
{
    int floor,egg;
    cin>>floor>>egg;
    memset(dp,-1,sizeof(dp));
    cout<<"MIN NO> OF TRIALS: "<<min_trials(floor,egg)<<endl;

    


}