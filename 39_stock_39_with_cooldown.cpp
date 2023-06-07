#include<bits/stdc++.h>
using namespace std;
// buy and sell unlimited time
// cooldown = can't buy just after sell
// almost same as 36 problem but +1 change in sell case

int f(int ind,int buy,vector<int>& prices,vector<vector<int>> &dp){
int n = prices.size(); 
if(ind>=n) return 0;
if(dp[ind][buy]!=-1) return dp[ind][buy];
if(buy) return dp[ind][buy]=max(-prices[ind]+f(ind+1,0,prices,dp),f(ind+1,1,prices,dp));
// if ind = n-1 so base case changes
return dp[ind][buy]=max(prices[ind]+f(ind+2,1,prices,dp),f(ind+1,0,prices,dp));
}

// int maxProfit(vector<int>& prices) {
//     int n = prices.size();
//     vector<vector<int>> dp(n,vector<int>(2,-1));
//     return f(0,1,prices,dp);
// }

// tabulation 
// int maxProfit(vector<int>& prices) {
//     int n = prices.size();
//     vector<vector<int>> dp(n+2,vector<int>(2,0));
//     for(int ind = n-1;ind>=0;ind--){
//         dp[ind][1]=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
//         dp[ind][0]=max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
//     }
//     return dp[0][1];
// }

// tabu = same
// int maxProfit(vector<int>& prices) {
//     int n = prices.size();
//     vector<vector<int>> dp(n+2,vector<int>(2,0));
//     for(int ind = n-1;ind>=0;ind--){
//         for(int buy=0;buy<=1;buy++){
//           if(buy) dp[ind][buy]=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
//           else dp[ind][buy]=max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
//         }
//     }
//     return dp[0][1];
// }

// best
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int>f1(2,0),f2(2,0),cur(2,0);
    for(int ind = n-1;ind>=0;ind--){
        cur[1]=max(-prices[ind]+f1[0],f1[1]);
        cur[0]=max(prices[ind]+f2[1],f1[0]);
        f2=f1;
        f1=cur;
    }
    return cur[1];
}

int main(){
int n;
cin>>n;
vector<int>prices(n);
for(int i=0;i<n;i++) cin>>prices[i];
cout<<maxProfit(prices)<<endl;
}