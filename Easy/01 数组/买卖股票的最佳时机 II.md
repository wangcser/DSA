# 买卖股票的最佳时机 II 

> Author：ID.9276

## 01 题目

给定一个数组，它的第 *i* 个元素是一支给定股票第 *i* 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

**注意：**你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

**示例 1:**

```
输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
```

**示例 2:**

```
输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
```

**示例 3:**

```
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
```

## 02 分析

- BF
  - 遍历vector中所有互斥的顺序对集合
  - 求每个集合的利润
  - 维护最高的利润
- DP
  - 按每个元素是否在最优解中来考虑

## 03 题解

### 3.1 C++

```c++
//version 1.0 BF
// hard to deal with the multi order problems.
// use greedy statege can't rach the global optimise.
// 网络中这类贪心策略很多，认为相邻两天产生利润就卖出？？其实是正确的！！！
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int i, j, k;
        int list_len = prices.size();
        int each_profit;
        int profit = 0;
        
        for(i=0;i<list_len;i++){
            each_profit = 0;
            j = i;
            for(k=j;k<list_len;k++){
                if(prices[j] < prices[k]){
                    each_profit += prices[k] - prices[j];
                    j = k + 1;
                }
            }
            printf("%d", each_profit);
            if(each_profit > profit) profit = each_profit;
        }
        
        return profit;
    }
};
```

```c++
//version 1.1 BF
// 这个思路也不对哦，应该注意到这里直接返回剩余vector的最大值也是一种 greedy
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int i, j, k;
        int list_len = prices.size();
        int each_profit=0;
        int profit = 0;
        
        for(i=0;i<list_len;i++){
            each_profit = 0;
            j = i;
            
            for(k=j;k<list_len;k++){
                
                k = findMax(prices, j, list_len);
                
                if(prices[k] > prices[j]){
                    each_profit += prices[k] - prices[j];
                    j = k;
                }else{
                    break;
                }
            }
            
            printf("%d", each_profit);
            if(each_profit > profit) profit = each_profit;
        }
        return profit;
    }
    
    int findMax(vector<int>& prices, int begin, int end){
        int max_elem_posi = 0;
        
        for(int i=begin;i<end;i++){
            if(prices[i]>prices[max_elem_posi]) max_elem_posi = i;
        }
        return max_elem_posi;
    }
};
```

```c++
// version 2.0 检测波峰特征 60.25%

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int i, j;
        int list_len = prices.size();
        //printf("%d", list_len);
        int profit = 0;
  
        for(i=0,j=i+1;j<list_len; ){
            // 扫描一次序列，每检测到一个顺序序列就用右边界（max）减去左边界（min），积累每个序列的收益
            
            if(prices[i] >= prices[j]){ //逆序对，注意这里将相等的情况也算作逆序处理，否则要单独处理相等的情况
                i++;
                j++;// i，j都指向下一对数组
            }else if(prices[i]<prices[j]){ // 局部出现顺序对
                if(j == list_len-1){ //边界情况，右界为该顺序序列的右边界
                    profit += prices[j] - prices[i];
                    //printf("case B: i is %d, j is %d, profit is %d \n", i,j,profit);
                    break;//提前终止，扫描结束
                }else if(prices[j]>prices[j+1]){//检测到波峰
                    profit += prices[j] - prices[i];
                    //printf("case A: i is %d, j is %d, profit is %d \n", i,j,profit);
                    i = j + 1;
                    j = i + 1;
                }else{//处在顺序序列的上升过程，j后移
                    j++;
                }
                
            }
        }
        
        return profit;
    }
    
};
```

```c++
// version 3.0 Greedy 100%
//相邻两天产生利润就卖出和 2.0 的策略是一致的，区别在于 3.0 的买卖更为频繁，而且假设每一天都可买入+卖出

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int i;
        int list_len = prices.size();
        int profit = 0;
  
        for(i=0;i<list_len-1;i++){
            
            if(prices[i] < prices[i+1]){
                profit += prices[i+1] - prices[i];
            }
        }
        
        return profit;
    }
    
};
```



### 3.2 Python 3

```python
# version 1.0 99.08%
# 沿用 Greedy 策略

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        profit = 0
        for i in range(0, len(prices)-1):
            if(prices[i] < prices[i+1]):
                profit += prices[i+1] - prices[i]
                
        return profit
```

```python
# version 1.1 
# 代码优化， 使用迭代对象实现 （好像不行哦，list本身就希望用户使用下标访问？）

```



### 3.3 Java

```java
//version 1.0
```



## 04 总结

