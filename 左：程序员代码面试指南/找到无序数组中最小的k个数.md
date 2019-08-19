# 找到无序数组中最小的k个数
> Author ID.9276 

**问题关键词：**

- 

## 01 题目

## 题目描述

给定一个整型数组arr，找到其中最小的k个数。

## 输入描述:

```
输入包含两行，第一行包含两个整数n和k(1 \leq k \leq n \leq 10^5)(1≤k≤n≤105)，代表数组arr的长度，第二行包含n个整数，代表数组arr(1 \leq arr_i \leq 10^9)(1≤arri≤109)。
```

## 输出描述:

```
输出包含一行，k个整数，代表数组中最小的k个整数。
```

示例1

## 输入

[复制](javascript:void(0);)

```
5 3
3 5 1 5 2
```

## 输出

[复制](javascript:void(0);)

```
3 1 2
```

## 备注:

```
时间复杂度O(nlog_2k)和O(n)O(nlog2k)和O(n)，额外空间复杂度O(n)O(n)。
```

## 02 分析



## 03 题解

### 基础：注意堆的使用

```c++
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

void solver(vector<int> &nums, int n, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto num : nums)
        pq.push(num);

    while (k--) {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    solver(nums, n, k);

    return 0;
}
```



### 优化：



## 04 总结

