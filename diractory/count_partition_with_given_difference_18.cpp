#include<bits/stdc++.h>
using namespace std;

  int m=1e9+7;
  int f(int ind,int sum,vector<int>& arr,vector<vector<int>> &dp){
    // if(sum==0) return 1;    // if(a[i]>=1) in array
    if(ind==0){
        if(sum==0 && arr[0]==0) return 2;    // if(arr[i]>=0) in array
        if(sum==0 || sum==arr[0]) return 1;
        return 0;
    }
    if(ind==0) return arr[0]==sum;

    if(dp[ind][sum]!=-1) return dp[ind][sum];

    int notpick = f(ind-1,sum,arr,dp);
    int pick=0;
    if(arr[ind]<=sum) pick = f(ind-1,sum-arr[ind],arr,dp);

    return dp[ind][sum]= (pick+notpick)%m;
}

int perfectSum(vector<int>& arr, int n, int sum){
    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
    return f(n-1,sum,arr,dp);
}

int countPartitions(int n, int d, vector<int>& arr) {
    int totsum=0;
    for(auto &i : arr) totsum+=i;
    if(totsum-d<0 || (totsum-d)&1) return false;
    return perfectSum(arr,arr.size(),(totsum-d)/2);
}

int main(){
int n,d;
cin>>n>>d;
vector<int>arr(n);
int sum=0;
for(int i=0;i<n;i++){
cin>>arr[i];
sum+=arr[i];}
// cout<<countPartitions(n,d,arr)<<endl;

// tabulation
vector<vector<int>>dp(n,vector<int>(sum+1,0));
if(arr[0]==0) dp[0][0]=2;
else dp[0][0]=1;
// arr[0]=0
if(arr[0]!=0 && arr[0]<=sum) dp[0][arr[0]]=1;
for(int i=0;i<n;i++){
    for(int j=0;j<=sum;j++){
    int notpick = dp[i-1][j];
    int pick=0;
    if(arr[i]<=j) pick = dp[i-1][j-arr[i]];

    dp[i][j]= pick+notpick;
    }
}
cout<<dp[n-1][sum]<<endl;
}