class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long ans = 0;
        int c = 0;
        while(n>0){
            int d = n%10;
            if(d != 0){
                sum += d;
                ans += (long long)d*(long long)pow(10,c);
                c++;
            }
          n/=10;
        }
        return ans * sum;
    }
};