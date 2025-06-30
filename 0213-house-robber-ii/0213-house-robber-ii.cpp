class Solution {

private:
    int f(vector<int>&temp){
        int n = temp.size();
        int prev = temp[0];
        int prev2 = 0;
        int curr;
        for(int i=1;i<n;i++){
            int take = temp[i];
            if(i>1)take += prev2;
            int nontake = prev;
            curr = max(take,nontake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)return nums[0];
        //temp1 : skips the first element and stores the rests
        //temp2 : skips the last element and stores the rests
        vector<int>temp1;
        vector<int>temp2;

        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }

        int ans1 = f(temp1);
        int ans2 = f(temp2);
        return max(ans1,ans2);
    }
};