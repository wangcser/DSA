# 链式APlusB
> Author ID.9276 

**问题关键词：**

- 

## 01 题目

有两个用链表表示的整数，每个结点包含一个数位。这些数位是反向存放的，也就是个位排在链表的首部。编写函数对这两个整数求和，并用链表形式返回结果。

给定两个链表ListNode* **A**，ListNode* **B**，请返回A+B的结果(ListNode*)。

测试样例：

```
{1,2,3},{3,2,1}
返回：{4,4,4}
```

## 02 分析



## 03 题解

### 基础：按位计算即可，注意链表操作的正确性

```c++
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
        if(a == nullptr) return b;
        if(b == nullptr) return a;

        ListNode* ansHead = new ListNode(-1);
        ListNode* cur = ansHead;
        int sum = 0;
        int carray = 0;

        while(a && b) {
            sum = (a->val + b->val + carray) % 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
            carray = (a->val + b->val + carray) / 10;

            a = a->next;
            b = b->next;
            
        }

        ListNode* tailcur = nullptr;
        if(a != nullptr) tailcur = a;
        else if(b != nullptr) tailcur = b;
        
        while(tailcur) {
            cur->next = new ListNode(tailcur->val + carray % 10);
            carray = (tailcur->val + carray) / 10;
            cur = cur->next;
            tailcur = tailcur->next;
            
        }
        
        if(carray) {
            cur->next = new ListNode(carray);
            cur = cur->next;
        }
        
        cur->next = nullptr;

        return ansHead->next;
    }
};
```



### 优化：



## 04 总结

