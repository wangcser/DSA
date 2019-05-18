# 至少有K个重复字符的最长子串
> Author ID.9276 

**问题关键词：**

- DP
- 递归

## 01 题目

找到给定字符串（由小写字符组成）中的最长子串 **T** ， 要求 **T** 中的每一字符出现次数都不少于 *k* 。输出 **T** 的长度。

**示例 1:**

```
输入:
s = "aaabb", k = 3

输出:
3

最长子串为 "aaa" ，其中 'a' 重复了 3 次。
```

**示例 2:**

```
输入:
s = "ababbc", k = 2

输出:
5

最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
```

## 02 输入分析



## 03 解题思路

### 3.1 基础思路

- 首先统计子串中所有字符的频率
  - 若所有字符频率都大于 k，则返回该子串
  - 若存在字符频率小于 k，则该字符不在结果串中，从该字符处将子串分为三部分

动态规划。

核心思想：如果某个字符 `x` 在整个字符串中出现的次数 `<k`，那么 `x` 不可能出现在最终要求的子串中。因此，可以将原字符串截断为：

```gml
x 左侧字符子串 + x + x 右侧字符子串
```

因此，问题就被拆分为对左子串、右子串求解这两个子问题

### 3.2 算法优化



## 04 核心代码

```c++
class Solution {
public:
    int longestSubstring(string s, int k) {
        
        if(k <= 1) return s.size();
        if(s.empty() || s.size() < k) return 0;
        
        // count the freq
        unordered_map<char, int> m;
        for(char c: s) {
            m[c]++;
        }
        
        int i = 0;
        while(i < s.size() && m[s[i]] >= k)
                i++;
        
        if(i == s.size()) return s.size();
        
        int l = longestSubstring(s.substr(0, i), k);
        while(i < s.size() && m[s[i]] < k)
            i++;
        
        int r = longestSubstring(s.substr(i), k);
        
        
        return max(l, r);
    }
};
```



## 05 算法效率分析



## 06 问题总结

