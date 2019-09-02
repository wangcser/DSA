# 找出第K小的距离对
**问题关键词：**

- 二分查找

## 01 题目

给定一个整数数组，返回所有数对之间的第 k 个最小**距离**。一对 (A, B) 的距离被定义为 A 和 B 之间的绝对差值。

**示例 1:**

```
输入：
nums = [1,3,1]
k = 1
输出：0 
解释：
所有数对如下：
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
因此第 1 个最小距离的数对是 (1,1)，它们之间的距离为 0。
```

**提示:**

1. `2 <= len(nums) <= 10000`.
2. `0 <= nums[i] < 1000000`.
3. `1 <= k <= len(nums) * (len(nums) - 1) / 2`.

## 02 分析

- 首先排序优化问题性质
- 然后将查找的目标设定为距离

## 03 题解

## 基础：

- 查找的目标设定为距离，而最小的距离为 0，最大的距离为 首尾的差值
- 中值用于找到序列中最接近的数，并由此得到满足距离约束的数对的数量

```c++
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // 排序该问题的核心操作，显著优化了问题的性质
        sort(nums.begin(), nums.end());
        // 按照距离进行查找
        int l = 0, r = nums.back() - nums[0];
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            int lessThanMid = findPairs(nums, mid);
            
            if(lessThanMid < k) l = mid + 1;
            else r = mid;
        }
        
        return l;
    }
    
    // 计算给定序列中距离不超过 dist 的元素对的数量
    int findPairs(vector<int>& nums, int dist) {
        int count = 0, r = nums.size() - 1;
        for(int l = nums.size() - 2; l >=0; l--) {
            while(r > l && nums[r] - nums[l] > dist)
                r--;
            
            count += r - l;
        }
        
        return count;
    }
};
```

## 04 总结

