class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int count = 0;
        bool valid = true;

        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') {
                if (valid) count++;  // word had no broken letters
                valid = true;        // reset for next word
            } 
            else if (broken.count(text[i])) {
                valid = false;       // this word can't be typed
            }
        }

        return count;
    }
};
