#include<bits/stdc++.h>
using namespace std;

int f(int amount,vector<vector<int>> &dp,vector<int> &coins, int ind){
    if(ind==0) return (amount%coins[0]==0);
    if(dp[ind][amount]!=-1) return dp[ind][amount];
    int nottake = f(amount,dp,coins,ind-1);
    int take=0;
    if(amount>=coins[ind]) take = f(amount-coins[ind],dp,coins,ind);
    return dp[ind][amount] = take+nottake;
}

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    return f(amount,dp,coins,n-1);
}

int main(){
int n;
cin>>n;
vector<int> coins(n);
for(int i=0;i<n;i++) cin>>coins[i];
int amount;
cin>>amount;
// cout<<change(amount,coins)<<endl;

// tabulation
// vector<vector<int>>dp(n,vector<int>(amount+1,-1));
// for(int t=0;t<=amount;t++) dp[0][t]=(t%coins[0]==0); 
// for(int ind=1;ind<n;ind++){
//     for(int t=0;t<=amount;t++){
//         int nottake=dp[ind-1][t];
//         int take=0;
//         if(coins[ind]<=t) take= dp[ind][t-coins[ind]];
//         dp[ind][t]=take+nottake;
//     }
// }
// cout<<dp[n-1][amount]<<endl;

// best
vector<int> prev(amount+1,-1),cur(amount+1,-1);
for(int t=0;t<=amount;t++) prev[t]=(t%coins[0]==0); 
for(int ind=1;ind<n;ind++){
    for(int t=0;t<=amount;t++){
        int nottake=prev[t];
        int take=0;
        if(coins[ind]<=t) take= cur[t-coins[ind]];
        cur[t]=take+nottake;
    }
    prev=cur;
}
cout<<prev[amount]<<endl;
}