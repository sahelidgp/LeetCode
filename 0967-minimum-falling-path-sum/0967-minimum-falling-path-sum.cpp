class Solution {

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n));
        //base case
        for(int j=0;j<n;j++){
            dp[n-1][j] = matrix[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int down = dp[i+1][j];
                int rightdiag = (j<n-1)?dp[i+1][j+1]:1e9;
                int leftdiag = (j>0)?dp[i+1][j-1]:1e9;

                dp[i][j] = matrix[i][j] + min({down,rightdiag,leftdiag});
            }
        }
        return *min_element(dp[0].begin(),dp[0].end());
    }
};