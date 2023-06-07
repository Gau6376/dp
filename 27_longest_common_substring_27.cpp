#include<bits/stdc++.h>
using namespace std;

// int longestCommonSubstr (string S1, string S2, int n, int m)
// {
//     vector<vector<int>>dp(n+1,vector<int>(m+1,0));
//     for(int i=0;i<=m;i++) dp[0][i]=0;
//     for(int i=0;i<=n;i++) dp[i][0]=0;
//     int ans=0;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(S1[i-1]==S2[j-1]){ 
//             dp[i][j]=1+dp[i-1][j-1];
//             ans=max(ans,dp[i][j]);
//             }
//             else dp[i][j]=0;
//         }
//     }
//     return ans;
// }

// best
int longestCommonSubstr (string S1, string S2, int n, int m)
{
    vector<int> prev(m+1,0),cur(m+1,0);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(S1[i-1]==S2[j-1]){ 
            cur[j]=1+prev[j-1];
            ans=max(ans,cur[j]);
            }
            else cur[j]=0;
        }
        prev=cur;
    }
    return ans;
}

int main(){
string s1="abcd",s2="abzd";
cout<<longestCommonSubstr(s1,s2,4,4)<<endl;
}