# N叉树的最大深度
> Author ID.9276

## 01 题目

给定一个 N 叉树，找到其最大深度。

最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。

例如，给定一个 `3叉树` :

 

![img](assets/narytreeexample-1555232041531.png)

 

我们应返回其最大深度，3。

**说明:**

1. 树的深度不会超过 `1000`。
2. 树的节点总不会超过 `5000`。

## 02 分析



## 03 题解

### 3.1 C++

```c++
//version 1.0 0.0%

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        int res = 1;
        for (Node* child : root->children) {
            res = max(res, maxDepth(child) + 1);
        }
        return res;
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

