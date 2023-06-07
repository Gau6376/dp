#include<bits/stdc++.h>
using namespace std;

int f(int i ,int j ,vector<int> &cuts,vector<vector<int>> &dp){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini = INT_MAX;
    for(int ind=i;ind<=j;ind++){
        int cost = (cuts[j+1]-cuts[i-1]) + f(i,ind-1,cuts,dp) + f(ind+1,j,cuts,dp);
        mini = min(mini,cost);
    }
    return dp[i][j]=mini;
}

int minCost(int n, vector<int>& cuts){
    int m = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
    sort(cuts.begin(),cuts.end());
    return f(1,m,cuts,dp);
}

// tabulation
int minCost(int n, vector<int>& cuts){
    int m = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    vector<vector<int>> dp(m+2,vector<int>(m+2,0));
    for(int i=m;i>=1;i--){
        for(int j=1;j<=m;j++){
            if(i>j) continue;
            int mini = INT_MAX;
            for(int ind=i;ind<=j;ind++){
            int cost = (cuts[j+1]-cuts[i-1]) + dp[i][ind-1] + dp[ind+1][j];
            mini = min(mini,cost);
           } 
           dp[i][j]=mini;
        }
    }
    return dp[1][m];
}


int main(){
    int n,m;cin>>n>>m;
    vector<int> cuts(m);
    for(auto i : cuts) cin>>i;
    cout<<minCost(n,cuts)<<endl;
}