# 高度最小的BST
> Author ID.9276 

**问题关键词：**

- 

## 01 题目

对于一个元素各不相同且按升序排列的有序序列，请编写一个算法，创建一棵高度最小的二叉查找树。

给定一个有序序列int[] **vals**,请返回创建的二叉查找树的高度。

## 02 分析



## 03 题解

### 基础：学会去对数

```c++
class MinimalBST {
public:
    int buildMinimalBST(vector<int> vals) {
        int len = vals.size();
        int count = 0;
        
         while(len > 0) {
             len = len >> 1;
             count++;
         }

        return count;
    }
};
```



### 优化：



## 04 总结

