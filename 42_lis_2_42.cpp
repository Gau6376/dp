#include<bits/stdc++.h>
using namespace std;

// same = 41 but another approach

// int lengthOfLIS(vector<int>& nums){
//     int n = nums.size();
//     vector<int>dp(n,1);
//     for(int i=0;i<n;i++){
//         for(int prev=0;prev<i;prev++){
//             if(nums[prev]<nums[i])
//             dp[i]=max(dp[i],1+dp[prev]);
//         }
//     }
//     return *max_element(dp.begin(),dp.end()); 
// }

// also print lis
int lengthOfLIS(vector<int>& nums){
    int n = nums.size();
    int last_idx=0,maxi=1;
    vector<int>dp(n,1),hash(n);
    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int prev=0;prev<i;prev++){
            if(nums[prev]<nums[i] && 1+dp[prev]>dp[i]){
            dp[i]=1+dp[prev];
            hash[i]=prev;
           }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            last_idx=i;
        }
    } 
    vector<int>temp;
    temp.push_back(nums[last_idx]);
    while(hash[last_idx]!=last_idx){
        last_idx=hash[last_idx];
        temp.push_back(nums[last_idx]);
    }
    reverse(temp.begin(),temp.end());
    for(auto i : temp) cout<<i<<" ";
    cout<<endl;
    return maxi;
}

int main(){
int n;cin>>n;    
vector<int>nums(n);
for(int i=0;i<n;i++) cin>>nums[i];
cout<<lengthOfLIS(nums)<<endl;
}