class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int maxcount = 0;
        //tc : O(n)
        for (int j = 0; j < n; j++) {
            // Shrink window if difference exceeds 1
            while (nums[j] - nums[i] > 1) {
                i++;
            }

            // Valid window if difference is exactly 1
            if (nums[j] - nums[i] == 1) {
                maxcount = max(maxcount, j - i + 1);
            }
        }

        return maxcount;
    }
};
//another approach O(nlogn)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int maxcount = 0;

        for (int j = 0; j < n; j++) {
            // Shrink window if difference exceeds 1
            while (nums[j] - nums[i] > 1) {
                i++;
            }

            // Valid window if difference is exactly 1
            if (nums[j] - nums[i] == 1) {
                maxcount = max(maxcount, j - i + 1);
            }
        }

        return maxcount;
    }
};

