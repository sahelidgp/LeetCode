class Solution {
private:
    void generateSubsetSums(vector<int>& arr, unordered_map<int, vector<int>>& res) {
        int n = arr.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            int sum = 0, cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    sum += arr[i];
                    cnt++;
                } else {
                    sum -= arr[i];
                }
            }
            res[cnt].push_back(sum);
        }
    }

public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;

        vector<int> left(nums.begin(), nums.begin() + half);
        vector<int> right(nums.begin() + half, nums.end());

        unordered_map<int, vector<int>> leftMap, rightMap;

        generateSubsetSums(left, leftMap);
        generateSubsetSums(right, rightMap);

        // Sort all vectors to use binary search
        for (auto& [_, vec] : rightMap) {
            sort(vec.begin(), vec.end());
        }

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int best = INT_MAX;

        for (auto& [cntA, vecA] : leftMap) {
            int cntB = half - cntA;
            if (rightMap.find(cntB) == rightMap.end()) continue;

            vector<int>& vecB = rightMap[cntB];
            for (int sumA : vecA) {
                int target = -sumA;

                auto it = lower_bound(vecB.begin(), vecB.end(), target);

                if (it != vecB.end()) {
                    int diff = sumA + *it;
                    best = min(best, abs(diff));
                }

                if (it != vecB.begin()) {
                    --it;
                    int diff = sumA + *it;
                    best = min(best, abs(diff));
                }
            }
        }

        return best;
    }
};
