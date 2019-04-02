# Fizz Buzz 

> Author：ID.9276

## 01 题目

写一个程序，输出从 1 到 *n* 数字的字符串表示。

\1. 如果 *n* 是3的倍数，输出“Fizz”；

\2. 如果 *n* 是5的倍数，输出“Buzz”；

3.如果 *n* 同时是3和5的倍数，输出 “FizzBuzz”。

**示例：**

```
n = 15,

返回:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
```

## 02 分析

判断逻辑要倒着来

## 03 题解

### 3.1 C++

```c++
// version 1.0 100.00%

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> ans;
        
        for(int i=1; i<=n; i++){
            if(i % 3 == 0 && i % 5 == 0) ans.push_back("FizzBuzz");
            else if(i % 3 == 0) ans.push_back("Fizz");
            else if(i % 5 == 0) ans.push_back("Buzz");
            else ans.push_back(to_string(i));
        }
        
        return ans;
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

