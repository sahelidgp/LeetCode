class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int ans = 0;
        k--; // Convert to 0-based index

        // Go through each bit of k
        for (int i = 0; k > 0; i++) {
            if (k & 1) { // If the i-th bit is set
                ans += operations[i];
            }
            k >>= 1; // Move to the next bit
        }

        return 'a' + (ans % 26);
    }
};
