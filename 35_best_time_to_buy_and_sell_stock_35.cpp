#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int mini = prices[0];
    int ans=0;
    for(int i=1;i<n;i++){
        int cost = prices[i] - mini;
        ans = max(ans,cost);
        mini = min(mini,prices[i]);
    }
    return ans;
}

// one transitions
int main(){
int n;cin>>n;
vector<int> prices(n);
for(int i=0;i<n;i++) cin>>prices[i];
cout<<maxProfit(prices)<<endl;
}