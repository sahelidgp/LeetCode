class Solution {
int maxSum = 0;
private:
    int sum(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i == m-1 && j == n-1)return  grid[i][j];
        if(i>=m || j >= n)return 1e9;
        if(dp[i][j] != -1)return dp[i][j];
        int r = sum(i+1,j,m,n,grid,dp);
        int b = sum(i,j+1,m,n,grid,dp);
         return dp[i][j] = min(r,b) + grid[i][j];

    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 && j==0)dp[i][j] = grid[i][j];
                else{
                    int left = 1e9;
                    int up = 1e9;
                    if(j>0) left = dp[i][j-1];
                    if(i>0) up = dp[i-1][j];
                    dp[i][j] = min(left,up)+grid[i][j];
                }  
            }
        }
        return dp[m-1][n-1];
    }
};