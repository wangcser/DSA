# 数组中第k个最大元素
关键词：

- topK

## 01 题目

在未排序的数组中找到第 **k** 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

**示例 1:**

```
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
```

**示例 2:**

```
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
```

**说明:**

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

## 02 分析

使用内置的排序 + 定位

或者自己排序找，任何排序算法都能实现，题解给出的是快排

- 排序
- 小顶堆
- 快排



## 03 题解

### 3.1 C++

```c++
//version 1.0 0.0%

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        return nums[nums.size() - k];
    }
};
```

```
class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    int findKthLargest(vector<int>& nums, int k) {
        for(auto num : nums) {
            minHeap.push(num);
            if(minHeap.size() > k)
                minHeap.pop();
        }
        
        return minHeap.top();
    }
};
```

## 04 总结

