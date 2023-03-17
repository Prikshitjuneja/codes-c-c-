#include<bits/stdc++.h>
using namespace std;
unordered_map<string,bool>mp;
bool is_scrambled(string s1,string s2)
{
    //base condition
    if(s1.compare(s2)==0)//if both strings are same
    return true;
    if(s1.length()<=1)//if we divide string such that one part is empty
    return false;

    string key=s1;
    key.push_back(' ');
    key.append(s2);

    if(mp.find(key)!=mp.end())
    return mp[key];

bool flag=false;
int n=s1.length();
   
    for(int i=1;i<=n-1;i++)//i starts from 1 as empty string not allowed.if i=0 then left part is empty
    {
         //condition 1->swapping allowed
      bool condition1=is_scrambled(s1.substr(0,i),s2.substr(n-i,i))&&is_scrambled(s1.substr(i,n-i),s2.substr(0,n-i));
        
        //condition 2->swapping not allowed
      bool condition2=is_scrambled(s1.substr(0,i),s2.substr(0,i))&&is_scrambled(s1.substr(i,n-i),s2.substr(i,n-i));

      if(condition1||condition2)//if one of the condition is true then string is scrambled
      {
        flag=true;
        break;
      }
        
    }
    return mp[key]=flag;
}
int main()
{
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
     mp.clear();

    if(s1.length()!=s2.length())
    cout<<"false"<<endl;
    else if(s1.length()==0&&s2.length()==0)
    cout<<"true"<<endl;
   else
    {
        if(is_scrambled(s1,s2))
        cout<<"true"<<endl;
        else
        cout<<"false"<<endl;
    }

}