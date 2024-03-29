# 两个数组的交集 II 

问题关键词：

- hash map

## 01 题目

给定两个数组，写一个方法来计算它们的交集。

**例如:**
给定 *nums1* = `[1, 2, 2, 1]`, *nums2* = `[2, 2]`, 返回 `[2, 2]`.

**注意：**

-    输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
-    我们可以不考虑输出结果的顺序。

**跟进:**

- 如果给定的数组已经**排好序**呢？你将如何优化你的算法？
- 如果 *nums1* 的大小比 *nums2* 小很多，哪种方法更优？
- 如果*nums2*的元素存储在磁盘上，内存是有限的，你不能一次加载所有的元素到内存中，你该怎么办？

## 02 分析

- 扫描两个list，发现相同元素时
  - 该元素插入结果
  - 删除原来list中的元素
- 性能：短的list遍历完成后结束（提前终止）

## 03 题解

### 基础：使用字典缓存每个元素的次数

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

### 优化：排序

- 如果排好序了，那么各自线性扫描即可
  - 谁小就右移动谁的指针
  - 遇到相同元素就加入解集，然后移动两个指针
  - 任何一个序列结尾就停止遍历

### 优化：大数据

- 问题变为查找磁盘数据中是否有满足题意的元素
  - 因此这时候使用 nums1 建立字典，使用 nums2 查字典即可

## 04 总结

网络上好像没有位运算和抽象数据类型的教程