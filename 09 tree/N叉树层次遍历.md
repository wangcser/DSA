# N叉树层次遍历
关键词：

- 树的遍历
- queue

## 01 题目

给定一个 N 叉树，返回其节点值的*层序遍历*。 (即从左到右，逐层遍历)。

例如，给定一个 `3叉树` :

![img](N叉树层次遍历.assets/narytreeexample.png) 

返回其层序遍历:

```
[
     [1],
     [3,2,4],
     [5,6]
]
```

**说明:**

1. 树的深度不会超过 `1000`。
2. 树的节点总数不会超过 `5000`。

## 02 分析

- 看做 BFS 即可

## 03 题解

### 基础：

- 树的层次遍历就是其 BFS
- 使用 queue 辅助

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
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> ans;
        queue<Node*> q;
        
        if(!root) return ans;
        q.push(root);
        
        while(!q.empty()) {
            vector<int>layer;
            int n = q.size(); // will change in for-loop
            for(int i = 0; i < n; i++) {
                Node* t = q.front();
                q.pop();
                layer.push_back(t->val);
                
                for(auto child : t->children) {
                    q.push(child);
                }
            }
            ans.push_back(layer);
        }
        
        return ans;
    }
};
```

## 04 总结

