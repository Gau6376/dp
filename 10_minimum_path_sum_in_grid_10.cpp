#include<bits/stdc++.h>
using namespace std;
int f(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
    if(i==0 && j==0) return grid[0][0];
    if(i<0 || j<0) return 1e9;

    if(dp[i][j]!=-1) return dp[i][j];

    int up = f(i-1,j,grid,dp) + grid[i][j];
    int left = f(i,j-1,grid,dp) + grid[i][j];

    return dp[i][j]=min(up,left);
}
int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,grid,dp);
}

int main(){
int n,m;
cin>>n>>m;
vector<vector<int>> dp(n,vector<int>(m,-1));
vector<vector<int>>grid;
for(int i=0;i<n;i++){
    vector<int>temp;
    for(int j=0;j<m;j++){
        int x;
        cin>>x;
        temp.push_back(x);
    }
    grid.push_back(temp);
}
// cout<<f(n-1,m-1,grid,dp)<<endl;



// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         if(i==0 && j==0) dp[i][j]=grid[0][0];
//         else{
//             int up=grid[i][j],left=grid[i][j];
//             if(i>0)
//             up += dp[i-1][j];
//             else up+=1e9;
//             if(j>0)
//             left += dp[i][j-1];
//             else left+=1e9;
//             dp[i][j] = min(up,left);
//         }
//     }
// }
// cout<<dp[n-1][m-1]<<endl;

// best
    vector<int>prev(m,0);
for(int i=0;i<n;i++){
    vector<int>cur(m,0);
    for(int j=0;j<m;j++){
        if(i==0 && j==0) cur[j]=grid[0][0];
        else{
            int up=grid[i][j],left=grid[i][j];
            if(i>0)
            up += prev[j];
            else up+=1e9;
            if(j>0)
            left += cur[j-1];
            else left+=1e9;
            
            cur[j] = min(left,up);
        }
    }
    prev=cur;
}
cout<<prev[m-1]<<endl;
}