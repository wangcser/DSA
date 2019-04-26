# 前K个高频元素
> Author ID.9276

## 01 题目

给定一个非空的整数数组，返回其中出现频率前 **k** 高的元素。

**示例 1:**

```
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
```

**示例 2:**

```
输入: nums = [1], k = 1
输出: [1]
```

**说明：**

- 你可以假设给定的 *k* 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
- 你的算法的时间复杂度**必须**优于 O(*n* log *n*) , *n* 是数组的大小。

## 02 分析

按频率排序

注意模版类的使用

## 03 题解

### 3.1 C++

```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // count the freq of each nums.
        unordered_map<int, int> freq;
        for(auto num : nums)
            freq[num]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // pq sort the item by the first index, so must store freq in first index.
        
        for(auto it : freq) {
            if(pq.size() == k) {
                if(it.second > pq.top().first) {
                    pq.pop();
                    pq.push(make_pair(it.second, it.first));
                }
            } else
                pq.push(make_pair(it.second, it.first));
        }
        
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
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

