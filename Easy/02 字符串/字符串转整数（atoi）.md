# 字符串转整数（atoi） 

> Author：ID.9276

## 01 题目

实现 `atoi`，将字符串转为整数。

在找到第一个非空字符之前，需要移除掉字符串中的空格字符。如果第一个非空字符是正号或负号，选取该符号，并将其与后面尽可能多的连续的数字组合起来，这部分字符即为整数的值。如果第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

字符串可以在形成整数的字符后面包括多余的字符，这些字符可以被忽略，它们对于函数没有影响。

当字符串中的第一个非空字符序列不是个有效的整数；或字符串为空；或字符串仅包含空白字符时，则不进行转换。

若函数不能执行有效的转换，返回 0。

**说明：**

假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。如果数值超过可表示的范围，则返回  INT_MAX (2^31 − 1) 或 INT_MIN (−2^31) 。

**示例 1:**

```
输入: "42"
输出: 42
```

**示例 2:**

```
输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
```

**示例 3:**

```
输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
```

**示例 4:**

```
输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。
```

**示例 5:**

```
输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 
     因此返回 INT_MIN (−231) 。
```

## 02 分析

这个题的难点在于对边界条件的处理，溢出的处理

## 03 题解

### 3.1 C++

```c++
// version 1.0 95.84%

class Solution {
public:
    int myAtoi(string str) {
        
        int i = 0;
        int str_len = str.length();
        bool isNeg = 0;
        string atoi;
        
        if(str_len == 0) return 0; // check the empty case
        
        while(i<str_len){ // remove the space ' '
            if(str[i] == ' ') i++;
            else break;
        }
        
        if(str[i] == '-'){ // check the flag
            isNeg = 1;
            i ++;
        }else if(str[i] == '+') i++;

        while(i<str_len){ // accumulate the num char
            if(isNum(str[i])){
                atoi += str[i];
                i++;
            }else break;    
        }
        
        return str2int(atoi, isNeg);
    }
    
    bool isNum(char ch){ // filter the num
        if('0' <= ch && ch <= '9') return true;
        else return false;
    }
    
    int str2int(string s, bool isNeg){
        
        //cout<<s<<endl;
        
        int val = 0;
        int s_len = s.length();
        int i;
        //int INT_MIN = -2147483648;
        //int INT_MAX = 2147483647;
        
        for(i=0; i<s_len; i++){
            val += pow(10, i) * (s[s_len - 1 - i] - 48);
        }
        
        //cout<<val<<endl;
        
        if(isNeg) val = - val;
        
        if(val <= INT_MIN && isNeg == 1) return INT_MIN;
        else if(val <= INT_MIN && isNeg == 0) return INT_MAX; //specially, for the overflow case, the val will change to INT_MIN case, but the flag stays.
        else if(val >= INT_MAX ) return INT_MAX;
        else return val;
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

