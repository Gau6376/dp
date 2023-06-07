#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int m=1003;

// this count number of ways
ll f(int i,int j,int istrue,string &S,vector<vector<vector<ll>>> &dp){
    if(i>j) return 0;
    if(i==j){
        if(istrue) return S[i]=='T';
        else return S[i]=='F';
    }
    if(dp[i][j][istrue]!=-1) return dp[i][j][istrue];
    ll ways = 0;
    for(int ind=i+1;ind<=j-1;ind+=2){
        ll lt = f(i,ind-1,1,S,dp); 
        ll lf = f(i,ind-1,0,S,dp); 
        ll rt = f(ind+1,j,1,S,dp); 
        ll rf = f(ind+1,j,0,S,dp); 

        if(S[ind]=='&'){
            if(istrue) ways = (ways + (rt * lt)%m)%m;
            else ways = (ways + (rt*lf)%m + (rf * lt)%m + (rf * lf)%m)%m;
        }
        else if(S[ind]=='|'){
            if(istrue) ways = (ways + (rt * lt)%m + (lt * rf)%m + (lf*rt)%m)%m;
            else ways = (ways + (rf * lf)%m)%m;
        }
        else{
            // t^t=f , t^f=t , f^t=t , f^f=f
            if(istrue) ways = (ways + (lt*rf)%m + (lf*rt)%m)%m;
            else ways = (ways + (rf*lf)%m + (lt*rt)%m)%m;
        }
    }
    return dp[i][j][istrue]=ways%1003;
}

int countWays(int N, string S){
    vector<vector<vector<ll>>> dp(N,vector<vector<ll>>(N,vector<ll>(2,-1)));
    return f(0,N-1,1,S,dp);
}

int main(){
int n;cin>>n;
string s; cin>>s;
cout<<countWays(n,s)<<endl;
}