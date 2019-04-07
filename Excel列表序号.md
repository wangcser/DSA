# 求众数

> Author ID.9276

## 01 题目

给定一个Excel表格中的列名称，返回其相应的列序号。

例如，

```
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
```

**示例 1:**

```
输入: "A"
输出: 1
```

**示例 2:**

```
输入: "AB"
输出: 28
```

**示例 3:**

```
输入: "ZY"
输出: 701
```

**致谢：**
特别感谢 [@ts](http://leetcode.com/discuss/user/ts) 添加此问题并创建所有测试用例。

## 02 分析

- 26 进制啦
- 摩尔投票
  - 由于有一类的数量大于整体的一半，因此不断消去不同的元素对，剩下的就是目标值
  - 这里的 c 代表抵消的情况

## 03 题解

### 3.1 C++

```c++
class Solution {
public:
    int titleToNumber(string s) {
        
        int ans = 0;
        int c = 26;
        int val = 0;
        
        for(int i = s.size() - 1; i >= 0; i--) {
            
            val = s[i] - 'A' + 1;
            ans += pow(26, s.size() - 1 - i) * val;
        }
        
        return ans;
    }
};
```



```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int c = 0, m = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            
            if(c == 0) m = nums[i];
            
            if(nums[i] == m) c++;
            else c--;
        }
        
        return m;
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

