#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,string &p,string &s,vector<vector<int>> &dp){
if(i<0 && j<0) return 1;
if(i<0 && j>=0) return 0;
if(j<0 && i>=0){
    for(int k=0;k<=i;k++){
        if(p[k]!='*') return 0;
    }
    return 1;
}

if(dp[i][j]!=-1) return dp[i][j];

if(p[i]==s[j] || p[i]=='?') return dp[i][j]=f(i-1,j-1,p,s,dp);
if(p[i]=='*'){
    return dp[i][j]=(f(i-1,j,p,s,dp) | f(i,j-1,p,s,dp));
}
return dp[i][j]=0;
}

// bool isMatch(string s, string p) {
//     int n=p.size(),m=s.size();
//     vector<vector<int>> dp(n,vector<int>(m,-1));  
//     return f(n-1,m-1,p,s,dp);  
// }

// tabulation
bool isMatch(string s, string p) {
    int n=p.size(),m=s.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,false)); 

    dp[0][0]=1;

    for(int j=1;j<=m;j++) dp[0][j]=0;

    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int k=1;k<=i;k++){
        if(p[k-1]!='*'){ 
        flag=false;
        break;
        }
        }
        dp[i][0]=flag;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(p[i-1]==s[j-1] || p[i-1]=='?') dp[i][j]=dp[i-1][j-1];
            else if(p[i-1]=='*') dp[i][j]= (dp[i-1][j] | dp[i][j-1]);
            else dp[i][j]=0;  
        }
    }
    return dp[n][m];
}

// best
bool isMatch(string s, string p) {
    int n=p.size(),m=s.size();
    vector<bool> prev(m+1,false),cur(m+1,false);

    prev[0]=1;

    for(int j=1;j<=m;j++) prev[j]=0;

    for(int i=1;i<=n;i++){
        // cur is the current row column
        // and that cur's 0th row has to be assigned everytime
        bool flag=1;
        for(int k=1;k<=i;k++){
        if(p[k-1]!='*'){ 
        flag=false;
        break;
        }
        }
        // for every row u r assigning the 0th column's value
        cur[0]=flag;

        for(int j=1;j<=m;j++){
            if(p[i-1]==s[j-1] || p[i-1]=='?') cur[j]=prev[j-1];
            else if(p[i-1]=='*') cur[j]= (prev[j] | cur[j-1]);
            else cur[j]=0;  
        }
        prev=cur;
    }
    return prev[m];
}
int main(){
    string pattern,s;
    cout<<isMatch(s,pattern)<<endl;
}