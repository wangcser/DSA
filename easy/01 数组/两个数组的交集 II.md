# 两个数组的交集 II 

> Author：ID.9276

## 01 题目

给定两个数组，写一个方法来计算它们的交集。

**例如:**
给定 *nums1* = `[1, 2, 2, 1]`, *nums2* = `[2, 2]`, 返回 `[2, 2]`.

**注意：**

-    输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
-    我们可以不考虑输出结果的顺序。

**跟进:**

- 如果给定的数组已经排好序呢？你将如何优化你的算法？
- 如果 *nums1* 的大小比 *nums2* 小很多，哪种方法更优？
- 如果*nums2*的元素存储在磁盘上，内存是有限的，你不能一次加载所有的元素到内存中，你该怎么办？

## 02 分析

- 扫描两个list，发现相同元素时
  - 该元素插入结果
  - 删除原来list中的元素
- 性能：短的list遍历完成后结束（提前终止）



下面是使用 map 的结果

## 03 题解

### 3.1 C++

```c++
//version 1.0

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> result;
        unordered_map<int, int> m;
        
        // you should init the map
        for(auto n1 : nums1) {
            if(m.count(n1) > 0) m[n1]++;
            else m[n1] = 1;
        }
        
        for(auto n2 : nums2) {
            if(m.count(n2) > 0 && m[n2] > 0) {
                result.push_back(n2);
                m[n2]--;
            }
        }
        
        return result;
    }
};
```



```c++

```



```c++

```



### 3.2 Python 3

```python
# version 1.0

```



```python

```



### 3.3 Java

```java
//version 1.0
```



## 04 总结

网络上好像没有位运算和抽象数据类型的教程