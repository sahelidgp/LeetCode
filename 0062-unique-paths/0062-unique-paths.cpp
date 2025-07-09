class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n,1);
        for(int i=1;i<m;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){

                temp[j] = prev[j];
                if(j>0) temp[j] += temp[j-1];
            }
            prev = temp;
        }
        return prev[n-1];
    }
};