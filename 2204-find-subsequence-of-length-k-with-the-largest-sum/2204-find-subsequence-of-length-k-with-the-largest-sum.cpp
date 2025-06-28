class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        
        set<pair<int,int>>st;
        for(int i=0;i<n;i++){
            st.insert({nums[i],i});
        }
        
        set<pair<int,int>>ans;
        int count = 0;
        for(auto it = st.rbegin();it != st.rend() && count < k; ++it,++count){
            ans.insert({it->second,it->first});
        
        }
        //reverse(ans.begin(),ans.end());
        //sort(ans.begin(),ans.end());
        vector<int>res;
        for(auto it = ans.begin();it!= ans.end();it++){
                res.push_back(it->second);
        }
        return res;
    }
};