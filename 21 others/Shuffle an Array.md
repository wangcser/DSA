# Shuffle an Array 

关键词：

- 随机

## 01 题目

打乱一个**没有重复**元素的数组。

**示例:**

```
// 以数字集合 1, 2 和 3 初始化数组。
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
solution.shuffle();

// 重设数组到它的初始状态[1,2,3]。
solution.reset();

// 随机返回数组[1,2,3]打乱后的结果。
solution.shuffle();
```

## 02 分析



## 03 题解

### 基础 ：向后随机交换法

```c++
// version 1.0 29.40%

class Solution {
public:
    Solution(vector<int> nums) : vec(nums) {

    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return vec;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = vec; // 每次改变原始的拷贝
        for(int i=0; i<res.size(); i++){
            int posi = i + rand() % (res.size() - i); // 向后随机交换位置
            swap(res[i], res[posi]);
        }
        
        return res;
    }
    
private:
    vector<int> vec; // key 类对象中生成后就不变了
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
```

## 04 总结

