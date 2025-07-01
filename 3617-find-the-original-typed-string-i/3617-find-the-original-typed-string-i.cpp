class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int ans = 1;
        int i=0;
        int count = 1;
        for(int j=i+1;j<n;j++){
            while(word[j] == word[i]){
                j++;
                count++;
            }
                ans += count-1;
                i=j;
                count=1;
            
        }
        
        return ans;
    }
};