#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getNext(vector<int> &next, const string &p) {
    int k = -1, j = 0;

    next[0] = -1;
    while(j < p.length() - 1) { // 这里 j 到不了最后一个的
        if(k == -1 || p[k] == p[j]) {
            k++;
            j++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}

int kmp(const string &s, const string &p) {
    int slen = s.length();
    int plen = p.length();

    if (plen < 1) return -1;
    if (slen < 1 || plen > slen) return -1;

    vector<int> next(plen, 0); // 初始化为 0 就是暴力方法
    getNext(next, p);

    int i = 0, j = 0;

    while (i < slen && j < plen) {
        if (s[i] == p[j]) {
            i++;
            j++;
        } else {
//            i = i - j + 1;
            j = next[j];
        }
    }

    return j == plen ? i - j : -1;
}


int main() {
    string s = "ababcabda";
    string p = "abcab";

    cout << kmp(s, p) << endl;

    return 0;
}