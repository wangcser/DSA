# 剑指 Offer 学习笔记

> Author：Super Wong
>
> 牛客网：<https://www.nowcoder.com/ta/coding-interviews?page=1>
>
> leetcode：

## 01 面试流程

### 1.1 面试流程

### 1.2 面试形式

### 1.3 面试环节

## 02 面试基础知识

### 2.1 需要掌握的基础知识

### 2.2 编程语言

#### 1. 赋值运算符函数(C++)

#### 2. 实现 Singleton 模式（C#）

### 2.3 数据结构

#### 3. 二维数组中的查找（数组）

- 减治法

[74. 搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix/)

#### 4. 替换空格（字符串）

- **尾插法**

[88. 合并两个有序数组](https://leetcode-cn.com/problems/merge-sorted-array/)

#### 5. 从尾到头打印链表（链表）

- 翻转链表
- 遍历时转换为双向链表
- 借助栈进行缓存
- 递归（借助函数调用栈！）

#### 6. 重建二叉树（树）

> 需要熟练掌握树的 7 种遍历算法
>
> 二叉树 -》二叉搜索树 -》红黑树 -》堆

1. 通过前、后序列找到根节点

2. 通过中序序列找到左右子树
3. 递归

- 分治思想：转化为构建左右子树的问题

[105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

[106. 从中序与后序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

[889. 根据前序和后序遍历构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/)

#### 7 . 用两个栈实现队列（栈与队列）

- 每次输入的元素放入 stack 1，每次输出的元素从 stack 2 中获取
- 从 stack 1 到 stack 2 的搬移能够保证元素之间的顺序，不存在乱序的情况
- 因此，当 stack 2 为空的时候就去 stack 1 中取数据即可

[232. 用栈实现队列](https://leetcode-cn.com/problems/implement-queue-using-stacks/)

- 用队列实现栈的细节在于每次弹出操作需要交换队列哦

[225. 用队列实现栈](https://leetcode-cn.com/problems/implement-stack-using-queues/)

### 2.4 算法和数据操作

考察重点：

- 查找：**二分**，顺序，哈希表，二叉排序树
- 排序：**归并**，**快排**，插入，冒泡

#### 8. 旋转数组的最小数字（二分查找）

- 旋转将原来的单调不减数组划分为两个子数组
- 借助单调性和左右边界比较都可行

- 左侧数组的最小值 >= 右侧数组的最大值
  - 若左侧最小值小于右侧最大值，表明数组天然有序
- 使用二分查找的中值来判断分界点的位置

[153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)

- 引入重复之后，可能会有：left = mid = right 的情况，此时无法判断分界点的位置
- 此时只能采用顺序查找进行补充

[154. 寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/)

#### 9. 斐波那契数列（递归与循环）

递归与迭代的区别类似于分治与动态规划的区别

- 消除重复结构
- 缓存中间结果

[70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)

#### 10. 二进制中 1 的个数（位运算）

注意：

- 位运算
- 进制
- 负数和 0 
- 溢出问题
- 二进制的运算有时会有比较骚的操作

[191. 位1的个数](https://leetcode-cn.com/problems/number-of-1-bits/)

[231. 2的幂](https://leetcode-cn.com/problems/power-of-two/)

- 将一个证书减去 1 后再和原来的整数做按位与运算，得到的结果相当于将该整数二进制表示中最右边的 1 变为 0

[504. 七进制数](https://leetcode-cn.com/problems/base-7/)

## 03 高质量的代码（程序的鲁棒性）

编写的程序应该做到：

- 规范性
  - 书写清晰
  - 布局清晰
  - 命名合理
- 完整性
  - 完成基本功能
  - 考虑边界条件
  - 做好错误处理
- 鲁棒性
  - 编写测试用例
  - 处理无效输入

### 3.1 面试官谈代码质量

- 边界情况
- 输入参数检查
- 初始化
- 错误处理
- 异常处理

### 3.2 代码的规范性(可读 + 清晰的逻辑)

**规范的代码 = 清晰的书写 + 清晰的布局 + 合理的命名**

### 3.3 代码的完整性（测试驱动）

1. **单元测试**：首先将可能的输入考虑清楚，**写单元测试用例**
2. **功能测试**：代码能够完成基本功能（此时要考虑 +，-，0）
3. **边界测试**：考虑循环或者递归的边界条件
4. **错误测试**：程序对于不合理的输入能够进行合理的错误处理

3 种错误处理方法：

- 函数返回值，不方便使用
- 使用全局变量捕捉错误，由**用户主动进行检查**
- **抛出异常**

#### 11. 数值的整数次方（小数的精度）

首先考虑单元测试：

- n > 0, n == 0, n < 0
- x > 0, x == 0, x < 0
- 0 的 0 次方， 输出 0 或者 1 都行
- 极端边界值：2147483647，-2147483648（单独处理）

之后考虑小数的比较：

- 由于计算机表示小数都有误差，因此不能直接用 == 进行判断，只能判断其差的绝对值是否满足需要的精度

最后考虑算法性能优化：

- 使用移位运算代替乘除
- 最后的这个与判断没有看懂哦

[50. Pow(x, n)](https://leetcode-cn.com/problems/powx-n/)

#### 12. 打印 1 到最大的 n 位数（大数问题）

- 对大数的处理 - 串，每个字符占 8 bit
- 串的加法运算
  - 串加法中进位的判断
  - 利用最高位判断终止条件
- 串的输出

另一种处理思路 - 转化为**排列组合问题**

- **可以使用递归来解决**

[415. 字符串相加](https://leetcode-cn.com/problems/add-strings/)

#### 13. 在常数时间删除链表结点（链表删除）

这里给出了需要删除的结点的指针，因此可以采用复制的策略：

- 将其下一个结点复制到当前结点
- 删除下一个结点

边界检查：

- 删除尾结点：没有后继，因此只能从头遍历
- 删除头结点：需要调整头指针
- 链表中只有一个结点：需要调整头指针

注意，这里给出了需要删除结点的指针，因此需要在每次操作完成后将其指向 
NULL

特别的，如果删除结点不在链表中？？？

[237. 删除链表中的节点](https://leetcode-cn.com/problems/delete-node-in-a-linked-list/)

#### 14. 调整数组顺序使奇数位于偶数前面（对撞指针，解耦）

- 可以将判断模块解耦出来

[905. 按奇偶排序数组](https://leetcode-cn.com/problems/sort-array-by-parity/)

[922. 按奇偶排序数组 II](https://leetcode-cn.com/problems/sort-array-by-parity-ii/)

#### 15. 链表中倒数第 k 个结点（快慢指针，链表的边界检查）

- 固定间隔双指针，间隔为 k-1

边界情况：

- 链表头指针为空
- 链表结点数量少于 k
- k = 0，对于无符号整数 0 - 1 = 0xFFFFFFFF = 4294967295

[19. 删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)

[876. 链表的中间结点](https://leetcode-cn.com/problems/middle-of-the-linked-list/)

[141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)

[142. 环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

#### 16. 反转链表（多指针操作，边界检查）

链表常用测试用例：

- head == NULL
- len = 1
- len > 1

注意迭代和递归的不同写法

[206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)

#### 17. 合并两个有序链表（归并操作，递归）

找到子问题和子结构，使用递归操作

[21. 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

#### 18. 树的子结构（树的遍历，树的指针操作，递归）

每当使用指针时，都要想到其是否可能为 NULL

树的判断总是站在 root 的角度进行的

[572. 另一个树的子树](https://leetcode-cn.com/problems/subtree-of-another-te/)

## 04 解决面试题的思路

思路：

- 画图
- 举例
- 分析

### 4.1 面试官谈面试思路

- 在编码之前想清楚思路和并给出必要的证明，不能一开始就编码
- 解释清楚问题和问题的解决方案才是关键

### 4.2 画图让抽象问题形象化

通过画图寻找规律

#### 19. 二叉树镜像（树的遍历）

[101. 对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/)

[226. 翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/)

#### 20. 顺时针打印矩阵（复杂过程分析，矩阵边界条件，循环结束条件）

分析：

1. 按圈打印，抓住对角元
2. 利用对角元坐标判断圈数
3. 打印圈的时候要注意退化情况

退化情况（画图分析）：

1. 一点
2. 一行，两行，多行
3. 一列，两列，多列

[54. 螺旋矩阵](https://leetcode-cn.com/problems/spiral-matrix/)

[59. 螺旋矩阵 II](https://leetcode-cn.com/problems/spiral-matrix-ii/)

[885. 螺旋矩阵 III](https://leetcode-cn.com/problems/spiral-matrix-iii/)

### 4.3 举例让抽象问题具体化

#### 21. 包含 min 函数的栈（辅助栈）

- 每次将当前最小元素压入辅助栈

[155. 最小栈](https://leetcode-cn.com/problems/min-stack/)

#### 22. 栈的压入、弹出序列（辅助栈）

- 这里使用一个辅助栈来帮助思考，注意，只能有一个栈

- 使用两个指针来操作序列，需要注意二者的位置

[946. 验证栈序列](https://leetcode-cn.com/problems/validate-stack-sequences/)

#### 23. 从上往下打印二叉树（层次遍历，辅助队列）

- 注意分层的方法
  - 旗标法
  - 计数法

[102. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

[107. 二叉树的层次遍历 II](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/)

1. 正序层次遍历
2. 外层反转

#### 24. 二叉搜索树的后序遍历序列（树的重构，搜索树的局部性质）

1. 利用后序遍历找出左-右-根
2. 利用局部性质判断即可

#### 25. 二叉树中和为某一值的路径（前序遍历）

- 路径从根节点出发，考虑到只有前序遍历从根出发

[257. 二叉树的所有路径](https://leetcode-cn.com/problems/binary-tree-paths/)

### 4.4 分解让抽象问题简单化

#### 26. 复杂链表的复制（复杂结构分析，分治，时间效率优化）

copy 链表至少需要两个指针哦

[138. 复制带随机指针的链表](https://leetcode-cn.com/problems/copy-list-with-random-pointer/)

两种策略：

1. 用 hashmap 维护 sibling
2. 用同链扩展复制 sibling

#### *27. 二叉搜索树与双向链表（大量指针操作）

1. 搜索树的中序遍历是有序的
2. 将 left 指针转变为 front 指针，将 right 指针转变为 behind 指针
3. 每个根节点的链接方式为：
   1. 向前链接左子树的最右侧节点（最大）
   2. 向后链接右子树的最左侧节点（最小）

按照 inorder，当转换到 root 时，其左子树已经转换为一个链表了，且最后一个节点为最大节点，直接和 root 相连即可，之后遍历right subtree



[108. 将有序数组转换为二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/)

[109. 有序链表转换二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)

[114. 二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)

[430. 扁平化多级双向链表](https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/)

#### 28. 字符串的排列（排列组合，减治分析）

- 组合问题
- 立方体问题
- 8 皇后问题

[438. 找到字符串中所有字母异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/)

[567. 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/)

## 05 优化时间和空间效率

降低时间复杂度的方法：

- 使用更高效的算法：DP
- 用空间换实践：hash table

### 5.1 面试官谈效率

- 分析时间空间复杂度
- 时间换空间
- 空间换时间

### 5.2 时间效率

编码细节：

- 使用引用或指针传递复杂类型参数
- 字符串拼接的空间效率
- 静态申请空间
- 递归中如果子问题有大量 overlapping，使用迭代效果会更好（保存中间结果）

#### 29. 数组中出现次数超过一半的数字

- 这个数字就是排序数组的中位数
- 使用快速排序思路，由分割点的位置判断下一次搜索的方向
  - 找到 index 位于 mid 的时候



- 使用计数策略，对

#### 30. 最小的 k 个数

- 快速排序
  - 找到 index = k 的时候
- 最大堆
  - 利用最大堆维护当前最小的 k 个数

#### 31. 连续子数组的最大和

- 计数法
- 动态规划

[643. 子数组最大平均数 I](https://leetcode-cn.com/problems/maximum-average-subarray-i/)

#### *32. 从 1 到 n 整数中出现的次数

- 穷举法：枚举每个数字的每个位 -》n× log n
- 寻找 含 1 数字的规律，按位分解子问题

[233. 数字1的个数](https://leetcode-cn.com/problems/number-of-digit-one/)

#### 33. 把数组排成最小的数

- 穷举：排列问题 阶乘复杂度
- 找到一个排序规则，对数组进行排序
- 存在大数问题，使用 str 保存数组



- 对自己提出的假设的证明

### 5.3 时间效率和空间效率的平衡

#### 34. 丑数

- 对因子的判断：n % m == 0
- 对整除的判断：除以因子之后没有余数，文章中对整除的定义有歧义，代码使用循环判断只有这三个因子



- 考虑丑数之间的关系，可以缓存已发现的丑数，每一轮乘以 2 3 5，选第一个新的最大值
- 只在丑数上做运算
- 要求丑数数排好序的

[263. 丑数](https://leetcode-cn.com/problems/ugly-number/)

[264. 丑数 II](https://leetcode-cn.com/problems/ugly-number-ii/)

[313. 超级丑数](https://leetcode-cn.com/problems/super-ugly-number/)

#### 35. 第一个只出现一次的字符

- 哈希表：char ->count
- inplace 方案：使用位运算 -》设计电路
  - 异或计数法
- 排序

[136. 只出现一次的数字](https://leetcode-cn.com/problems/single-number/)

[137. 只出现一次的数字 II](https://leetcode-cn.com/problems/single-number-ii/)

[260. 只出现一次的数字 III](https://leetcode-cn.com/problems/single-number-iii/)

[451. 根据字符出现频率排序](https://leetcode-cn.com/problems/sort-characters-by-frequency/)

[316. 去除重复字母](https://leetcode-cn.com/problems/remove-duplicate-letters/)

#### 36. 数组中的逆序对

- 归并排序思想
- 统计逆序对的过程很复杂

#### 37. 两个链表的第一个公共结点

- 从尾部开始比较，使用两个辅助栈
- 如果两个链表长度不相等，就先找出二者的长度，同步其位置后第一次相同的节点就是需要求的节点，这种思路不需要辅助栈

[160. 相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)

**下午继续**

## 06 面试中的各项能力

### 6.1 面试官谈能力

- 礼貌平和，不卑不亢地进行交流
- 逻辑清晰，详略得当地介绍自己和项目
- 针对问题能够发现细节并有效和面试官交流，获取信息
- **对自己的项目了解深入**
- **对面试题能够快速寻找解决方法**

### 6.2 沟通能力和学习能力

沟通能力：

- 对于不清楚的内容，要勇敢承认，不能不懂装懂
- 对于英语面试应该努力提升自己的听说能力

学习能力：

- 关注新的领域，学习新的技术，转换为自己的技能

善于学习，善于提问

- 对于面试过程中比较模糊的问题，要和面试官多进行沟通，努力弄清楚问题的细节

### 6.3 知识迁移能力

#### 38. 数字在排序数组中出现的次数（二分查找）

- 二分查找可以确定有序数组中元素的位置

- 利用二分查找获取数字的起点和终点

#### 39. 二叉树的深度（树的遍历，树的局部性）

注意，不同的遍历算法针对不同的问题有不同的好处

[104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)

[111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)

[111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)

[559. N叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/)

#### 40. 数组中只出现 1 次的数字（位运算）

- 转化为 1 个只出现一次的数字
- 利用首次出现 1 的位区分两个数组
- 学习这种模块化的写法

[260. 只出现一次的数字 III](https://leetcode-cn.com/problems/single-number-iii/)

#### 41. 和为 s 的两个数字 vs 和为 s 的连续正数序列（对撞指针，二分查找）

面试时不要忽略穷举法，如果存在应该先从穷举入手，然后再一步一步优化

- 对撞指针，注意移动的策略，由于数组有序，大了就该右指针，小了就改左指针

[1. 两数之和](https://leetcode-cn.com/problems/two-sum/)

[15. 三数之和](https://leetcode-cn.com/problems/3sum/)

[18. 四数之和](https://leetcode-cn.com/problems/4sum/)

[167. 两数之和 II - 输入有序数组](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/)

[560. 和为K的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/)

[653. 两数之和 IV - 输入 BST](https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/)

[829. 连续整数求和](https://leetcode-cn.com/problems/consecutive-numbers-sum/)

#### 42. 翻转单词顺序 vs 左旋字符串（字符串翻转）

- 局部翻转 + 全局翻转
- 注意字符串问题的边界：
  - 空指针
  - 访问越界

[151. 翻转字符串里的单词](https://leetcode-cn.com/problems/reverse-words-in-a-string/)

[344. 反转字符串](https://leetcode-cn.com/problems/reverse-string/)

[345. 反转字符串中的元音字母](https://leetcode-cn.com/problems/reverse-vowels-of-a-string/)

[541. 反转字符串 II](https://leetcode-cn.com/problems/reverse-string-ii/)

[557. 反转字符串中的单词 III](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)

[796. 旋转字符串](https://leetcode-cn.com/problems/rotate-string/)

### 6.4 抽象建模能力

生活问题-数学建模-编程实现：

- 利用合理的数据结构表达问题
- 分析模型内在规律
- 递归 or 迭代

#### 43. n 个骰子的点数（hash映射）

- 这是一个排列组合问题
- 概率的求法
- 迭代求解的思路：第 n 个骰子的结果与前面的结果有关

#### 44. 扑克牌的顺子（特殊值统计，连续性判断）

[846. 一手顺子](https://leetcode-cn.com/problems/hand-of-straights/)

#### *45. 圆圈中最后剩下的数字（约瑟夫环，数学分析）

- 环形链表模拟删除过程
- 分析删除数字规律直接求解

### 6.5 发散思维能力

面试是一个厚积薄发的过程

#### *46. 求 1 + 2 +  + n（构造函数，虚函数，模版类型）

- 不能使用 for while -》 不能使用迭代
- 不能使用 if -》 不能使用递归（无法判断递归基）

#### 47. 不用加减乘除做加法（位运算）

- 转换为二进制的位运算
  - 第一步两数相加，不进位 异或
  - 第二步两数相加，观察进位情况， 与 + 左移
  - 然后将前面的过程重复即可

#### *48. 不能被继承的类（语言特性）

## 07 两个面试案例

**简历面试**

介绍项目经历的时候可以参照 STAR 模型着重介绍自己完成的工作以及最终对项目组的贡献

- 基于什么平台、用了哪些技术、实现了哪些算法

**技术面试**

考察编程语言，数据结构和算法方面的基础知识

- 对于简单的问题，尽力考虑全面
- 对于复杂的问题，尝试分析其规律

注意考虑算法的优化

注意该轮面试过程中的沟通和学习能力

#### 49. 把字符串转换成整数（负面教材）

**测试驱动**



#### 50. 树中两个结点的最低公共祖先（正面教材）



