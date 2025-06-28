<h2><a href="https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum">2204. Find Subsequence of Length K With the Largest Sum</a></h2><h3>Easy</h3><hr><p>You are given an integer array <code>nums</code> and an integer <code>k</code>. You want to find a <strong>subsequence </strong>of <code>nums</code> of length <code>k</code> that has the <strong>largest</strong> sum.</p>

<p>Return<em> </em><em><strong>any</strong> such subsequence as an integer array of length </em><code>k</code>.</p>

<p>A <strong>subsequence</strong> is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,1,3,3], k = 2
<strong>Output:</strong> [3,3]
<strong>Explanation:</strong>
The subsequence has the largest sum of 3 + 3 = 6.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [-1,-2,3,4], k = 3
<strong>Output:</strong> [-1,3,4]
<strong>Explanation:</strong> 
The subsequence has the largest sum of -1 + 3 + 4 = 6.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,4,3,3], k = 2
<strong>Output:</strong> [3,4]
<strong>Explanation:</strong>
The subsequence has the largest sum of 3 + 4 = 7. 
Another possible subsequence is [4, 3].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>

# CODE
```c++
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        // copy the vector in other vector
        vector<int>copy = nums;
        //sort the copy vector
        //O(n)
        sort(copy.begin(),copy.end());

        // take the last k elements as they are the largetst k elements
        //O(klogk)
        unordered_map<int,int>mp;
        for(int i=n-k;i<n;i++){
            mp[copy[i]]++;
        }
        vector<int>ans;
        // nowtraverse in the original input array and check if the element is among the largest k ele
        // then push it in the ans
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]) != mp.end()){
                ans.push_back(nums[i]);
                //decrease the freq count once it is included
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)mp.erase(nums[i]);
            }
            if(ans.size() == k)break;
        }
        return ans;
    }
};
```
</ul>
