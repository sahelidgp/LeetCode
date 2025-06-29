class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i=n-1;i>=0;i--){
            if (digits[i]<9){
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        vector<int>digits2(n+1,0);
        digits2[0] = 1;
        return digits2;
    }
};
