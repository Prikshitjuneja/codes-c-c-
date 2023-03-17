#include<bits/stdc++.h>
using namespace std;
int dp[101][101][2];
int count_true(string s,int i,int j,bool is_true)
{
    //base case
    if(i>j)
    return false;
    if(i==j)
    {
        if(is_true==true)
        return s[i]=='T';//checking if single block contains true or not
        else
        return s[i]=='F';//checking if single block contains false or not
    }
    //check in table
    if (dp[i][j][is_true] != -1)
        return dp[i][j][is_true];

     int ans=0;
    for(int k=i+1;k<=j-1;k+=2)
    {
       int lt,rt,lf,rf;
       //operator always present at k
       //seaching for number of true in left part i.e. i to k-1
       if(dp[i][k-1][true]!=-1)
       lt=dp[i][k-1][true];
       else
       lt=count_true(s,i,k-1,true);
       
       //seaching for number of true in right part i.e. k+1 to j
       if(dp[k+1][j][true]!=-1)
       rt=dp[k+1][j][true];
       else
       rt=count_true(s,k+1,j,true);
       
       //seaching for number of false in left part i.e. i to k-1
       if(dp[i][k-1][false]!=-1)
       lf=dp[i][k-1][false];
       else
       lf=count_true(s,i,k-1,false);

       //seaching for number of false in right part i.e. k+1 to j
       if(dp[k+1][j][false]!=-1)
       rf=dp[k+1][j][false];
       else
       rf=count_true(s,k+1,j,false);

       //handling operators
       //expression1 operator expression 2
       if(s[k]=='&')
       {
           if(is_true==true)
           ans+=lt*rt;//calculating cases in which we want true from and operator
           else
           ans+=lf*rf+lf*rt+lt*rf;//calculating cases in which we want false from and operator
       }
       if(s[k]=='|')
       {
        if(is_true==true)
        ans+=lt*rt+lt*rf+lf*rt;//calculating cases in which we want true from or operator
        else
        ans+=lf*rf;//calculating cases in which we want false from or operator
       }
       if(s[k]=='^')
       {
        if(is_true==true)
        ans+=lt*rf+lf*rt; //calculating cases in which we want true from xor operator
        else
        ans+=lt*rt+lf*rf;//calculating cases in which we want false from xor operator
       }
        
        dp[i][j][is_true]==ans;//filling answer in dp
       }
    return ans;//return final ans 
}
int main()
{
   string symbols = "TTFT";
    string operators = "|&^";
    string s;
    int j = 0;
 
    for (int i = 0; i < symbols.length(); i++)
    {
        s.push_back(symbols[i]);
        if (j < operators.length())
            s.push_back(operators[j++]);
    }
   memset(dp,-1,sizeof(dp));

   cout<<count_true(s,0,s.size()-1,true)<<endl;
}