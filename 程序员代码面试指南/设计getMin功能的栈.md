# 设计getMin功能的栈
> Author ID.9276 

**问题关键词：**

- 

## 01 题目


实现一个特殊功能的栈，在实现栈的基本功能的基础上，再实现返回栈中最小元素的操作。

## 输入描述:

```
第一行输入一个整数N，表示对栈进行的操作总数。下面N行每行输入一个字符串S，表示操作的种类。如果S为"push"，则后面还有一个整数X表示向栈里压入整数X。如果S为"pop"，则表示弹出栈顶操作。如果S为"getMin"，则表示询问当前栈中的最小元素是多少。
```

## 输出描述:

```
对于每个getMin操作，输出一行表示当前栈中的最小元素是多少。
```

示例1

## 输入

[复制](javascript:void(0);)

```
6
push 3
push 2
push 1
getMin
pop
getMin
```

## 输出

[复制](javascript:void(0);)

```
1
2
```

## 说明

```

```

## 备注:

```
1<=N<=1000000-1000000<=X<=1000000数据保证没有不合法的操作
```

## 02 分析



## 03 题解

### 基础：同步插入法

```c++
#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class MinStack {
public:
    void push(int num) {
        if(helperStack.empty())
            helperStack.push(num);
        else if(getMin() > num)
            helperStack.push(num);
        else helperStack.push(getMin());

        mainStack.push(num);
    }

    void pop() {
        if (helperStack.empty())
            return;

        mainStack.pop();
        helperStack.pop();
    }

    int getMin() {
        return helperStack.top();
    }

private:
    stack<int> mainStack;
    stack<int> helperStack;
};

int main() {

    int n;
    MinStack minStack;
    string op;

    scanf("%d", &n);

    while (n--) {
        cin >> op;
        if (op == "push") {
            int num;
            scanf("%d", &num);
            minStack.push(num);
        } else if (op == "pop")
            minStack.pop();
        else
            cout << minStack.getMin() << endl;
    }

    return 0;
}
```



### 优化：



## 04 总结

