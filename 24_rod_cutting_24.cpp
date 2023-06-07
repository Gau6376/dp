#include<bits/stdc++.h>
using namespace std;

int f(int ind,int n,int price[],vector<vector<int>> &dp){
    if(ind==0) return n*price[0];
    if(dp[ind][n]!=-1) return dp[ind][n];
    int nottake = 0+f(ind-1,n,price,dp);
    int take = INT_MIN;
    int rodlength = ind+1;
    if(rodlength<=n) take = price[ind]+f(ind,n-rodlength,price,dp);
    return dp[ind][n]=max(take,nottake);
}

int cutRod(int price[], int n) {
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return f(n-1,n,price,dp);
}

int main(){
    int n;
    cin>>n;
    int price[n];
    for(int i=0;i<n;i++) price[i];
    // cout<<cutRod(price,n)<<endl;

    // tabulation
    vector<vector<int>> dp(n,vector<int>(n+1,0));
    for(int i=0;i<=n;i++) dp[0][i] = i*price[0];
    for(int ind=1;ind<n;ind++){
        for(int j=0;j<=n;j++){
            int nottake = 0+dp[ind-1][j];
            int take = INT_MIN;
            int rodlength = ind+1;
            if(rodlength<=j) take = price[ind]+dp[ind][j-rodlength];
            dp[ind][j]=max(take,nottake);
        }
    }
    cout<<dp[n-1][n]<<endl;

    //not best
    vector<int> prev(n+1,0),cur(n+1,0);
    for(int i=0;i<=n;i++) prev[i] = i*price[0];
    for(int ind=1;ind<n;ind++){
        for(int j=0;j<=n;j++){
            int nottake = 0+prev[j];
            int take = INT_MIN;
            int rodlength = ind+1;
            if(rodlength<=j) take = price[ind]+cur[j-rodlength];
            cur[j]=max(take,nottake);
        }
        prev=cur;
    }
    cout<<prev[n]<<endl;

    // best
    vector<int> prev(n+1,0);
    for(int i=0;i<=n;i++) prev[i] = i*price[0];
    for(int ind=1;ind<n;ind++){
        for(int j=0;j<=n;j++){
            int nottake = 0+prev[j];
            int take = INT_MIN;
            int rodlength = ind+1;
            if(rodlength<=j) take = price[ind]+prev[j-rodlength];
            prev[j]=max(take,nottake);
        }
    }
    cout<<prev[n]<<endl;
}