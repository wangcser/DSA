# 合并K个排序链表
> Author ID.9276

## 01 题目

合并 *k* 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

**示例:**

```
输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
```

## 02 分析

最小堆 + k 路合并（归并）

注意容器的使用

## 03 题解

### 3.1 C++

```c++
//version 1.0 0.0%
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct Comp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val >= b->val;
        }  
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode* , vector<ListNode*>, Comp> minHeap;
        
        ListNode dummyHead(0);
        
        // add all list head into heap
        for(auto node : lists) {
            if(node) minHeap.push(node);
        }
        
        // merge with heap
        auto p = &dummyHead;
        while(!minHeap.empty()) {
            
            ListNode* node = minHeap.top();
            minHeap.pop();
            p->next = node;
            p = node;
            
            if(node->next)
                minHeap.push(node->next);
        }
        
        return dummyHead.next;
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

