# 删除链表的倒数第N个节点 

> Author：ID.9276

## 01 题目

给定一个链表，删除链表的倒数第 *n* 个节点，并且返回链表的头结点。

**示例：**

```
给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
```

**说明：**

给定的 *n* 保证是有效的。

**进阶：**

你能尝试使用一趟扫描实现吗？

## 02 分析

常规思路：先用一次扫描定位，再删除

- 这里头指针代表第一个节点，并非空节点！！！
- 子节点删除法不能处理尾节点，因此这里将头节点特殊考虑，其他节点采用父节点删除法

## 03 题解

### 3.1 C++

```c++
// version 1.0 90.55%

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur = head; //头指针代表第一个节点，并非首节点
        int count = 1;
        int posi;
        
        while(true){
            if(cur->next == NULL) break;
            count++;
            cur = cur->next;
        }

        if(count == 1 && n == 1){
            head = NULL;
            return head;
        }
        
        posi = count - n + 1;
        cur = head;
        
        if(posi == 1){ // 删除头节点的情况，特殊考虑
            cur->val = cur->next->val;
            cur->next = cur->next->next;
            return head;
        }
        
        for(int i=2; i<posi; i++) {
            cur = cur->next;
        }

        // 利用父节点进行删除
        cur->next = cur->next->next;
        
        return head;
    }
};
```

```
// version 2.0 100%
//优化了头节点的删除逻辑，并增加了删除节点的空间释放
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur = head; //头指针代表第一个节点，并非首节点
        int count = 1;
        int posi;
        
        while(true){
            if(cur->next == NULL) break;
            count++;
            cur = cur->next;
        }

        if(count == 1 && n == 1){
            head = NULL;
            return head;
        }
        
        posi = count - n + 1;
        cur = head;
        
        if(posi == 1){ // 删除头节点的情况，特殊考虑
            return head->next;
        }
        
        for(int i=2; i<posi; i++) {
            cur = cur->next;
        }

        // 利用父节点进行删除
        ListNode *delNode = cur->next;
        cur->next = cur->next->next;
        delete delNode;
        
        return head;
    }
};
```



### 3.2 Python 3

```python
# version 1.0 


```

### 3.3 Java

```java
// version 1.0

```



## 04 总结

