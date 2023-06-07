#include<bits/stdc++.h>
using namespace std;

int f(vector<int>&dp,int n,vector<int>&a){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int one = f(dp,n-1,a) + abs(a[n]-a[n-1]);
    int two = INT_MAX;
    if(n>1)
    two = f(dp,n-2,a) + abs(a[n]-a[n-2]);
    return dp[n]=min(one,two);
}

int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    vector<int>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<f(dp,n-1,a)<<endl;

    // dp[0]=0;
    // dp[1] = abs(a[0]-a[1]);
    // for(int i=2;i<n;i++){
    //     int one = dp[i-1] + abs(a[i]-a[i-1]);
    //     int two = dp[i-2] + abs(a[i]-a[i-2]);
    //     dp[i] = min(one,two);
    // }
    // cout<<dp[n-1]<<endl;

    // best
    // int prev=0,prev2=0;
    // for(int i=1;i<n;i++){
    //     int one = prev+ abs(a[i]-a[i-1]);
    //     int two = prev2 + abs(a[i]-a[i-2]);
    //     int  cur = min(one,two);
    //     prev2 = prev;
    //     prev = cur;
    // }
    // cout<<prev<<endl;
}