# 找到二叉树中的最大BST子树
> Author ID.9276 

**问题关键词：**

- 

## 01 题目

## 题目描述

给定一颗二叉树，已知其中所有节点的值都不一样，找到含有节点最多的搜索二叉子树，输出该子树总节点的数量。

搜索二叉树是指对于二叉树的任何一个节点，如果它有儿子，那么左儿子的值应该小于它的值，右儿子的值应该大于它的值。

## 输入描述:

```
第一行输入两个整数 n 和 root，n 表示二叉树的总节点个数，root 表示二叉树的根节点。以下 n 行每行三个整数 fa，lch，rch，表示 fa 的左儿子为 lch，右儿子为 rch。(如果 lch 为 0 则表示 fa 没有左儿子，rch同理)ps:节点的编号就是节点的值。
```

## 输出描述:

```
1 \leq n \leq 10000001≤n≤10000001 \leq fa,lch,rch,root \leq n1≤fa,lch,rch,root≤n
```

示例1

## 输入

[复制](javascript:void(0);)

```
3 2
2 1 3
1 0 0
3 0 0
```

## 输出

[复制](javascript:void(0);)

```
3
```

## 02 分析

- 树型 DP

## 03 题解

### 基础：

```c++
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <climits>

using namespace std;


class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int num) : val(num), left(nullptr), right(nullptr) {}
};

class ReturnType { // record the max sub BST info.
public:
    TreeNode *head; // BST root
    int size; // BST size
    int rmin; // min num in right sub tree
    int lmax; // max num in left sub tree

    ReturnType(TreeNode *node, int size, int rmin, int lmax) :
            head(node), size(size), rmin(rmin), lmax(lmax) {}
};

ReturnType *process(TreeNode *root) {
    if (root == nullptr) {
        ReturnType *ret = new ReturnType(nullptr, 0, INT_MAX, INT_MIN);
        return ret;
    }

    ReturnType *leftData = process(root->left);
    ReturnType *rightData = process(root->right);

    int minNum = min(root->val, min(leftData->rmin, rightData->rmin));
    int maxNum = max(root->val, max(leftData->lmax, rightData->lmax));

    int maxBSTSize = max(leftData->size, rightData->size);
    TreeNode *maxBSTHead = leftData->size >= rightData->size ?
                           leftData->head : rightData->head;

    if (leftData->head == root->left && rightData->head == root->right &&
        leftData->lmax < root->val && root->val < rightData->rmin) {
        maxBSTSize = leftData->size + rightData->size + 1;
        maxBSTHead = root;
    }

    ReturnType *ret = new ReturnType(maxBSTHead, maxBSTSize, minNum, maxNum);
    return ret;
}

int maxSubBST(TreeNode *root) {
    return process(root)->size;
}

int main() {
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

    // solver
    cout << maxSubBST(root);

    return 0;
}
```



### 优化：



## 04 总结

