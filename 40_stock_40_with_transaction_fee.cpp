#include<bits/stdc++.h>
using namespace std;
// buy and sell unlimited time
// each transaction have some fee

int f(int ind,int buy,vector<int> &prices,vector<vector<int>> &dp,int fee){
int n = prices.size(); 
if(ind>=n) return 0;
if(dp[ind][buy]!=-1) return dp[ind][buy];
if(buy) return dp[ind][buy]=max(-prices[ind]+f(ind+1,0,prices,dp,fee),f(ind+1,1,prices,dp,fee));
return dp[ind][buy]=max(prices[ind]-fee+f(ind+1,1,prices,dp,fee),f(ind+1,0,prices,dp,fee));
}

int maxProfit(vector<int>& prices,int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return f(0,1,prices,dp,fee);
}

int main(){
int n,fee;
cin>>n>>fee;
vector<int>prices(n);
for(int i=0;i<n;i++) cin>>prices[i];
cout<<maxProfit(prices,fee)<<endl;
}