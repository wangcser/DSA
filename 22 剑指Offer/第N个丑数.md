# 第N个丑数
> Author ID.9276 

**问题关键词：**

- 

## 01 题目

把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

## 02 输入分析



## 03 解题思路

### 3.1 基础解法



### 3.2 优化 - DP

- 每一个丑数都是之前的丑数乘以丑数因子得到的

```c++
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index == 0) return 0;
        
        vector<int> ugList;
        vector<int> factor{2, 3, 5};

        ugList.push_back(1);

        while(index > 1) {
            nextUgNum(ugList, factor);
            index--;
        }

        return ugList.back();
    }

    void nextUgNum(vector<int>& ugList, vector<int>& factor) {
        int preUg = ugList.back();
        int nextUg = INT_MAX;
        int tmp = 0;

        for(int i = 0; i < ugList.size(); ++i) {
            for(int j = 0; j < factor.size(); ++j) {
                tmp = ugList[i] * factor[j];
                if(tmp > preUg)
                    nextUg = min(nextUg, tmp);
            }
        }

        ugList.push_back(nextUg);
    }
};
```



## 04 问题总结

