# 复原IP地址
> Author ID.9276 

**问题关键词：**

- 回溯

## 01 题目

给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

**示例:**

```
输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
```

## 02 输入分析



## 03 解题思路

### 3.1 基础思路

- 沿着串向右 dfs 搜索即可，每次搜索按照 subnet 的要求判断即可
- 代码中写的很清晰了



- 本题需要注意的几个细节
  - 搜索停止的条件为 ip 长度为 4
  - 搜索成功的条件为剩余字符串长度为 0
    - 剩余字符串长度这里有一个陷阱，我们在搜索时必须考虑当前 i 与剩余串长的关系
      - 一方面是要防止溢出
      - 另一方面是要保证能够遍历到串尾，因此这里取了 =
        - substr 是左闭右开的，因此 i = s.size() - 1，总会剩下一个元素的子串
    - 考虑到 IP 的特殊结构，我们在构造答案的时候直接一步到位拼接而没有写多余的循环

### 3.2 算法优化



## 04 核心代码

```c++
class Solution {
private:
    vector<string> ipSet;
    vector<string> ip;
    
public:
    vector<string> restoreIpAddresses(string s) {
        
        if(s.size() < 4) return ipSet;
        
        dfs(s);
        
        return ipSet;
    }
    
    void dfs(string s) {
        // 搜索终止条件：栈中含有 4 个子网地址
        if(ip.size() == 4) {
            // 搜索成功：没有剩余内容可供搜索, 当前结果加入 ipSet
            if(s.empty()) {
                string each_ip = ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3];
                ipSet.push_back(each_ip);
            }
            // 搜索失败：s 还有剩余
            
            return;
        }
        
        
        for(int i = 1; i <= 3 && i <= s.size(); i++) {
            // 当前搜索位置
            string cur = s.substr(0, i);
            // 判断当前位置的正确性
            if(cur.size() > 1 && cur[0] == '0' || atoi(cur.c_str()) > 255)
                continue;
            
            // dfs 结构
            ip.push_back(cur);
            // 搜索下一位置
            dfs(s.substr(i));
            ip.pop_back();
        }
    }
};
```



## 05 算法效率分析



## 06 问题总结

