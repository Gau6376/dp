#include<bits/stdc++.h>
using namespace std;

int f(int ind,int W,int val[],int wt[],vector<vector<int>> &dp){
    if(ind==0){
        return ((int)(W/wt[0]))*val[0];
    }
    if(dp[ind][W]!=-1) return dp[ind][W];
    int nottake = 0+f(ind-1,W,val,wt,dp);
    int take=0;
    if(wt[ind]<=W) take = val[ind]+f(ind,W-wt[ind],val,wt,dp);
    return dp[ind][W]=max(take,nottake);
}

int knapSack(int N, int W, int val[], int wt[]){
    vector<vector<int>> dp(N,vector<int>(W+1,-1));
    return f(N-1,W,val,wt,dp);
}

int main(){
    int N,W;
    cin>>N>>W;
    int val[N],wt[N];
    for(int i=0;i<N;i++) cin>>val[i];
    for(int i=0;i<N;i++) cin>>wt[i];
    // cout<<knapSack(N-1,W,val,wt)<<endl;

    // tabulation
    vector<vector<int>> dp(N,vector<int>(W+1,0));
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = ((int) i/wt[0]) * val[0];
    }  
    for(int ind =1; ind<N; ind++){
        for(int cap=0; cap<=W; cap++){           
          int notTaken = 0 + dp[ind-1][cap];         
          int taken = INT_MIN;
          if(wt[ind] <= cap) taken = val[ind] + dp[ind][cap - wt[ind]];   
          dp[ind][cap] = max(notTaken, taken);
        }
    } 
    cout<<dp[N-1][W]<<endl;

    // not best
    vector<int>prev(W+1,0),cur(W+1,0);
    for(int i=wt[0]; i<=W; i++){
        prev[i] = ((int) i/wt[0]) * val[0];
    }  
    for(int ind =1; ind<N; ind++){
        for(int cap=0; cap<=W; cap++){           
          int notTaken = 0 + prev[cap];         
          int taken = INT_MIN;
          if(wt[ind] <= cap) taken = val[ind] + cur[cap - wt[ind]];   
          cur[cap] = max(notTaken, taken);
        }
        prev=cur;
    } 
    cout<<prev[W]<<endl;

    // best
    vector<int>prev(W+1,0);
    for(int i=wt[0]; i<=W; i++){
        prev[i] = ((int) i/wt[0]) * val[0];
    }  
    for(int ind =1; ind<N; ind++){
        for(int cap=0; cap<=W; cap++){           
          int notTaken = 0 + prev[cap];         
          int taken = INT_MIN;
          if(wt[ind] <= cap) taken = val[ind] + prev[cap - wt[ind]];   
          prev[cap] = max(notTaken, taken);
        }
    } 
    cout<<prev[W]<<endl;
}