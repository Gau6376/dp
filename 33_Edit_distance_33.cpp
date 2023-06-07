#include<bits/stdc++.h>
using namespace std;
// convert s1 to s2 to these 3 operations 1. insert 2. deletion 3. replace

int f(int i,int j,string &s,string &t,vector<vector<int>> &dp){
    if(i<0) return j+1;
    if(j<0) return i+1;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==t[j]) return dp[i][j] = 0+f(i-1,j-1,s,t,dp); // match
    int insert = 1+f(i,j-1,s,t,dp);
    int deletion = 1+f(i-1,j,s,t,dp);
    int replace = 1+f(i-1,j-1,s,t,dp);
    return dp[i][j] = min({insert,deletion,replace});
}

// memozation
// int editDistance(string s, string t) {
//     int n=s.size(),m=t.size();
//     vector<vector<int>> dp(n,vector<int>(m,-1));
//     return f(n-1,m-1,s,t,dp);
// }

// tabulation
int editDistance(string s, string t) {
    int n=s.size(),m=t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++) dp[i][0]=i;
    for(int j=0;j<=m;j++) dp[0][j]=j;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]) dp[i][j] = 0+dp[i-1][j-1]; // match
            else{
            int insert = 1+dp[i][j-1];
            int deletion = 1+dp[i-1][j];
            int replace = 1+dp[i-1][j-1];
            dp[i][j] = min({insert,deletion,replace});
            }
        }
    }

    return dp[n][m];
}

// space optimization = best
int editDistance(string s, string t) {
    int n=s.size(),m=t.size();
    vector<int> prev(m+1,0),cur(m+1,0);
    for(int j=0;j<=m;j++) prev[j]=j;

    for(int i=1;i<=n;i++){
        cur[0]=i;
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]) cur[j] = 0+prev[j-1]; // match
            else{
            int insert = 1+cur[j-1];
            int deletion = 1+prev[j];
            int replace = 1+prev[j-1];
            cur[j] = min({insert,deletion,replace});
            }
        }
        prev=cur;
    }

    return prev[m];
}

int main(){
    string s,t;
    cin>>s>>t;
    cout<<editDistance(s,t)<<endl;
}