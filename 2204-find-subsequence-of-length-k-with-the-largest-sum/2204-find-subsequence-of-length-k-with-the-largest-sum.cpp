class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        // copy the vector in other vector
        vector<int>copy = nums;
        //sort the copy vector
        //O(n)
        sort(copy.begin(),copy.end());

        // take the last k elements as they are the largetst k elements
        //O(klogk)
        unordered_map<int,int>mp;
        for(int i=n-k;i<n;i++){
            mp[copy[i]]++;
        }
        vector<int>ans;
        // nowtraverse in the original input array and check if the element is among the largest k ele
        // then push it in the ans
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]) != mp.end()){
                ans.push_back(nums[i]);
                //decrease the freq count once it is included
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)mp.erase(nums[i]);
            }
            if(ans.size() == k)break;
        }
        return ans;
    }
};