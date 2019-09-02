# N叉树前序遍历
关键词：

- 树的遍历

## 01 题目

给定一个 N 叉树，返回其节点值的*前序遍历*。

例如，给定一个 `3叉树` :

 ![img](N叉树前序遍历.assets/narytreeexample.png)

返回其前序遍历: `[1,3,5,6,2,4]`。

**说明:** 递归法很简单，你可以使用迭代法完成此题吗?

## 02 分析

- 先访问 root，再访问所有子树

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
    vector<int> preorder(Node* root) {
        
        vector<int> ans;
        porder(root, ans);
        return ans;
    }
    
    void porder(Node* root, vector<int>& ans) {
        if(!root) return;
        
        ans.push_back(root->val);
        for(auto child : root->children) {
            porder(child, ans);
        }
    }
};
```

## 04 总结

