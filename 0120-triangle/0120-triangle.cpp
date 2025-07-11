class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();

        vector<int>dp(m);

        for(int j=0;j<m;j++){
            dp[j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int>temp(n);
            for(int j=i;j>=0;j--){

                int down = triangle[i][j] + dp[j];
                int diag = triangle[i][j] + dp[j+1];

                temp[j] = min(down,diag);
            }
            dp = temp;
        }
        return dp[0];
    }
};