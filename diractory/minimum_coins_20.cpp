#include<bits/stdc++.h>
using namespace std;

int f(int ind,int amount,vector<int>& coins,vector<vector<int>> &dp){
if(ind==0){
    if(amount%coins[ind]==0) return amount/coins[ind];
    else return 1e9;
}
if(dp[ind][amount]!=-1) return dp[ind][amount];
int nottake = 0 + f(ind-1,amount,coins,dp);
int take = 1e9;
if(coins[ind]<=amount) take = 1+f(ind,amount-coins[ind],coins,dp);
return dp[ind][amount] = min(take,nottake);
}

int coinChange(vector<int>& coins, int amount) {
    int n=coins.size();
    vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    int ans=f(n-1,amount,coins,dp);
    if(ans>=1e9) return -1;
    return ans;
}

int main(){
int n,amount;cin>>n>>amount;
vector<int>coins(n);
for(int i=0;i<n;i++)
cin>>coins[i];
// cout<<coinChange(coins,amount)<<endl;

// tabulation
// vector<vector<int>> dp(n,vector<int>(amount+1,0));
// for(int t=0;t<=amount;t++){
//     if(t%coins[0]==0) dp[0][t]=t/coins[0];
//     else dp[0][t]=1e9;
// }

// for(int ind=1;ind<n;ind++){
//     for(int t=0;t<=amount;t++){
//         int nottake = 0 + dp[ind-1][t];
//         int take = 1e9;
//         if(coins[ind]<=t) take = 1+dp[ind][t-coins[ind]];
//         dp[ind][t] = min(take,nottake);
//     }
// }
// int ans=dp[n-1][amount];
// if(ans>=1e9) 
// cout<<-1<<endl;
// else
// cout<<ans<<endl;

//best
vector<int> prev(amount+1,0),cur(amount+1,0);
for(int t=0;t<=amount;t++){
    if(t%coins[0]==0) prev[t]=t/coins[0];
    else prev[t]=1e9;
}

for(int ind=1;ind<n;ind++){
    for(int t=0;t<=amount;t++){
        int nottake = 0 + prev[t];
        int take = 1e9;
        if(coins[ind]<=t) take = 1+cur[t-coins[ind]];
        cur[t] = min(take,nottake);
    }
    prev=cur;
}
int ans=prev[amount];
if(ans>=1e9) 
cout<<-1<<endl;
else
cout<<ans<<endl;
}