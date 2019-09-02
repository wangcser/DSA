# 二叉搜索树中第k大元素
关键词：

- BST
- topK

## 01 题目

设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。

你的 `KthLargest` 类需要一个同时接收整数 `k` 和整数数组`nums` 的构造器，它包含数据流中的初始元素。每次调用 `KthLargest.add`，返回当前数据流中第K大的元素。

**示例:**

```
int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
```

**说明:** 
你可以假设 `nums` 的长度≥ `k-1` 且`k` ≥ 1。

## 02 分析

- 容器中会动态地插入数据，需要返回实时地 topK

## 03 题解

### 基础：

- 改造BST 节点，增加一个记录当前子树中有多少子节点的变量
  - 插入时，每向下搜索一层，就增加该计数器
  - 搜索时，先获取右侧点的数量，如果右侧点数量大于 K 个，那么 topK 位于右子树中
    - 依次更新 K 即可
- 通过该变量来获得 topK 的位置

```c++
//version 1.0 0.0%

class KthLargest {
public:
    struct TreeNode {
        int val;
        int count = 1;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
    TreeNode* root;
    int count;
    
    KthLargest(int k, vector<int>& nums) {   
        
        count = k;
        
        for(auto num : nums) {
            root = insertIntoBST(root, num);
        }
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(!root) return new TreeNode(val);
        
        if(root->val > val) root->left = insertIntoBST(root->left, val);
        else if(root->val < val) root->right = insertIntoBST(root->right, val);
        
        root->count += 1;
        return root;
    }
    
    int add(int val) {
        root = insertIntoBST(root, val);
        TreeNode* cur = root;
        int right_count;
        
        while(cur) {
            
            if(cur->right) right_count = cur->right->count;
            else right_count = 0;
            
            if(right_count > count - 1) cur = cur->right;
            else if(right_count < count - 1) {
                count = count - (right_count + 1);
                cur = cur->left;
            } else return cur->val;
            
        }
        
        return 0;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```

## 04 总结

