#include <iostream>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        int shifts = 0;

        while (k > 1) {
            int len = 1;
            while (2 * len < k) {
                len *= 2;
            }

            if (k > len) {
                k -= len; // Map to first half
                shifts++;
            } else {
                shifts++;
            }
        }

        return 'a' + (shifts % 26);
    }
};
