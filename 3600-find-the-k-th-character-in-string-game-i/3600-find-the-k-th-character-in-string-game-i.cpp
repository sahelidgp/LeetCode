class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(true){
        
            int len = s.length();

            for(int i=0;i<len;i++){
                s += ((s[i]-'a'+1)%26+'a');
                if(i==k-1)return s[k-1];
            }
        }
        return -1;
    }
};