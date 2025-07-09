class Solution {
public:
    int uniquePaths(int m, int n) {
        long long N = (long long)m+n-2;
        long long r = m < n ? m - 1 : n - 1; 
        long long res = 1;
        for(long long i=0;i<r;i++){
            res *= (N-i);
            res /= (i+1);
        }
        return (int)res;
    }
};