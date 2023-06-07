// fixed starting point and variable ending point
#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,int n, vector<vector<int>>& triangle,vector<vector<int>>&dp){
    if(i==n-1) return triangle[n-1][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int down = triangle[i][j]  + f(i+1,j,n,triangle,dp);
    int diagonal = triangle[i][j]  + f(i+1,j+1,n,triangle,dp);
    return dp[i][j] = min(down,diagonal);
}

int minimizeSum(int n, vector<vector<int>>& triangle) {
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return f(0,0,n,triangle,dp);
}

int main(){
int n;
cin>>n;
vector<vector<int>> triangle;
for(int i=0;i<n;i++){
    vector<int>temp;
    for(int j=0;j<=i;j++){
        int x;
        cin>>x;
        temp.push_back(x);
    }
    triangle.push_back(temp);
}
cout<<minimizeSum(n,triangle)<<endl;

// tabulation
// vector<vector<int>> dp(n,vector<int>(n,-1));
// for(int j=0;j<n;j++)
// dp[n-1][j] = triangle[n-1][j];
// for(int i=n-2;i>=0;i--){
//     for(int j=i;j>=0;j--){
//     int down = triangle[i][j]  + dp[i+1][j];
//     int diagonal = triangle[i][j]  + dp[i+1][j+1];
//     dp[i][j] = min(down,diagonal);
//     }
// }
// cout<<dp[0][0]<<endl;


// best
// vector<int>front(n,0),curr(n,0);
// for(int j=0;j<n;j++)
// dp[n-1][j] = triangle[n-1][j];
// for(int i=n-2;i>=0;i--){
//     for(int j=i;j>=0;j--){
//     int down = triangle[i][j]  + front[j];
//     int diagonal = triangle[i][j]  + front[j+1];
//     curr[j] = min(down,diagonal);
//     }
// front=curr;
// }
// cout<<front[0]<<endl;
}