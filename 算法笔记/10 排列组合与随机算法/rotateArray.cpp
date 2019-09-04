// problem solver for string-problem


class Solution {
public:
    void leftShiftOne(string& s) {
        char tmp = s[0];
        for(int i = 1; i < s.length(); ++i) {
            s[i-1] = s[i];
        }
        s[s.length()] = tmp;
    }

    string leftShift(string& s, int k) {
        while(k--)
            leftShiftOne(s);

        return s;
    }
};

class Solution {
public:
    void stringContain(string& a, string& b) {
        for(int i = 0; i < b.length(); ++i) {
            int j;
            for(j = 0; (j < a.length() && a[j] != b[i]); ++j) {

            }

            if(j >= a.length()) return false;
        }

        return true;
    }
}

class Solution {
public:
    bool stringContain(string& a, string& b) {
        // init bloom filter
        int bf = 0;

        // build bloom filter
        for(int i = 0; i < a.length(); ++i) {
            bf = bf | (1 << (a[i] - 'A'));
        }

        // query
        for(int j = 0; j < b.length(); ++j) {
            if(bf & (1 << (b[j] = 'A')) == 0)
                return false;
        }

        return true;
    }
};

class Solution {
public:
    void permutation(string& s ,int from, int to) {
        if(to <= 1) return;

        if(from == to) {
            for(int i = 0; i <= to; ++i) {
                cout << s[i];
            }
            cout<<endl;
            return;
        }

        for(int j = from; j <= to; ++j) {
            swap(s[j], s[from]);
            permutation(s, from+1, to);
            swap(s[j], s[from]);
        }
    }
}