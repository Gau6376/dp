#include<bits/stdc++.h>
using namespace std;
// largest divisible subset =  a[i]%a[j]==0 || a[j]%a[i]==0 
// same as lis 42 but if condition is changes

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    int last_idx=0,maxi=1;
    vector<int>dp(n,1),hash(n);
    sort(nums.begin(),nums.end());    // changes
    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int prev=0;prev<i;prev++){
            if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){     // changes
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
    return temp; 
}

int main(){
int n;cin>>n;
vector<int>nums(n);
for(int i=0;i<n;i++) cin>>nums[i];
}