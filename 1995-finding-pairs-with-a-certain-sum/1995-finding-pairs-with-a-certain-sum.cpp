class FindSumPairs {
private:
vector<int> nums1;
vector<int> nums2;
unordered_map<int,int>freq;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        int l2 = nums2.size();
        for(int i=0;i<l2;i++){
            freq[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        freq[nums2[index]]--;
        nums2[index] += val;
        freq[nums2[index]]++;
    }
    
    int count(int tot) {
        
        int l1 = nums1.size();
        int cnt = 0;
        for(int i=0;i<l1;i++){
            if(freq.find(tot-nums1[i])!=freq.end()){
                cnt+= freq[tot-nums1[i]];
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */