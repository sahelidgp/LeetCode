class Solution {
public:
    vector<string> partitionString(string s) {
        set<pair<long long, long long>> seen; // Store double hashes
        vector<string> result;

        int n = s.size();
        long long hash1 = 0, hash2 = 0;
        long long base1 = 131, base2 = 137;
        long long mod1 = 1e9 + 7, mod2 = 1e9 + 9;

        string curr = "";

        for (int i = 0; i < n; ++i) {
            curr += s[i];
            hash1 = (hash1 * base1 + s[i]) % mod1;
            hash2 = (hash2 * base2 + s[i]) % mod2;

            if (seen.count({hash1, hash2})) continue;

            result.push_back(curr);
            seen.insert({hash1, hash2});
            curr = "";
            hash1 = 0;
            hash2 = 0;
        }

        return result;
    }
};
