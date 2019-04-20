# 和为k的子数组
> Author ID.9276

## 01 题目

给定一个整数数组和一个整数 **k，**你需要找到该数组中和为 **k** 的连续的子数组的个数。

**示例 1 :**

```
输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
```

**说明 :**

1. 数组的长度为 [1, 20,000]。
2. 数组中元素的范围是 [-1000, 1000] ，且整数 **k** 的范围是 [-1e7, 1e7]。

## 02 分析

减治求和，注意数组无序且非正

\#1: 累计和

用一个数组cumulative保存从第0个元素到当前元素的和，cumulative数组中第j个元素与第i个元素的差（cumulative[j] - cumulative[i]）即是原数组nums中第i个元素到第j个元素的和（nums[i:j]），通过两层循环计算每两个元素间的累积和。时间复杂度为$O(n^2)$，空间复杂度为$O(n)$。

```c++
class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        vector<int> cul(nums.size() + 1, 0);
        int res = 0;
        for (int i = 1; i <= nums.size(); ++i)
            cul[i] = cul[i - 1] + nums[i - 1];
        for (int i = 0; i < cul.size(); ++i)
            for (int j = i + 1; j < cul.size(); ++j)
                res += cul[j] - cul[i] == k;
        return res;
    }
};
```

\#2: 累计和（不使用数组）

直接通过两层循环计算两个元素间的累积和。时间复杂度为$O(n^2)$，空间复杂度为$O(1)$。

```c++
class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int size = nums.size(), res = 0;
        for (int i = 0; i < size; ++i) {
            int sum = 0;
            for (int j = i; j < size; ++j) {
                sum += nums[j];
                res += sum == k ? 1 : 0;
            }
        }
        return res;
    }
};
```

\#3: 哈希表

遍历数组nums，计算从第0个元素到当前元素的和，用哈希表保存出现过的累积和sum的次数。如果sum - k在哈希表中出现过，则代表从当前下标i往前有连续的子数组的和为sum。时间复杂度为$O(n)$，空间复杂度为$O(1)$。

```c++
class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int, int> cul;
        cul[0] = 1;
        for (auto &m : nums) {
            sum += m;
            res += cul[sum - k];
            ++cul[sum];
        }
        return res;
    }
}
class Solution:
    def subarraySum(self, nums: 'List[int]', k: 'int') -> 'int':
        sum, res, cul = 0, 0, {}
        cul[0] = 1
        for i in range(len(nums)):
            sum += nums[i]
            if sum - k in cul:
                res += cul[sum - k]
            if sum not in cul:
                cul[sum] = 0
            cul[sum] += 1
        return res
```



## 03 题解

### 3.1 C++

```c++
//version 1.0 0.0%
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        if(nums.size() <= 0) return 0;
        
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for(int j = i; j < nums.size(); j++) {
                sum += nums[j];
                count += (sum == k) ? 1 : 0;
            }
        }
            return count;
    }
};
```

### 3.2 Python 3

```python
# version 1.0 0.0%

```

### 3.3 Go

```Go
//version 1.0 0.0%

```



## 04 总结

