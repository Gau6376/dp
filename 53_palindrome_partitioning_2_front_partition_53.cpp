#include<bits/stdc++.h>
using namespace std;

bool ispalindrom(int i,int j,string s){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;j--;
    }
    return true;
}

int f(int i,int n,string &s,vector<int> &dp){
// may give tle
if(i==n) return 0;
if(dp[i]!=-1) return dp[i];
int mincost=INT_MAX;
// i......j  = string
for(int j=i;j<n;j++){
if(ispalindrom(i,j,s)){
    int cost = 1+f(j+1,n,s,dp);
    mincost=min(mincost,cost);
}
}
return dp[i]=mincost;
}

int minCut(string s) {
    int n = s.size();
    vector<int> dp(n,-1);
    return f(0,n,s,dp)-1;
}

// tabulation
int minCut(string s) {
    int n = s.size();
    vector<int> dp(n+1,0);
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
    int mincost=INT_MAX;
    for(int j=i;j<n;j++){
    if(ispalindrom(i,j,s)){
    int cost = 1+dp[j+1];
    mincost=min(mincost,cost);
   }
  }
   dp[i]=mincost;
}
return dp[0]-1;
}

int main(){
string s;cin>>s;
cout<<minCut(s)<<endl;
}