# N叉树后序遍历
关键词：

- 递归遍历

## 01 题目

给定一个 N 叉树，返回其节点值的*后序遍历*。

例如，给定一个 `3叉树` :

![img](N叉树后序遍历.assets/narytreeexample.png) 

返回其后序遍历: `[5,6,3,2,4,1]`.

**说明:** 递归法很简单，你可以使用迭代法完成此题吗?

## 02 分析

- 先访问当前 root 的所有子树，然后访问 root

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
    vector<int> postorder(Node* root) {
        
        vector<int> ans;
        porder(root, ans);
        return ans;
    }
    
    void porder(Node* root, vector<int>& ans) {
        if(!root) return;
        
        for(auto child : root->children) {
            porder(child, ans);
        }
        ans.push_back(root->val);
    }
};
```

## 04 总结

