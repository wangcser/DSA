# 数组的partition调整2
**问题关键词：**

- partition

## 01 题目

## 题目描述

给定一个数组arr，其中只可能含有0、1、2三个值，请实现arr的排序

[要求]

时间复杂度为O(n)*O*(*n*)，空间复杂度为O(1)*O*(1)



## 输入描述:

```
第一行一个整数N。表示数组长度接下来一行N个整数表示数组内的数
```

## 输出描述:

```
输出N个整数，表示排序后的结果
```

示例1

## 输入

[复制](javascript:void(0);)

```
5
2 0 1 2 0
```

## 输出

[复制](javascript:void(0);)

```
0 0 1 2 2
```

## 备注:

```
1 \leqslant N \leqslant 10^51⩽N⩽105\text{保证} arr_i = 0/1/2保证arri=0/1/2
```

## 02 分析

- 三路扫描法
- 这个题很细节的，使用三个指针进行 partition 操作

## 03 题解

### 基础：

```c++
#include <iostream>
#include <vector>

using namespace std;

void solver(vector<int> &nums, int n) {
    int l = -1, cur = 0, r = n;
    while (cur < r) {
        if (nums[cur] == 0) {
            l++;
            swap(nums[cur], nums[l]);
            cur++;
        } else if (nums[cur] == 2) {
            r--;
            swap(nums[cur], nums[r]);
        } else
            cur++;
    }

    for (auto num : nums)
        cout << num << " ";
}


int main() {
    int n;
    cin >> n;

    int num;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> num;
        nums[i] = num;
    }

    solver(nums, n);

    return 0;
}

```



### 优化：



## 04 总结

