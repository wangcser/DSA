#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void permutation(string& s, int index) {
        if(index == s.length()) {
            cout<<s<<endl;
            return;
        }

        for(int i = index; i < s.length(); i++) {
            swap(s, index, i);
            permutation(s, index+1);
            swap(s, index, i);
        }
    }
    
    void swap(string& s, int i, int j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
};


int main() {
    string s = "abc";
    Solution().permutation(s, 0);
    return 0;
}