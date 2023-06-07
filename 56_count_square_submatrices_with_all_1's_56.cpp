#include<bits/stdc++.h>
using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    int n=matrix.size(),m=matrix[0].size(),sum=0;  
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){  
    dp[i][0] = matrix[i][0];
    }
    for(int i=0;i<m;i++){
    dp[0][i] = matrix[0][i];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]==0) dp[i][j]=0;
            else dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum+=dp[i][j];
        }
    }
    return sum;
}

int main(){
int n,m;cin>>n>>m;
vector<vector<int>>matrix;
for(int i=0;i<n;i++){
    for(int j=0;j<m;i++){
        cin>>matrix[i][j];
    }
}
cout<<countSquares(matrix)<<endl;
}