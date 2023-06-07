#include<bits/stdc++.h>
using namespace std;

int f(vector<int>&dp,int n,vector<int>&a,int k){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int ans=INT_MAX;             // o(n*k)
    for(int i=1;i<=k;i++){
        if(n-i>=0){
        int jump = f(dp, n-i, a, k) + abs(a[n] - a[n-i]);
        ans = min(ans,jump);
        }
    }
    return dp[n]=ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>dp(n+1,-1);
    vector<int>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<f(dp,n-1,a,k)<<endl;

    // dp[0]=0;
    // for(int i=1;i<n;i++){
    //     int ans=INT_MAX;             // o(n*k)
    //     for(int j=1;j<=k;j++){
    //     if(i-j>=0){
    //     int jump = dp[i-j] + abs(a[i] - a[i-j]);
    //     ans = min(ans,jump);
    //     }
    //   }
    //   dp[i]=ans;
    // }
    // cout<<dp[n-1]<<endl;
}