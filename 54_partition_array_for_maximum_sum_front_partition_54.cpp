#include<bits/stdc++.h>
using namespace std;

int f(int ind,vector<int>& arr, int k,vector<int> &dp){
    int n=arr.size();
    if(ind==n) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int maxsum=INT_MIN,len=0,maxi=INT_MIN;
    for(int j=ind;j<min(n,ind+k);j++){
        len++;
        maxi = max(maxi,arr[j]);
        int sum = len*maxi + f(j+1,arr,k,dp);
        maxsum = max(maxsum,sum);
    }
    return dp[ind]=maxsum;
}

int maxSumAfterPartitioning(vector<int>& arr, int k) {
   int n=arr.size();
   vector<int> dp(n,-1);
   return f(0,arr,k,dp);     
}

// tabulation
int maxSumAfterPartitioning(vector<int>& arr, int k) {
   int n=arr.size();
   vector<int> dp(n+1,0);
   for(int i=n-1;i>=0;i--){
    int maxsum=INT_MIN,len=0,maxi=INT_MIN;
    for(int j=i;j<min(n,i+k);j++){
        len++;
        maxi = max(maxi,arr[j]);
        int sum = len*maxi + dp[j+1];
        maxsum = max(maxsum,sum);
    }
    dp[i]=maxsum;
   } 
   return dp[0];    
}

int main(){
int n,k;cin>>n>>k;
vector<int> arr(n);
for(int i=0;i<n;i++) cin>>arr[i];
cout<<maxSumAfterPartitioning(arr,k)<<endl;
}