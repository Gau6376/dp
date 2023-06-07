#include<bits/stdc++.h>
using namespace std;
// 3-D dp

int f(int i,int j1,int j2,int n,int m,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
    if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e8;
    if(i==n-1){
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }

    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

    // explore all path alice and bob can go together

    int maxi=-1e8;
    for(int dj1=-1;dj1<=1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++){
            int val=0;
            if(j1==j2) val=grid[i][j1];
            else val = grid[i][j1]+grid[i][j2];
            val+=f(i+1,j1+dj1,j2+dj2,n,m,grid,dp);
            maxi=max(maxi,val);
        }
    }

    return dp[i][j1][j2] = maxi;
}

int solve(int n, int m, vector<vector<int>>& grid) {
    // dp[r][c][c]
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    return f(0,0,m-1,n,m,grid,dp);
}

int main(){
int n,m;
cin>>n>>m;
vector<vector<int>>grid;
for(int i=0;i<n;i++){
    vector<int>temp;
    for(int j=0;j<m;j++){
        int x;cin>>x;
        temp.push_back(x);
    }
    grid.push_back(temp);
}
    // cout<<solve(n,m,grid)<<endl;

// tabulation 
vector<vector<vector<int>>> dp1(n,vector<vector<int>>(m,vector<int>(m,0)));   
for(int j1=0;j1<m;j1++){
    for(int j2=0;j2<m;j2++){
        if(j1==j2) dp1[n-1][j1][j2] = grid[n-1][j1];
        else dp1[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
    }
}

for(int i=n-2;i>=0;i--){
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            int maxi=-1e8;
            for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
            int val=0;
            if(j1==j2) val=grid[i][j1];
            else val = grid[i][j1]+grid[i][j2];
            if(j1+dj1>=0 && j1+dj1<m  && j2+dj2>=0 && j2+dj2<m)
            val+=dp1[i+1][j1+dj1][j2+dj2];
            else val+=-1e8;
            maxi=max(maxi,val);
       }
      }
      dp1[i][j1][j2]=maxi;
     }
    }
   }
   cout<<dp1[0][0][m-1]<<endl;
}