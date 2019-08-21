#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void combination(string& s, string& ans, int index, int k) {
        if(ans.length() == k) {
            cout<<ans<<endl;
            return;
        }
        
        if(index >= s.length())
            return;
        
        ans.push_back(s[index]);
        combination(s, ans, index+1, k);
        ans.pop_back();
        combination(s, ans, index+1, k);
    }
};


int main() {
    string s = "abcd";
    string ans = "";
    Solution().combination(s, ans, 0, 3);
    return 0;
}