# 实现strStr()  

问题关键词：

- 字符串匹配

## 01 题目

实现 [strStr()](https://baike.baidu.com/item/strstr/811469) 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  **-1**。

**示例 1:**

```
输入: haystack = "hello", needle = "ll"
输出: 2
```

**示例 2:**

```
输入: haystack = "aaaaa", needle = "bba"
输出: -1
```

**说明:**

当 `needle` 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 `needle` 是**空字符串时我们应当返回 0** 。这与C语言的 [strstr()](https://baike.baidu.com/item/strstr/811469) 以及 Java的 [indexOf()](https://docs.oracle.com/javase/7/docs/api/java/lang/String.html#indexOf(java.lang.String)) 定义相符。

## 02 分析

注意pattern串的内部结构性质，对每个str中的起点都要回头看看

## 03 题解

### 基础：穷举匹配（注意游标）

```c++
// version 1.0 17.73%

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int i = 0, j = 0;
        int pattern_len = needle.length();
        int str_len = haystack.length();
        
        if(pattern_len == 0) return 0;
        if(pattern_len > str_len) return -1;
    
        for(i=0; i<str_len; i++){
            j = 0;
            
            while(j<pattern_len){
                if(haystack[i+j] == needle[j]) j++;
                else break;
            }
            
            if(j == pattern_len) return i;
        }
        return -1;
    }
};
```

## 04 总结

