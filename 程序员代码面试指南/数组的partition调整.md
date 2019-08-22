# 数组的partition调整
**问题关键词：**

- 顺序扫描

## 01 题目

## 题目描述

给定一个有序数组arr，调整arr使得这个数组的左半部分[1, \frac{n+1}{2}][1,2*n*+1]没有重复元素且升序，而不用保证右部分是否有序

例如，arr = [1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 7, 7, 8, 8, 8, 9]，调整之后arr=[1, 2, 3, 4, 5, 6, 7, 8, 9, .....]。

[要求]

时间复杂度为O(n)*O*(*n*)，空间复杂度为O(1)*O*(1)



## 输入描述:

```
第一行一个整数N。表示数组长度。接下来一行N个整数，表示数组内元素
```

## 输出描述:

```
输出N个整数为答案数组
```

示例1

## 输入

[复制](javascript:void(0);)

```
16
1 2 2 2 3 3 4 5 6 6 7 7 8 8 8 9
```

## 输出

[复制](javascript:void(0);)

```
1 2 3 4 5 6 7 8 9 6 2 7 2 8 8 3
```

示例2

## 输入

[复制](javascript:void(0);)

```
5
2 3 4 4 5
```

## 输出

[复制](javascript:void(0);)

```
2 3 4 5 4
```

## 备注:

```
1 \leqslant N \leqslant 10^51⩽N⩽1051 \leqslant arr_i \leqslant 10^91⩽arri⩽109本题有special judge，对于右边的部分，你可以任意输出(在保证合法的前提下)
```

## 02 分析

- 数组有序，因此顺序扫描数组，遇到和锚节点不同的元素就将其加入锚节点的下一个位置

## 03 题解

### 基础：

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solver(vector<int> &nums, int n) {
    int i = 0;
    for (int j = 1; j < n; ++j) {
        if (nums[i] != nums[j]) {
            i++;
            swap(nums[i], nums[j]);
        }
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

