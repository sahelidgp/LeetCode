class Solution {

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>dp(n);
        //base case
        for(int j=0;j<n;j++){
            dp[j] = matrix[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int>temp(n);
            for(int j=0;j<n;j++){
                int down = dp[j];
                int rightdiag = (j<n-1)?dp[j+1]:1e9;
                int leftdiag = (j>0)?dp[j-1]:1e9;

                temp[j] = matrix[i][j] + min({down,rightdiag,leftdiag});
            }
            dp = temp;
        }
        return *min_element(dp.begin(),dp.end());
    }
};