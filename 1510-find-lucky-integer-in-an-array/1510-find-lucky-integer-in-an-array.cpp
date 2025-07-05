class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int maxi=-1;
        int ans = -1;
        for(auto &[key,val]:mp){
            
            if(key == val){
                ans = key;
                maxi = max(maxi,ans);
            }
        }

        return maxi;
    }
};