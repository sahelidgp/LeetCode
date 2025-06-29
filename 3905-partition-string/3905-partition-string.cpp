#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> seen;
        vector<string> result;

        int n = s.size();
        string curr = "";

        for (int i = 0; i < n; ++i) {
            curr += s[i];

            if (seen.count(curr)) {
                continue;
            } else {
                result.push_back(curr);
                seen.insert(curr);
                curr = "";
            }
        }

        return result;
    }
};
// tc: O(nlogn.(bound on number of comparisons))
//set-> red black tree 
//insertion,count->log(n).no of comparisons

//bound on comparison -> O(sqrt(n))

// "aaaaaaaaaa...." worst case when we insert this into the set 

//standard formula for ap :  (n')(n'+1)/2  = n
// n' ~ O(sqrt(n)) -> a maximum size of a segment

//tc: O(n.sqrt(n).logn) ~= 10^8 operations which should just pass  if set   
// if unordered_set is used O(n.sqrt(n))

// in fact actual bound is lesser 
//set<string>seen  
//O(n.sqrt(n).log(sqrt(n))) ~= 10^7

// time complexity analysis question
// the direct implementation passes
// analysis to see why it passes is not so obvious 

// can be solved in less tc using advanced algorithm
//hashing(custom(kmp),unordered_set)
//tries
