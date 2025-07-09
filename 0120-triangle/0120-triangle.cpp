class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();

        
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<i+1;j++){
                if(i == 0 && j == 0)dp[i][j] = triangle[i][j];
                else{
                    int up = 1e9;
                    int diag = 1e9;
                    if(i>0) up = dp[i-1][j];
                    if(i>0 && j>0)diag = dp[i-1][j-1];

                    dp[i][j] = min(up,diag)+triangle[i][j];
                }
            }
        }
        int mini = 1e9;
        for(int p=0;p<m;p++){
            mini = min(mini,dp[n-1][p]);
        }
        return mini;
    }
};