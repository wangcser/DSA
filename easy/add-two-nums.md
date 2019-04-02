# add-two-nums
> Author ID.9276

## 01 题目

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order** and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Example:**

```
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
```

## 02 分析



## 03 题解

### 3.1 C++

```c++
// version 1.0 0.0%
// 执行用时 : 44 ms, 在Add Two Numbers的C++提交中击败了64.96% 的用户
// 内存消耗 : 10.8 MB, 在Add Two Numbers的C++提交中击败了0.94% 的用户
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int dig = 0;
        vector<int> ans;
        
        while(true) {
            
            // tail of the SLL
            if(l1->next == NULL && l2->next == NULL) {

                sum = (l1->val + l2->val + dig) % 10;
                dig = (l1->val + l2->val + dig) / 10;
                ans.push_back(sum);

                if(dig == 1) ans.push_back(dig);
            
                break;
            }
            
            // body of the SLL
            sum = (l1->val + l2->val + dig) % 10;
            dig = (l1->val + l2->val + dig) / 10;
            ans.push_back(sum);
            
            // for async case
            if(l1->next != NULL) l1 = l1->next;
            else l1->val = 0;
            
            if(l2->next != NULL) l2 = l2->next;
            else l2->val = 0;
        }
        
        // head can't be moved.
        ListNode* head=new ListNode(0);
        // use temp ptr to connect node
        ListNode* cur=head;
        
        for(int i=0; i<ans.size(); i++){
            ListNode* tmp = new ListNode(0);
            tmp->val = ans[i];            
            // connect to temp
            cur->next = tmp;
            cur = tmp;
        }
        
        return head->next;
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

