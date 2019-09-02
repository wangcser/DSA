# 数据流中第K大的元素
关键词：

- topK

## 01 题目

设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。

你的 `KthLargest` 类需要一个同时接收整数 `k` 和整数数组`nums` 的构造器，它包含数据流中的初始元素。每次调用 `KthLargest.add`，返回当前数据流中第K大的元素。

## 02 分析

对于找第 k 大元素的问题，有下面几种思路：

- 排序后返回 k 处的值
- 使用 BST
- 使用堆结构，对于最大堆返回最后元素即可
- 使用快速排序的切分方法，查找到 k 位置的元素

这个问题有些特殊，因为输入是流，因此可以采用下面两种方法：

- BST
  - BST 的插入操作很简单，关键在于在 BST 中查找第 K 大元素。
    - 方法一，中序遍历返回第 k 个元素
    - 方法二，构造树的时候记录每个节点下面的子节点数量，利用这个值来查找
- heap
  - 这里使用小顶堆，方便堆操作，堆顶就是第 k 大元素



## 03 题解

### 基础

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
            
            if(right_count > count - 1) cur = cur->right; // right elements more the k
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

```
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        heap_k = k;
        for(int i = 0; i < nums.size(); i++) {
            minHeap.push(nums[i]); 
            if(i > k - 1)
                minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > heap_k)
            minHeap.pop();
        
        return minHeap.top();
    }

private:
    int heap_k;
    priority_queue<int,vector<int>,greater<int>> minHeap; //小顶堆 从栈顶到栈底是递增 int k
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```

## 04 总结

