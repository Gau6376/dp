#include<bits/stdc++.h>
using namespace std;

// if buy = 1 then u can buy else sell

int f(int ind,int buy,vector<int>& prices,vector<vector<int>> &dp){
int n = prices.size(); 

if(ind==n) return 0;
long long profit=0;

if(dp[ind][buy]!=-1) return dp[ind][buy];

if(buy){
int take = -prices[ind] + f(ind+1,0,prices,dp);
int nottake = 0 + f(ind+1,1,prices,dp);
profit = max(take,nottake);
}
else{
int take = +prices[ind] + f(ind+1,1,prices,dp);
int nottake = 0 + f(ind+1,0,prices,dp);
profit = max(take,nottake);
}

return dp[ind][buy] = profit;
}

// int maxProfit(vector<int>& prices) {
//     int n = prices.size();
//     vector<vector<int>> dp(n,vector<int>(2,-1));
//     return f(0,1,prices,dp);
// }
 
// tabulation 
// int maxProfit(vector<int>& prices) {
//     int n = prices.size();
//     vector<vector<int>> dp(n+1,vector<int>(2,0));

//     dp[n][0] = dp[n][1] = 0;

//     for(int ind = n-1;ind>=0;ind--){
//         for(int buy=0;buy<=1;buy++){
//            long long profit=0;

//            if(buy){
//            int take = -prices[ind] + dp[ind+1][0];
//            int nottake = 0 + dp[ind+1][1];
//            profit = max(take,nottake);
//            }
//            else{
//            int take = +prices[ind] + dp[ind+1][1];
//            int nottake = 0 + dp[ind+1][0];
//            profit = max(take,nottake);
//            }

//            dp[ind][buy] = profit;
//         }
//     }
//     return dp[0][1];
// }

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<long> ahead(2,0),cur(2,0);

    ahead[0] = ahead[1] = 0;

    for(int ind = n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
           long long profit=0;

           if(buy){
           int take = -prices[ind] + ahead[0];
           int nottake = 0 + ahead[1];
           profit = max(take,nottake);
           }
           else{
           int take = +prices[ind] + ahead[1];
           int nottake = 0 + ahead[0];
           profit = max(take,nottake);
           }

           cur[buy] = profit;
        }
        ahead=cur;
    }
    return ahead[1]; 
}

// infinite transitions
int main(){
int n;
cin>>n;    
vector<int> prices(n);
for(int i=0;i<n;i++) cin>>prices[i];
cout<<maxProfit(prices)<<endl;
}