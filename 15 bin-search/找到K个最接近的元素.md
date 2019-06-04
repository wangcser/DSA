# 找到K个最接近的元素
> Author ID.9276 

**问题关键词：**

- 

## 01 题目

给定一个排序好的数组，两个整数 `k` 和 `x`，从数组中找到最靠近 `x`（两数之差最小）的 `k` 个数。返回的结果必须要是按升序排好的。如果有两个数与 `x` 的差值一样，优先选择数值较小的那个数。

**示例 1:**

```
输入: [1,2,3,4,5], k=4, x=3
输出: [1,2,3,4]
```

 

**示例 2:**

```
输入: [1,2,3,4,5], k=4, x=-1
输出: [1,2,3,4]
```

 

**说明:**

1. k 的值为正数，且总是小于给定排序数组的长度。
2. 数组不为空，且长度不超过 104
3. 数组里的每个元素与 x 的绝对值不超过 104

 

**更新(2017/9/19):**
这个参数 *arr* 已经被改变为一个**整数数组**（而不是整数列表）。 **请重新加载代码定义以获取最新更改。**

## 02 输入分析



## 03 解题思路

### 3.1 基础思路

#### 滑窗探查法

#### 二分查找法

- 使用二分查找确定中点，然后按照要求中心扩展

### 3.2 算法优化



## 04 核心代码

### 滑窗探查法

```c++
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int> diff(arr.begin(), arr.end());
        int start = 0;
        
        for(int i = 0; i < k; i++) {
            diff[i] = diff[i] - x;
        }
        
        for(int i = k; i < diff.size(); i++) {
            
            diff[i] = diff[i] - x;
            
            if(abs(diff[i]) < abs(diff[start])) start = i - k + 1;
        }
        
        vector<int> ans(arr.begin() + start, arr.begin() + start + k);
        return ans;
    }
};
```



## 05 算法效率分析



## 06 问题总结

