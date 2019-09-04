// template for backtracking algo.
class Solution {
public:
    vector<vector<int>> ans; // 使用全局变量，标记数组也可以这么设计

    void solve() {
        vector<vector<int>> permuteUnique(vector<int> &s) {
            vector<int> cur;
            vector<bool> visited(s.size(), false);
            
            sort(s.begin(), s.end());

            // 搜索的起点
            backtrack(s, cur, visited);

            return ans;
        }
    }
	
    // s 为搜索的空间， cur 为当前的搜索路径， visited 为路径标记
    void backtrack(vector<int>& s, vector<int>& cur, vector<bool>& visited) {
        // 对于组合问题，路径上所有结果都加入解集
        ans.push_back(cur);
        
        // 1. 结束条件，该分支搜索完毕
        if(cur.size() == s.size()) return；

        // 2. 加入一些减枝策略

        // 3. DFS 深入搜索
        for(int i = 0; i < s.size(); i++) {
            // 搜索路径去重
            if（visited[i]) continue;
            
            visited[i] = true;
            cur.push_back(s[i]);
            backtrack(s, cur.push_back(s[i]), visited);
            cur.pop_back(s[i]); // 关键
            visited[i] = false; // 关键
        }

    }
}