# 和为S的两个数
> Author ID.9276 

**问题关键词：**

- 

## 01 题目


输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。

## 输出描述:

```
对应每个测试案例，输出两个数，小的先输出。
```

## 02 输入分析



## 03 解题思路

### 3.1 基础解法

- 双指针法

```c++
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> ans;
        if(array.size() == 0) return ans;
        
        int l = 0, r = array.size() - 1;
        while(l < r) {
            if(array[l] + array[r] < sum)
                l++;
            else if(array[l] + array[r] > sum)
                r--;
            else {
                ans.push_back(array[l]);
                ans.push_back(array[r]);
                break;
            }
        }
        
        return ans;
    }
};
```



### 3.2 优化



## 04 问题总结

