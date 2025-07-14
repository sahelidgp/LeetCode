class Solution {
private:
    
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<bool> prev(target+1,false);
        prev[0] = true;
       if (arr[0] <= target) prev[arr[0]] = true;

        for(int ind=1;ind<n;ind++){
            vector<bool> curr(target+1,false);
            curr[0]=true;
            for(int tar=1;tar<=target;tar++){
                bool notTake = prev[tar];
                bool take = false;
                if(arr[ind]<=tar)take = prev[tar-arr[ind]];
                curr[tar] = notTake || take;
            }
            prev = curr;
        }
        return prev[target];
    }
public:
    bool canPartition(vector<int>&arr) {
        int n = arr.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        if((sum & 1))return false;
        return isSubsetSum(arr,sum/2);
    }
};

