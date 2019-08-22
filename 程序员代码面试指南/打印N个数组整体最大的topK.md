# 打印N个数组整体最大的topK
**问题关键词：**

- 

## 01 题目

## 题目描述

有N个长度不一的数组，所有的数组都是有序的，请从大到小打印这N个数组整体最大的前K个数。

例如，输入含有N行元素的二维数组可以代表N个一维数组。

219, 405, 538, 845, 971

148, 558

52, 99, 348, 691

再输入整数k=5，则打印：

Top 5: 971, 845, 691, 558, 538

[要求]

时间复杂度为O(k \log k)*O*(*k*log*k*)，空间复杂度为O(k \log k)*O*(*k*log*k*)



## 输入描述:

```
第一行两个整数T, K。分别表示数组个数，需要打印前K大的元素接下来T行，每行输入格式如下：开头一个整数N，表示该数组的大小，接下来N个已排好序的数表示数组内的数
```

## 输出描述:

```
从大到小输出输出K个整数，表示前K大。
```

示例1

## 输入

[复制](javascript:void(0);)

```
3 5
5 219 405 538 845 971
2 148 558
4 52 99 348 691
```

## 输出

[复制](javascript:void(0);)

```
971 845 691 558 538
```

## 备注:

```
1 \leqslant \text{数组内数的总个数} \leqslant 10^51⩽数组内数的总个数⩽1050 \leqslant  \text{数组内元素} \leqslant 10^90⩽数组内元素⩽109保证各个输入值合法
```

## 02 分析

- 把所有数据当成一个输入流即可，转化为典型的 topK 问题

## 03 题解

### 基础：

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; ++i) {
        int len;
        cin >> len;

        int num;
        for (int j = 0; j < len; ++j) {
            cin >> num;
            if (minHeap.size() < k)
                minHeap.push(num);
            else {
                if (num > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(num);
                }
            }
        }
    }

    stack<int> st;

    while (!minHeap.empty()) {
        st.push(minHeap.top());
        minHeap.pop();
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}

```



### 优化：



## 04 总结

