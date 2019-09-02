# 最接近原点的K个点
关键词：

- topK
- sort

## 01 题目

我们有一个由平面上的点组成的列表 `points`。需要从中找出 `K` 个距离原点 `(0, 0)` 最近的点。

（这里，平面上两点之间的距离是欧几里德距离。）

你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。

 

**示例 1：**

```
输入：points = [[1,3],[-2,2]], K = 1
输出：[[-2,2]]
解释： 
(1, 3) 和原点之间的距离为 sqrt(10)，
(-2, 2) 和原点之间的距离为 sqrt(8)，
由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。
```

**示例 2：**

```
输入：points = [[3,3],[5,-1],[-2,4]], K = 2
输出：[[3,3],[-2,4]]
（答案 [[-2,4],[3,3]] 也会被接受。）
```

 

**提示：**

1. `1 <= K <= points.length <= 10000`
2. `-10000 < points[i][0] < 10000`
3. `-10000 < points[i][1] < 10000`

## 02 分析

- 用小顶堆最方便
- 这个问题的难点在于定义比较函数

## 03 题解

### 3.1 C++

方法一，使用排序，借助 lambda 函数定义比较函数

> 在新的 exp 上 timeout 啦

```c++
//version 1.0 0.0%
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        vector<vector<int>> ans;
        
        auto pow = [](int i) -> int {return i * i;};
        sort(points.begin(), points.end(), 
            [&](vector<int> v1, vector<int> v2) -> bool { return pow(v1[0]) + pow(v1[1]) < pow(v2[0]) + pow(v2[1]); });
        
        for(int i = 0; i < K; i++)
            ans.push_back(points[i]);
        
        return ans;
    }
};
```

优化一下复制机制，将 lambda 替换为比较函数

```
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        sort(points.begin(), points.end(), cmp);     
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
    
    static bool cmp(vector<int>&a, vector<int>&b) {        //排序方法
		 return sqrt(pow(a[0], 2) + pow(a[1], 2)) < sqrt(pow(b[0], 2) + pow(b[1], 2));
    }
};
```

## 04 总结

