#include<bits/stdc++.h>
using namespace std;

int f(int n,vector<int>&dp){
    if(n<=2) return n;
    /* if(n>1)
    // f(n-1,dp);
    // if(n>2)    // recursion
    // f(n-2,dp); */
    if(dp[n]!=-1)
    return dp[n];
    return dp[n]=f(n-1,dp)+f(n-2,dp);
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<f(n,dp)<<endl;

    // dp[0]=1;
    // dp[1]=1;
    // for(int i=2;i<=n;i++){
    //     dp[i]=dp[i-1]+dp[i-2];
    // }
    // cout<<dp[n]<<endl;
}