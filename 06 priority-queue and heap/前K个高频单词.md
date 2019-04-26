# 前K个高频单词
> Author ID.9276

## 01 题目

给一非空的单词列表，返回前 *k* 个出现次数最多的单词。

返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。

**示例 1：**

```
输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
输出: ["i", "love"]
解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
    注意，按字母顺序 "i" 在 "love" 之前。
```

 

**示例 2：**

```
输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
输出: ["the", "is", "sunny", "day"]
解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
    出现次数依次为 4, 3, 2 和 1 次。
```

 

**注意：**

1. 假定 *k* 总为有效值， 1 ≤ *k* ≤ 集合元素数。
2. 输入的单词均由小写字母组成。

 

**扩展练习：**

1. 尝试以 *O*(*n* log *k*) 时间复杂度和 *O*(*n*) 空间复杂度解决。

## 02 分析

注意容器的使用

## 03 题解

### 3.1 C++

```c++
//version 1.0 0.0%
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        
        // count the freq of each word
        map<string, int> hp;
        for(auto word : words)
            hp[word]++;
        
        // sort with multiset
        multiset<pair<int, string>, intComp> set;
        for(auto it : hp)
            set.insert({it.second, it.first});
        
        // get the first k item
        auto it = set.begin();
        for(int i = 0; i < k; i++) {
            ans.push_back(it->second);
            it++;
        }
        
        return ans;
    }
    struct intComp {
        bool operator() (const pair<int, string>& lhs, const pair<int, string>& rhs) const{
		    return lhs.first > rhs.first;
        }
    };
};
```

### 3.2 Python 3

```python
# version 1.0 0.0%

```

### 3.3 Go

```Go
//version 1.0 0.0%

```



## 04 总结

