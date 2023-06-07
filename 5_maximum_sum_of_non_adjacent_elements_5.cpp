#include<bits/stdc++.h>
using namespace std;

int f(vector<int>&dp,int ind,vector<int>&a){
   if(ind==0) return a[ind];             // o(n) 
   if(ind<0) return 0; 
   if(dp[ind]!=-1) return dp[ind];
   int pick = a[ind] + f(dp,ind-2,a);
   int notpick = 0 + f(dp,ind-1,a);
   return dp[ind] = max(pick,notpick);
}

int ans(vector<int>&a){
    int n = a.size();
    vector<int>dp(n+1,-1);
    return f(dp,n-1,a);
}

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<ans(a)<<endl;

    // tabulation
    // vector<int>dp(n+1,-1);
    // dp[0]=a[0];
    // int neg = 0;
    // for(int i=1;i<n;i++){
    //     int take = a[i]; if(i>1) take+=dp[i-2];
    //     int nottake = 0 + dp[i-1];

    //     dp[i] = max(take,nottake);
    // }
    // cout<<dp[n-1]<<endl;

    //best
    int prev=a[0];
    int prev2 = 0;
    for(int i=1;i<n;i++){
        int take = a[i]; if(i>1) take+=prev2;      //  o(n) , o(1)
        int nottake = 0 + prev;

        int curri = max(take,nottake);
        prev2 = prev;
        prev = curri;
    }
    cout<<prev<<endl;
}