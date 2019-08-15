# 二叉树的层次打印和zigzag打印
> Author ID.9276 

**问题关键词：**

- 

## 01 题目

## 题目描述

给定一颗二叉树，分别实现按层和 ZigZag 打印二叉树。

ZigZag遍历: 意思是第一层从左到右遍历，第二层从右到左遍历，依次类推。

## 输入描述:

```
第一行输入两个整数 n 和 root，n 表示二叉树的总节点个数，root 表示二叉树的根节点。以下 n 行每行三个整数 fa，lch，rch，表示 fa 的左儿子为 lch，右儿子为 rch。(如果 lch 为 0 则表示 fa 没有左儿子，rch同理)
```

## 输出描述:

```
先输出按层打印，再输出按ZigZag打印。
```

示例1

## 输入

[复制](javascript:void(0);)

```
8 1
1 2 3
2 4 0
4 0 0
3 5 6
5 7 8
6 0 0
7 0 0
8 0 0
```

## 输出

[复制](javascript:void(0);)

```
Level 1 : 1
Level 2 : 2 3
Level 3 : 4 5 6
Level 4 : 7 8
Level 1 from left to right: 1
Level 2 from right to left: 3 2
Level 3 from left to right: 4 5 6
Level 4 from right to left: 8 7
```

## 备注:

```
1 \leq n \leq 5000001≤n≤5000001 \leq fa,lch,rch,root \leq n1≤fa,lch,rch,root≤n
```

## 02 分析



## 03 题解

### 基础：queue 和 deque

```c++
#include <iostream>
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

void layerorder(TreeNode *root) {
    if (!root) return;

    queue<TreeNode *> que;
    que.push(root);
    int level = 1;

    while (!que.empty()) {
        int size = que.size();
        cout << "Level " << level << " : ";
        while (size--) {
            TreeNode *cur = que.front();
            que.pop();
            // do something
            cout << cur->val << " ";
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
        cout << endl;
        level++;
    }
}

void zigzagorder(TreeNode *root) {
    if (!root) return;

    deque<TreeNode *> st;
    st.push_back(root);
    int level = 1;

    while (!st.empty()) {
        int size = st.size();
        if(level % 2 == 1) {
            cout << "Level " << level << " from left to right: ";
            while (size--) {
                TreeNode *cur = st.front();
                st.pop_front();
                cout << cur->val << " ";

                if (cur->left) st.push_back(cur->left);
                if (cur->right) st.push_back(cur->right);
            }
        } else {
            cout << "Level " << level << " from right to left: ";
            while (size--) {
                TreeNode *cur = st.back();
                st.pop_back();
                cout << cur->val << " ";

                if (cur->right) st.push_front(cur->right);
                if (cur->left) st.push_front(cur->left);
            }
        }
        cout << endl;
        level++;
    }
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
    layerorder(root);
    zigzagorder(root);

    return 0;
}
```



### 优化：



## 04 总结

