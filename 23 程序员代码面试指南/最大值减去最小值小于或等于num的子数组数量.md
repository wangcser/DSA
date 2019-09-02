# 最大值减去最小值小于或等于num的子数组数量
> Author ID.9276 

**问题关键词：**

- 

## 01 题目

## 题目描述

给定数组 arr 和整数 num，共返回有多少个子数组满足如下情况：

max(arr[i...j] - min(arr[i...j]) <= num

max(arr[i...j])表示子数组arr[i...j]中的最大值，min[arr[i...j])表示子数组arr[i...j]中的最小值。



## 输入描述:

```
第一行输入两个数 n 和 num，其中 n 表示数组 arr 的长度第二行输入n个整数X_iXi，表示数组arr中的每个元素
```

## 输出描述:

```
输出给定数组中满足条件的子数组个数
```

示例1

## 输入

[复制](javascript:void(0);)

```
5 2 
1 2 3 4 5
```

## 输出

[复制](javascript:void(0);)

```
12
```

## 说明

```

```

## 备注:

```
1\le n \le 10000001≤n≤1000000-1000000 \le arr_i \le 1000000−1000000≤arri≤10000000 \le num \le 20000000≤num≤2000000
```

## 02 分析

最值双端队列

## 03 题解

### 基础：

```c++
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <numeric>
#include <list>
#include <cmath>
#include <stack>
#include <ctime>
#include <queue>
#include <deque>

using namespace std;

int arrayNums(vector<int> &nums, int target) {
    int count = 0;
    deque<int> maxq;
    deque<int> minq;
    int i = 0, j = 0;

    while (i < nums.size()) {
        while (j < nums.size()) {
            while (!minq.empty() && nums[minq.back()] >= nums[j])
                minq.pop_back();
            minq.push_back(j);

            while (!maxq.empty() && nums[maxq.back()] <= nums[j])
                maxq.pop_back();
            maxq.push_back(j);

            if (nums[maxq.front()] - nums[minq.front()] > target) break;
            j++;
        }
        count += j - i;

        if (minq.front() == i) minq.pop_front();
        if (maxq.front() == i) maxq.pop_front();
        i++;
    }

    return count;
}


int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums;
    int num;

    while (n--) {
        cin >> num;
        nums.push_back(num);
    }

    cout << arrayNums(nums, target);

    return 0;
}
```



### 优化：



## 04 总结

