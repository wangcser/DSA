# N皇后
> Author ID.9276

## 01 题目

*n* 皇后问题研究的是如何将 *n* 个皇后放置在 *n*×*n* 的棋盘上，并且使皇后彼此之间不能相互攻击。

![img](assets/8-queens.png)

上图为 8 皇后问题的一种解法。

给定一个整数 *n*，返回所有不同的 *n* 皇后问题的解决方案。

每一种解法包含一个明确的 *n* 皇后问题的棋子放置方案，该方案中 `'Q'` 和 `'.'` 分别代表了皇后和空位。

**示例:**

```
输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
```

## 02 分析

排列组合问题

## 03 题解

### 3.1 C++

```c++
//version 1.0 0.0%

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> queens(n);
        vector<vector<string>> ans(n, vector<string> (n, "."));
        bool noConflict = false;
        
        for(int i = 0; i < n; i++) {
            queens[i] = i;
        }
        
        // range queen        
        // rangeQueens(queens);
        
        // set output
        setQueen(queens, ans);
        
        return ans;
    }
    
    void setQueen(vector<int>& q, vector<vector<string>>& ans) {
        for(int i = 0; i < q.size(); i++) {
            int j = q[i];
            ans[i][j] = "Q";
        }
    }
};
```

### 3.2 Python 3

```python
# version 1.0 0.0%

```

### 3.3 Go

```Go
//version 1.0 0.0%

```



## 04 总结

