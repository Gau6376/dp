#include <bits/stdc++.h>
using namespace std;

int f(int n,vector<int> &dp){   // o(n) // space comp o(n)+o(n)
    if(n<2) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = f(n-1,dp) + f(n-2,dp);
}

int main(){
    int n;
    cin>>n;
    // int dp[n+1];
    // memset(dp,-1,sizeof(dp));

    /* 1.
    vector<int> dp(n+1,-1);
    cout<<f(n,dp)<<endl;
    */

   // best = o(n) and space comp = o(1)
   int prev2=0,prev1=1; 
   for(int i=2;i<=n;i++){
    int curi = prev1 + prev2;
    prev2 = prev1;
    prev1 = curi;
   }
   cout<<prev1<<endl;
}