class Solution {
public:
    int m = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
         int st = 0;
         int end = n-1;
        int count = 0;
        vector<int>power(n,1);
        for(int i=1;i<n;i++){
            power[i] = (power[i-1]*2)%m;
        }
        
            while(st<=end){
                if(nums[st]+nums[end] <= target){
                    count = (count + power[end-st])%m;
                    st++;
                }else end--;
            }
        
        return count%m;
    }
};