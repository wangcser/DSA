# 维护x的秩
> Author ID.9276 

**问题关键词：**

- 

## 01 题目

现在我们要读入一串数，同时要求在读入每个数的时候算出它的秩，即在当前数组中小于等于它的数的个数(不包括它自身)，请设计一个高效的数据结构和算法来实现这个功能。

给定一个int数组**A**，同时给定它的大小**n**，请返回一个int数组，元素为每次加入的数的秩。保证数组大小小于等于5000。

测试样例：

```
[1,2,3,4,5,6,7],7
返回：[0,1,2,3,4,5,6]
```

## 02 分析



## 03 题解

### 基础：遍历统计即可

- 注意和叠罗汉相区别

```c++
class Rank {
public:
    vector<int> getRankOfNumber(vector<int> A, int n) {
        // write code here
        vector<int> count(n, 0);

        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (A[i] >= A[j]) {
                    count[i]++;
                }
            }
        }

        return count;
    }
};
```

### 优化：BST



## 04 总结

https://www.nowcoder.com/questionTerminal/0ade0d95c85349beb934a90b1d9b02be?f=discussion