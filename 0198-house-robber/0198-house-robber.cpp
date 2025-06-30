class Solution {
private:
    int memo(int i,vector<int>&nums,vector<int>&dp){
        //base case
        if(i == 0)return nums[i]; // 2->0 so it will be better if we rob this house
        if(i <0)return 0; // 1-> -1 not possible case
        if(dp[i] != -1)return dp[i];
        int pick = nums[i] + memo(i-2,nums,dp);
        int notPick = memo(i-1,nums,dp);

        return dp[i] = max(pick,notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n,-1);

        return memo(n-1,nums,dp);

    }
};