#include<bits/stdc++.h>
using namespace std;

int f(int ind,int sum,int arr[],vector<vector<int>> &dp){
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

    return dp[ind][sum]= pick+notpick;
}

int perfectSum(int arr[], int n, int sum){
    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
    return f(n-1,sum,arr,dp);
}

int main(){
int n,sum;
cin>>n>>sum;
int arr[n];
for(int i=0;i<n;i++)
cin>>arr[i];
// cout<<perfectSum(arr,n,sum)<<endl;

// tabulation
vector<vector<int>>dp(n,vector<int>(sum+1,-1));
for(int i=0;i<n;i++) dp[i][0]=1;
if(arr[0]<=sum) dp[0][arr[0]]=1;
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


// best
// int findWays(vector<int> &num, int k){
//     int n = num.size();
//     vector<int> prev(k+1,0);    
//     prev[0] =1;   
//     if(num[0]<=k)
//         prev[num[0]] = 1;   
//     for(int ind = 1; ind<n; ind++){
//         vector<int> cur(k+1,0);
//         cur[0]=1;
//         for(int target= 1; target<=k; target++){           
//             int notTaken = prev[target];   
//             int taken = 0;
//                 if(num[ind]<=target)
//                     taken = prev[target-num[ind]];       
//             cur[target]= notTaken + taken;
//         }       
//         prev = cur;
//     }   
//     return prev[k];   
// }