# LCA
> Author ID.9276 

**问题关键词：**

- 

## 01 题目

有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。现在有两个结点a，b。请设计一个算法，求出a和b点的最近公共祖先的编号。

给定两个int **a**,**b**。为给定结点的编号。请返回**a**和**b**的最近公共祖先的编号。注意这里结点本身也可认为是其祖先。

测试样例：

```
2，3
返回：1
```

## 02 分析



## 03 题解

### 基础：序列比较法

- 求出各自的祖先序列，使用栈容器遍历比较其最后的公共祖先

```c++
class LCA {
public:
    int getLCA(int a, int b) {
        // write code here
        if(a == b) return a;

        stack<int> lcaA;
        stack<int> lcaB;

        while(a > 0) {
            lcaA.push(a);
            a = a / 2;
        }

        while(b > 0) {
            lcaB.push(b);
            b = b / 2;
        }

        int ans;
        while(lcaA.top() == lcaB.top()) {
            ans = lcaA.top();
            lcaA.pop();
            lcaB.pop();
        }

        return ans;
    }
};
```

### 优化：不断减小较大元素的值即可（上溯）

> 链接：https://www.nowcoder.com/questionTerminal/70e00e490b454006976c1fdf47f155d9?f=discussion来源：牛客网
>
>   //利用这个关系，如果a ！= b，就让其中的较大数除以2， 如此循环知道a == b， 
>
>   //即是原来两个数的最近公共祖先

```c++
class LCA {
public:
    int getLCA(int a, int b) {
        // write code here
        if(a == b) return a;

        while(a != b) {
            if(a > b) a = a / 2;
            else b = b / 2;
        }

        return a;
    }
};
```



## 04 总结

