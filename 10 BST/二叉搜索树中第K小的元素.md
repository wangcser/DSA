# 二叉搜索树中第K小的元素
> Author ID.9276 

**问题关键词：**

- BST 中序遍历
- 提前终止

## 01 题目

给定一个二叉搜索树，编写一个函数 `kthSmallest` 来查找其中第 **k** 个最小的元素。

**说明：**
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

**示例 1:**

```
输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1
```

**示例 2:**

```
输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 3
```

**进阶：**
如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 `kthSmallest` 函数？

## 02 输入分析



## 03 解题思路

### 3.1 基础思路



### 3.2 算法优化



## 04 核心代码

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = 0;
        inorder(root, count, k, ans);
        
        return ans; 
    }
    
    void inorder(TreeNode* root, int& count, int k, int& ans) {
        if(root == NULL) return;
        
        inorder(root->left, count, k, ans);
        // do something
        count++;
        
        if(count == k) {
            ans = root->val;
            return;
        }
        
        inorder(root->right, count, k, ans);
    }
};
```



## 05 算法效率分析



## 06 问题总结

