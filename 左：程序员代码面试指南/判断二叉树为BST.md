# 判断二叉树为BST
> Author ID.9276 

**问题关键词：**

- 

## 01 题目

## 题目描述

平衡二叉树的性质为: 要么是一棵空树，要么任何一个节点的左右子树高度差的绝对值不超过 1。给定一棵二叉树，判断这棵二叉树是否为平衡二叉树。

一颗树的高度指的是树的根节点到所有节点的距离中的最大值。



## 输入描述:

```
第一行输入两个整数 n 和 root，n 表示二叉树的总节点个数，root 表示二叉树的根节点。以下 n 行每行三个整数 fa，lch，rch，表示 fa 的左儿子为 lch，右儿子为 rch。(如果 lch 为 0 则表示 fa 没有左儿子，rch同理)
```

## 输出描述:

```
如果是平衡二叉树则输出 "true"，否则输出 "false"。
```

示例1

## 输入

[复制](javascript:void(0);)

```
3 2
1 2 3
```

## 输出

[复制](javascript:void(0);)

```
true
```

## 备注:

```
1 \leq n \leq 5000001≤n≤5000001 \leq fa,lch,rch,root \leq n1≤fa,lch,rch,root≤n
```

## 02 分析



## 03 题解

### 基础：

```c++
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <climits>

using namespace std;


class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int num) : val(num), left(nullptr), right(nullptr) {}
};

TreeNode *readTree() {
    // read tree
    int n, r;
    map<int, TreeNode *> nodeMap;

    scanf("%d%d", &n, &r);
    //  create node and store it into dict
    for (int i = 1; i <= n; ++i) {
        TreeNode *newNode = new TreeNode(i);
        nodeMap[i] = newNode;
    }

    TreeNode *root = nodeMap[r];

    // build tree:use dict to link node
    int parent, lchild, rchild;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &parent, &lchild, &rchild); // ctrl + z is EOF
        if (lchild != 0) nodeMap[parent]->left = nodeMap[lchild];
        if (rchild != 0) nodeMap[parent]->right = nodeMap[rchild];
    }

    return root;
}

class ReturnType {
public:
    bool isBalanced;
    int height;

    ReturnType(bool state, int h) : isBalanced(state), height(h) {}
};

class Solver {
public:
    ReturnType *process(TreeNode *root) {
        if (!root) {
            return new ReturnType(true, 0);
        }

        ReturnType *leftData = process(root->left);
        ReturnType *rightData = process(root->right);

        int height = max(leftData->height, rightData->height) + 1;
        bool isBalanced = leftData->isBalanced && rightData->isBalanced &&
                          abs(leftData->height - rightData->height) < 2;

        return new ReturnType(isBalanced, height);
    }

    bool solve(TreeNode *root) {
        return process(root)->isBalanced;
    }

private:

};

int main() {
    TreeNode *root = readTree();

    // solver
    Solver solver;
    bool ans = solver.solve(root);

    if (ans) cout << "true";
    else cout << "false";
    return 0;
}
```



### 优化：



## 04 总结

