// dp on subsequence
#include<bits/stdc++.h>
using namespace std;

bool f(int ind,int target,vector<int>&arr,vector<vector<int>> &dp){
    if(target==0) return true;
    if(ind==0) return (arr[0]==target);

    if(dp[ind][target]!=-1) return dp[ind][target];

    bool nottake = f(ind-1,target,arr,dp);
    bool take = false;
    if(arr[ind]<=target) take = f(ind-1,target-arr[ind],arr,dp);

    return dp[ind][target]= take | nottake;
}

bool isSubsetSum(vector<int>arr, int sum){
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
    return f(n-1,sum,arr,dp);
}

int main(){
int n,target;
cin>>n>>target;
vector<int> arr(n);
for(int i=0;i<n;i++)
cin>>arr[i];
// cout<<isSubsetSum(arr,target)<<endl;

// tabulation
// vector<vector<int>> dp(n+1,vector<int>(target+1,0));
// for(int i=0;i<n;i++) dp[i][0] = true;
// dp[0][arr[0]] = true;
// for(int ind=1;ind<n;ind++){
//     for(int tar=1;tar<=target;tar++){
//     bool nottake = dp[ind-1][tar];
//     bool take = false;
//     if(arr[ind]<=target) take = dp[ind-1][tar-arr[ind]];

//     dp[ind][tar]= take | nottake;
//     }
// }
// cout<<dp[n-1][target]<<endl; 

// best
vector<bool> prev(target+1,0),curr(target+1,0);
prev[0]=curr[0]=true;
prev[arr[0]] = true;
for(int i=1;i<n;i++){
    for(int j=1;j<=target;j++){
    bool nottake = prev[j];
    bool take = false;
    if(arr[i]<=target) take = prev[j-arr[i]];

    curr[j]= take | nottake;
    }
    prev=curr;
}
cout<<prev[target]<<endl;
}