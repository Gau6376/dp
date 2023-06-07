#include<bits/stdc++.h>
using namespace std;

int f(int ind,int prev_ind,vector<int>& nums,vector<vector<int>> &dp){
    int n = nums.size();
    if(ind==n) return 0;
    if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];

    int len = 0+f(ind+1,prev_ind,nums,dp); // nottake
    if(prev_ind==-1 || nums[ind]>nums[prev_ind])
    len = max(len,1+f(ind+1,ind,nums,dp));  // take

    return dp[ind][prev_ind+1]=len; 
}

int lengthOfLIS(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return f(0,-1,nums,dp);
}

// tabulation
int lengthOfLIS(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
            int len = 0+dp[ind+1][prev_ind+1]; // nottake
            if(prev_ind==-1 || nums[ind]>nums[prev_ind])
            len = max(len,1+dp[ind+1][ind+1]);  // take
            dp[ind][prev_ind+1]=len;
        }
    }
    return dp[0][-1+1];
}

// best
int lengthOfLIS(vector<int>& nums){
    int n = nums.size();
    vector<int> next(n+1,0),cur(n+1,0);
    for(int ind=n-1;ind>=0;ind--){
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
            int len = 0+next[prev_ind+1]; // nottake
            if(prev_ind==-1 || nums[ind]>nums[prev_ind])
            len = max(len,1+next[ind+1]);  // take
            cur[prev_ind+1]=len;
        }
        next = cur;
    }
    return next[-1+1];
}


int main(){
int n;cin>>n;    
vector<int>nums(n);
for(int i=0;i<n;i++) cin>>nums[i];
cout<<lengthOfLIS(nums)<<endl;
}