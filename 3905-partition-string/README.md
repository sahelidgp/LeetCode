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
