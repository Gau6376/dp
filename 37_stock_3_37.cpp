#include<bits/stdc++.h>
using namespace std;

// if buy = 1 then u can buy else sell

// int f(int ind,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>> &dp){
// int n = prices.size(); 

// if(ind==n || cap==0) return 0;
// long long profit=0;

// if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];

// if(buy){
// int take = -prices[ind] + f(ind+1,0,cap,prices,dp);
// int nottake = 0 + f(ind+1,1,cap,prices,dp);
// profit = max(take,nottake);
// }
// else{
// int take = +prices[ind] + f(ind+1,1,cap-1,prices,dp);
// int nottake = 0 + f(ind+1,0,cap,prices,dp);
// profit = max(take,nottake);
// }

// return dp[ind][buy][cap] = profit;
// }

// int maxProfit(vector<int>& prices) {
//     int n = prices.size();
//     vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
//     return f(0,1,2,prices,dp);
// }
 
// tabulation 
// int maxProfit(vector<int>& prices) {
//     int n = prices.size();
//     vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
//     // we do not write base case here bcoz dp is filled with 0

//     for(int ind = n-1;ind>=0;ind--){
//         for(int buy=0;buy<=1;buy++){
//            for(int cap=1;cap<=2;cap++){
//             long long profit=0;

//             if(buy){
//            int take = -prices[ind] + dp[ind+1][0][cap];
//             int nottake = 0 + dp[ind+1][1][cap];
//             profit = max(take,nottake);
//             }
//             else{
//             int take = +prices[ind] + dp[ind+1][1][cap-1];
//             int nottake = 0 + dp[ind+1][0][cap];
//             profit = max(take,nottake);
//             }

//             dp[ind][buy][cap] = profit;
//             }
//          }
//      }
//     return dp[0][1][2]; // (0 = index , 1 = buy , 2 = cap) intial
// }

// best
// int maxProfit(vector<int>& prices) {
//     int n = prices.size();
//     vector<vector<long>> after(2,vector<long>(3,0));
//     vector<vector<long>> cur(2,vector<long>(3,0));

//     for(int ind = n-1;ind>=0;ind--){
//         for(int buy=0;buy<=1;buy++){
//             for(int cap=1;cap<=2;cap++){
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
//     return after[1][2]; 
// }


// B S B S    
// 0 1 2 3   = tarnsition number

// int f(int ind,int tarnsition){      // dp[n][4]  // if(tarnsition%2==1) = sell else buy
//     if(ind==n || tarnsition==4) return 0;
//     if(tarnsition%2==0){
//         profit = max(-prices[ind]+f(ind+1,tarnsition+1),f(ind+1,tarnsition));
//     }
//     else{
//         profit = max(prices[ind]+f(ind+1,tarnsition+1),f(ind+1,tarnsition));
//     }
// }

// at max 2 transitions
int main(){
int n;
cin>>n;    
vector<int> prices(n);
for(int i=0;i<n;i++) cin>>prices[i];
// cout<<maxProfit(prices)<<endl;
}