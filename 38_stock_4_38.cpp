#include<bits/stdc++.h>
using namespace std;

// if buy = 1 then u can buy else sell
// same as 37 problem

int f(int ind,int tranNo,vector<int> &prices,int k,vector<vector<int>> &dp){
    int n = prices.size();
    if(ind==n || tranNo==2*k) return 0;

    if(dp[ind][tranNo]!=-1) return dp[ind][tranNo];

    if(tranNo%2==0) 
    return dp[ind][tranNo]=max(-prices[ind]+f(ind+1,tranNo+1,prices,k,dp),f(ind+1,tranNo,prices,k,dp));

    return dp[ind][tranNo]=max(prices[ind]+f(ind+1,tranNo+1,prices,k,dp),f(ind+1,tranNo,prices,k,dp));
}

// int maxProfit(int k, vector<int>& prices) {
//     int n = prices.size();
//     vector<vector<int>> dp(n,vector<int>(2*k,-1));
//     return f(0,0,prices,k,dp);
// }

// tabulation
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int tranNo = 2*k-1;tranNo>=0;tranNo--){
            if(tranNo%2==0) 
            dp[ind][tranNo]=max(-prices[ind]+dp[ind+1][tranNo+1],dp[ind+1][tranNo]);
            else
            dp[ind][tranNo]=max(-prices[ind]+dp[ind+1][tranNo+1],dp[ind+1][tranNo]);
        }
    }
    return dp[0][0];
}

// best
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<int> after(2*k+1,0),cur(2*k+1,0);
    for(int ind=n-1;ind>=0;ind--){
        for(int tranNo = 2*k-1;tranNo>=0;tranNo--){
            if(tranNo%2==0) 
            cur[tranNo]=max(-prices[ind]+after[tranNo+1],after[tranNo]);
            else
            cur[tranNo]=max(prices[ind]+after[tranNo+1],after[tranNo]);
        }
        after=cur;
    }
    return after[0];
}

// int maxProfit(vector<int>& prices,int k) {
//     int n = prices.size();
//     vector<vector<long>> after(2,vector<long>(k+1,0));
//     vector<vector<long>> cur(2,vector<long>(k+1,0));

//     for(int ind = n-1;ind>=0;ind--){
//         for(int buy=0;buy<=1;buy++){
//             for(int cap=1;cap<=k;cap++){
//            long long profit=0;

//            if(buy){
//            int take = -prices[ind] + after[0][cap];
//            int nottake = 0 + after[1][cap];
//            profit = max(take,nottake);
//            }
//            else{
//            int take = +prices[ind] + after[1][cap-1];
//            int nottake = 0 + after[0][cap];
//            profit = max(take,nottake);
//            }

//            cur[buy][cap] = profit;
//             }
//         }
//         after=cur;
//     }
//     return after[1][k]; 
// }

// at max k transitions
int main(){
int n,k;
cin>>n>>k;    
vector<int> prices(n);
for(int i=0;i<n;i++) cin>>prices[i];
// cout<<maxProfit(prices,k)<<endl;
}