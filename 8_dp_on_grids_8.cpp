// 2d matrix
#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,vector<vector<int>> &dp){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up = f(i-1,j,dp);
    int left = f(i,j-1,dp);
    return dp[i][j] = left+up;
}

int NumberOfPath(int a, int b)
{
    vector<vector<int>> dp(a,vector<int>(b,-1));
    return f(a-1,b-1,dp);
}

int main(){
    int n,m;
    cin>>n>>m;
    // cout<<NumberOfPath(n,m)<<endl;

    // tabulation
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(i==0 && j==0) dp[i][j]=1;
    //       else {
    //         int up=0,left=0;
    //         if(i>0) up = dp[i-1][j];
    //         if(j>0) left = dp[i][j-1];
    //         dp[i][j] = left+up;}
    //     }
    // }
    // cout<<dp[n-1][m-1]<<endl;

    // best
    vector<int>prev(m,0);
    for(int i=0;i<n;i++){
    vector<int>curr(m,0);
        for(int j=0;j<m;j++){
            if(i==0 && j==0) curr[j]=1;
          else {int up=0,left=0;
            if(i>0) up = prev[j];
            if(j>0) left = curr[j-1];
            curr[j] = left+up;}
        }
    prev=curr;
    }
    cout<<prev[m-1]<<endl;
}