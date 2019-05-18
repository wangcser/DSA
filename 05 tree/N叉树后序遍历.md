# N叉树后序遍历
> Author ID.9276

## 01 题目

给定一个 N 叉树，返回其节点值的*后序遍历*。

例如，给定一个 `3叉树` :

 

![img](assets/narytreeexample-1555231262397.png)

 

返回其后序遍历: `[5,6,3,2,4,1]`.

 

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

### 3.2 Python 3

```python
# version 1.0 0.0%

```

### 3.3 Go

```Go
//version 1.0 0.0%

```



## 04 总结

