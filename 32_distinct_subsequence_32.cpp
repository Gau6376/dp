#include<bits/stdc++.h>
using namespace std;
// #define MOD 109+7;

int countUtil(string s1, string s2, int ind1, int ind2,vector<vector<int>>& dp){
if(ind2<0) return 1;
if(ind1<0) return 0;
if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    
if(s1[ind1]==s2[ind2]){
    int leaveOne = countUtil(s1,s2,ind1-1,ind2-1,dp);
    int stay = countUtil(s1,s2,ind1-1,ind2,dp);
        
    return dp[ind1][ind2] = (leaveOne + stay);
}
else{
    return dp[ind1][ind2] = countUtil(s1,s2,ind1-1,ind2,dp);
}
}

int subsequenceCounting(string &t, string &s) {
    int lt = t.size();             // gives tle
    int ls = s.size();   
    vector<vector<int>> dp(lt,vector<int>(ls,-1));
    return countUtil(t,s,lt-1,ls-1,dp);
}

// tabulation
// int numDistinct(string s, string t) {
//     int n = s.size();   
//     int m = t.size();             
//     vector<vector<double>> dp(n+1,vector<double>(m+1,0));
//     for(int i=0;i<=n;i++) dp[i][0]=1;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
//             else dp[i][j] = dp[i-1][j];
//         }
//     }
//     return (int)dp[n][m];
// }

// space optimization
// int numDistinct(string s, string t) {
//     int n = s.size();   
//     int m = t.size();             
//     vector<double> prev(m+1,0) , cur(m+1,0);
//     prev[0]=cur[0]=1;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(s[i-1]==t[j-1]) cur[j] = prev[j-1] + prev[j];
//             else cur[j] = prev[j];
//         }
//         prev=cur;
//     }
//     return (int)prev[m];
// }

// best
int numDistinct(string s, string t) {
    int n = s.size();   
    int m = t.size();             
    vector<double> dp(m+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(s[i-1]==t[j-1]) dp[j] = dp[j-1] + dp[j];
        }
    }
    return (int)dp[m];
}

int main(){
string s1,s2;
cin>>s1>>s2;
// cout<<subsequenceCounting(s1,s2)<<endl;
cout<<numDistinct(s1,s2)<<endl;
}
// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// rabbit
// rabbit
// rabbit