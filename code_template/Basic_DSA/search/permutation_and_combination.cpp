#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void permutation(int i, int len, string &s) {
    if (i == len) {
        cout << s << endl;
        return;
    }

    for (int j = i; j < len; ++j) {
        swap(s[i], s[j]);
        permutation(i + 1, len, s);
        swap(s[i], s[j]);
    }
}

void combination(int i, string &c, int len, string &s) {
    if (i == len) {
        cout << c << endl;
        return;
    }

    c.push_back(s[i]);
    combination(i + 1, c, len, s);
    c.pop_back();
    combination(i + 1, c, len, s);
}

int main() {
    string s = "ABC";

    permutation(0, s.length(), s);

//    string c = "";
//    combination(0, c, s.length(), s);

    return 0;
}