# N叉树的最大深度
关键词：

- 递归遍历
- 树的深度

## 01 题目

给定一个 N 叉树，找到其最大深度。

**最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。**

例如，给定一个 `3叉树` :

 

![img](N叉树的最大深度.assets/narytreeexample.png) 

我们应返回其最大深度，3。

**说明:**

1. 树的深度不会超过 `1000`。
2. 树的节点总不会超过 `5000`。

## 02 分析

- 遍历过程中更新每个节点的深度
- 使用全局变量记录最大深度

上面的思路如何实现呢？

- 问题转化为每棵子树的最大深度问题：**对于一棵树，root 的最大深度为其子树最大深度 + 1**

## 03 题解

### 基础

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

## 04 总结

