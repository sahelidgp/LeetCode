class Solution {
public:
    int findLHS(vector<int>& nums) {
       unordered_map<int,int>mp;
       int n = nums.size();

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int count;
        int maxcount = 0;
        for(auto [key,val]:mp){
            if(mp.count(key+1)){
                count = val + mp[key+1];
                maxcount = max(count,maxcount);
            }
        }
        return maxcount;
    }
};
