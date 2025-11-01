class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0; i<asteroids.size(); i++) {
            int curr = asteroids[i];
            bool destroyed = false;

            while(!st.empty() && st.top() > 0 && curr < 0) {
                if(abs(st.top()) < abs(curr)) {
                    st.pop(); // smaller asteroid explodes
                    continue;
                } else if(abs(st.top()) == abs(curr)) {
                    st.pop(); // both explode
                }
                destroyed = true; // current one destroyed
                break;
            }

            if(!destroyed) st.push(curr);
        }

        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
