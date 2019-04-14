# N叉树前序遍历
> Author ID.9276

## 01 题目

给定一个 N 叉树，返回其节点值的*前序遍历*。

例如，给定一个 `3叉树` :

 

![img](assets/narytreeexample.png)

 

返回其前序遍历: `[1,3,5,6,2,4]`。

 

**说明:** 递归法很简单，你可以使用迭代法完成此题吗?

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

### 3.2 Python 3

```python
# version 1.0 0.0%

```

### 3.3 Go

```Go
//version 1.0 0.0%

```



## 04 总结

