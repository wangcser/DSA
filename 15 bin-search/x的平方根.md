# x的平方根
> Author ID.9276

## 01 题目

实现 `int sqrt(int x)` 函数。

计算并返回 *x* 的平方根，其中 *x* 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

**示例 1:**

```
输入: 4
输出: 2
```

**示例 2:**

```
输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
```

## 02 分析



## 03 题解

### 3.1 C++

```c++
class Solution {
public:
    int mySqrt(int x) {
        if(x < 0) return -1;
        
        int l = 0, r = x;
        int target = (int) sqrt(x);
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(mid == target) return mid;
            else if(mid < target) l = mid + 1;
            else r = mid - 1;
        }
        
        return -1;
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

