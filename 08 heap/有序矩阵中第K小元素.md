# 有序矩阵中第K小元素
关键词：

- topK

## 01 题目

给定一个 *n x n* 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
请注意，它是排序后的第k小元素，而不是第k个元素。

**示例:**

```
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

返回 13。
```

**说明:** 
你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n2 。

## 02 分析

- 对于一个最小堆，堆顶的元素为堆内元素中最小的，因此我们如果能够将 matrix 中所有元素装入堆，然后**取出第 k 次的堆顶即可得到我们的答案**

- 注意这是一个有序矩阵，因此每一行的向量都是有序的，头部位置的值是最小的，然后向右递增

- 因此我们可以**用有序的特点进行优化**，不需要把所有的元素都放入堆中（赛马问题）：
  - 先放入所有向量的头元素，比较出最小的元素，这也是所有元素中最小的元素
  - 然后**利用该最小的元素找到第二小的元素**，思路如下：
    - 将最小元素后面的那个元素入堆，假设该元素不为次小元素，则次小元素必为其他向量的头元素，入堆后该头元素自动恢复到堆顶
    - 假设该元素为次小元素，的证
  - **每次将最小元素的下一个元素入堆**
- 这个策略只需要入堆 K 个元素

## 03 题解

### 基础：

- 堆元素设计为：[值，位于那个向量，位于那个位置]

```c++
//version 1.0 0.0%
class Solution {
public:
    struct Comp{
        bool operator()(const vector<int> &x, const vector<int> &y) const{
            return x[0] > y[0];
        }
    };
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        priority_queue<vector<int>, vector<vector<int>>, Comp> minHeap;
        
        for(int i = 0; i < m; i++) {
            minHeap.push(vector<int> {matrix[i][0], i, 0});
        }
        
        int ans = 0;
        for(int i = 0; i < k; i++) {
            vector<int> x = minHeap.top();
            minHeap.pop();
            ans = x[0];
            if(x[2] < m - 1) {
                x[2]++;
                x[0] = matrix[x[1]][x[2]];
                minHeap.push(x);
            }
        }
        
        return ans;
    }
};
```

## 04 总结

