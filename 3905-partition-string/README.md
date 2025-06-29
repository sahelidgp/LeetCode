# LeetCode 3905 - Partition String

## Problem Link

[LeetCode 3905: Partition String](https://leetcode.com/problems/partition-string)

## Problem Description

Given a string `s`, partition it into **unique segments** following this procedure:

1. Start building a segment from index 0.
2. Extend the current segment character by character until the current segment has **not been seen before**.
3. Once the segment is unique, add it to your list of segments, mark it as seen, and start a new segment from the next index.
4. Repeat until the end of the string.

Return the array of created segments.

---

## Example 1:

**Input:**

```text
s = "abbccccd"
```

**Output:**

```text
["a", "b", "bc", "c", "cc", "d"]
```

## Example 2:

**Input:**

```text
s = "aaaa"
```

**Output:**

```text
["a", "aa"]
```

---

## Constraints:

* `1 <= s.length <= 10^5`
* `s` contains only lowercase English letters.

---

## Approaches and Time Complexity

| Approach                                | Time Complexity | Practical Performance         | Space Complexity | Notes                                                                                     |
| --------------------------------------- | --------------- | ----------------------------- | ---------------- | ----------------------------------------------------------------------------------------- |
| **1. Unordered Set (Current Solution)** | O(n√n)          | Acceptable (\~10⁸ operations) | O(n)             | Passes in practice. Worst-case is borderline. String hashing depends on substring length. |
| **2. Ordered Set (Balanced BST)**       | O(n√n log n)    | Slower                        | O(n)             | Adds log n factor due to tree balancing. Not recommended.                                 |
| **3. Rolling Hash (Recommended)**       | O(n)            | Extremely Fast                | O(n)             | Uses integer hashing. Avoids string comparisons. Best performance.                        |
| **4. Trie (Prefix Tree)**               | O(n)            | Very Fast                     | O(n)             | Efficient prefix matching, but higher memory usage due to trie node overhead.             |

---

## Conclusion:

* ✅ Use **Rolling Hash** for the most optimized solution.
* ✅ Trie can also solve this efficiently if prefix management is required.
* ✅ The provided solution using `unordered_set<string>` is acceptable but not optimal for large inputs in worst-case scenarios.

---

## Contact:

Feel free to reach out for the full rolling hash or trie implementation.


📚 Step 1: Set Operation Cost
You are using unordered_set<string>.

Average case: Insertion and lookup in an unordered_set is O(1) per operation.

But here, each key is a string, and comparing or hashing a string is not O(1).

👉 Important:
For a string of length L, unordered_set.count(curr) and unordered_set.insert(curr) take O(L) time
(because it needs to compute the hash and possibly compare strings on hash collision).

📚 Step 2: Maximum String Length
Let’s find out how big curr can become in the worst case.

Worst-case example: "aaaaaaaaaaaaaa...."
Let’s say the partitions look like:

perl
Copy
Edit
"a", "aa", "aaa", "aaaa", ..., up to length k
The total length of all these substrings cannot exceed n.
Using the formula for sum of first k natural numbers:

1
+
2
+
3
+
⋯
+
𝑘
≤
𝑛
1+2+3+⋯+k≤n
𝑘
(
𝑘
+
1
)
2
≤
𝑛
⇒
𝑘
≈
𝑂
(
𝑛
)
2
k(k+1)
​
 ≤n⇒k≈O( 
n
​
 )
So maximum string length you will ever build is roughly O(√n).

📚 Step 3: Number of Comparisons and Insertions
You process each character once → O(n) iterations.

But the cost per iteration is not O(1) because:

String comparison/hashing is O(L), where L is the length of curr.

In the worst case, L can grow up to O(√n).

So each set operation (count/insert) costs O(√n) in worst case.

📚 Step 4: Final Time Complexity
Each iteration:

O(√n) for string hashing and comparison.

Total:

𝑂
(
𝑛
)
×
𝑂
(
𝑛
)
=
𝑂
(
𝑛
𝑛
)
O(n)×O( 
root(n)
​
 )=O(n 
root(n)
​
 )
This is approximately O(10^8) operations when n ~ 10^5, which is acceptable in competitive programming under a 1-second limit.

📚 Your Detailed Comments: Verified ✅
You correctly estimated:

The maximum length of substrings → O(√n)

Each operation’s cost → O(√n)

Total time complexity → O(n√n)
