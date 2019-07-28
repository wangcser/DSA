# 链表中倒数第k个节点
> Author ID.9276 

**问题关键词：**

- 

## 01 题目

输入一个链表，输出该链表中倒数第k个结点。

## 02 输入分析

本题难点在于边界条件的检查

## 03 解题思路

### 3.1 基础解法

```c++
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL) return NULL;
        if(k < 1) return NULL;
        
        ListNode* slow = pListHead;
        ListNode* fast = pListHead;
        
        while(k > 1 && fast->next != NULL) {
            fast = fast->next;
            k--;
        }
        if(fast->next == NULL && k > 1) return NULL;
        
        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};
```



### 3.2 优化



## 04 问题总结

