#include<bits/stdc++.h>
using namespace std;

int f(int ind,int W,int wt[],int val[],vector<vector<int>> &dp){
if(ind==0){
    if(wt[0]<=W) return val[0];
    else return 0;
}

if(dp[ind][W]!=-1) return dp[ind][W];

int nottake=0+f(ind-1,W,wt,val,dp);
int take=INT_MIN;
if(wt[ind]<=W) take=val[ind]+f(ind-1,W-wt[ind],wt,val,dp);

return dp[ind][W]=max(take,nottake);
}

int knapSack(int W, int wt[], int val[], int n) { 
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return f(n-1,W,wt,val,dp);
}

int main(){
    int n,w;
    cin>>n>>w;
    int val[n],wt[n];
    for(int i=0;i<n;i++)
    cin>>val[i];
    for(int i=0;i<n;i++)
    cin>>wt[i];
    // cout<<knapSack(w,wt,val,n)<<endl; 

    // tabulation
    // vector<vector<int>> dp(n,vector<int>(w+1,0));
    // for(int i=wt[0]; i<=w; i++){
    //     dp[0][i] = val[0];
    // }
    
    // for(int ind =1; ind<n; ind++){
    //     for(int cap=0; cap<=w; cap++){         
    //         int notTaken = 0 + dp[ind-1][cap];       
    //         int taken = INT_MIN;
    //         if(wt[ind] <= cap)
    //         taken = val[ind] + dp[ind-1][cap - wt[ind]];          
    //         dp[ind][cap] = max(notTaken, taken);
    //     }
    // }  
    // cout<<dp[n-1][w]<<endl;

    // best
    vector<int>prev(w+1),curr(w+1,0);
    for(int i=wt[0]; i<=w; i++){
        prev[i] = val[0];
    }
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=w; cap++){         
            int notTaken = 0 + prev[cap];       
            int taken = INT_MIN;
            if(wt[ind] <= cap)
            taken = val[ind] + prev[cap - wt[ind]];          
            curr[cap] = max(notTaken, taken);
        }
        prev=curr;
    }  
    cout<<prev[w]<<endl;
}