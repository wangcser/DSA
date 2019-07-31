# 检查是否为BST
> Author ID.9276 

**问题关键词：**

- 

## 01 题目



## 02 分析



## 03 题解

### 基础：递归 - 注意定义中指的是子树的最值

```c++
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Checker {
public:
    bool checkBST(TreeNode* root) {
        if(!root) return true;

        if(root->left && leftMax(root->left) > root->val)
            return false;
        if(root->right && rightMin(root->right) < root->val)
            return false;

        return checkBST(root->left) && checkBST(root->right);
    }

    int leftMax(TreeNode* root) {
        if(root == nullptr) return INT_MAX;

        while(root->right) {
            root = root->right;
        }

        return root->val;
    }

    int rightMin(TreeNode* root) {
        if(root == nullptr) return INT_MIN;

        while(root->left) {
            root = root->left;
        }

        return root->val;
    }
};
```

### 优化：中序遍历 + 实时判断

```c++
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Checker {
public:
    bool checkBST(TreeNode* root) {
        if(!root) return true;

        if(!checkBST(root->left)) return false;
        
        if(root->val >= curMax)
            curMax = root->val;
        else return false;

        if(!checkBST(root->right)) return false;

        return true;
    }
private:
    int curMax = INT_MIN;
};
```





## 04 总结

